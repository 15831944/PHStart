#include "stdafx.hpp"

#define EACT_CAD_EXPORT_C_PLUS_PLUS
#include "../EActCADExport.hpp"

#include "../EActCAD_old.hpp"
#include "ElectrodeBom_new.hpp"

ElectrodeBom * ElectrodeBom::CreateInstance()
{
	ElectrodeBom *elecBom = new ElectrodeBom();
	return elecBom;
}

ElectrodeBom::ElectrodeBom()
{
	this->InitElecBomConfig();
	this->elecListCtrl = EActListCtrl::CreateInstance();
	this->elecAttrListCtrl = EActListCtrl::CreateInstance();
	this->displayPart = EActPart::CreateInstance(EActPart::GetDisplayPart());
	this->elecPrototypeColl = this->displayPart->GetAllEActElecPrototype();
	this->stringCoder = EActStringCoder::CreateInstance();
	this->elecSubtypeColl = EActElectrode::GetEActElectrodeSubtypeByXml();
}

ElectrodeBom::~ElectrodeBom()
{
	if(NULL != this->elecListCtrl)
	{
		this->elecListCtrl->Destroy();
		this->elecListCtrl = NULL;
	}

	if(NULL != this->elecAttrListCtrl)
	{
		this->elecAttrListCtrl->Destroy();
		this->elecAttrListCtrl = NULL;
	}

	if(NULL != this->displayPart)
	{
		this->displayPart->Destroy();
		this->displayPart = NULL;
	}

	for(map<string, EActElecPrototype *>::iterator it = this->elecPrototypeColl.begin();\
		it != this->elecPrototypeColl.end(); ++it)
	{
		it->second->Destroy();
		it->second = NULL;
	}
	this->elecPrototypeColl.clear();

	if (NULL != this->stringCoder)
	{
		this->stringCoder->Destroy();
		this->stringCoder = NULL;
	}
}

void ElectrodeBom::Destroy()
{
	delete this;
}

//��ȡ�缫BOM�����ļ�
void ElectrodeBom::InitElecBomConfig()
{
	string elecBomConfigPath = EActBase::GetProgramRootDir();
	elecBomConfigPath.append("\\").append(ELECTRODEBOM_PATH);
	file<> elecBomConfigFile(elecBomConfigPath.c_str());
	safety_xml_document<> elecBomConfigDoc;
	elecBomConfigDoc.parse<0>(elecBomConfigFile.data());

	safety_xml_node<> *elecBomNode = elecBomConfigDoc.first_node("ElectrodeBom");

	//��ʼ��������Ϣ����
	safety_xml_node<> *uiInfoNode = elecBomNode->first_node("UIInfo");
	for(safety_xml_node<> *infoNode = uiInfoNode->first_node("Info"); infoNode != NULL;\
		infoNode = infoNode->next_sibling("Info"))
	{
		EActBomData bomDefData;
		bomDefData.displayName = infoNode->first_attribute("DisplayName")->value();
		bomDefData.dataName = infoNode->first_attribute("Value")->value();
		bomDefData.dataType = infoNode->first_attribute("Type")->value();
		this->uiDefDataColl.push_back(bomDefData);
	}

	//��ʼ�����BOM��Ϣ����
	safety_xml_node<> *tableBomNode = elecBomNode->first_node("TableBom");
	for (safety_xml_node<> *tableNode = tableBomNode->first_node("Table"); tableNode != NULL; \
		tableNode = tableNode->next_sibling("Table"))
	{
		TableBomDefineData tableBomDefData;
		tableBomDefData.templateFilePath = EActBase::GetProgramRootDir();
		tableBomDefData.templateFilePath.append("\\").append(tableNode->first_attribute("Template")->value());
		tableBomDefData.buildType = tableNode->first_attribute("BuildType")->value();

		tableBomDefData.BomName = tableNode->first_attribute("BomName")->value();

		safety_xml_node<> *headNode = tableNode->first_node("Head");
		for (safety_xml_node<> *infoNode = headNode->first_node("Info"); infoNode != NULL; \
			infoNode = infoNode->next_sibling("Info"))
		{
			EActBomData bomDefData;
			bomDefData.dataName = infoNode->first_attribute("Value")->value();
			bomDefData.dataType = infoNode->first_attribute("Type")->value();
			bomDefData.rowIndex = EActTemplate::StringToNumber<int>(infoNode->first_attribute("Row")->value());
			bomDefData.columnIndex = EActTemplate::StringToNumber<int>(infoNode->first_attribute("Column")->value());
			tableBomDefData.headDefDataColl.push_back(bomDefData);
		}

		safety_xml_node<> *bodyNode = tableNode->first_node("Body");
		tableBomDefData.startRowIndex= EActTemplate::StringToNumber<int>(bodyNode->first_attribute("StartRow")->value());

		for (safety_xml_node<> *infoNode = bodyNode->first_node("Info"); infoNode != NULL; \
			infoNode = infoNode->next_sibling("Info"))
		{
			EActBomData itemDefData;
			itemDefData.rowIndex = -1;
			itemDefData.columnIndex = EActTemplate::StringToNumber<int>(infoNode->first_attribute("Column")->value());
			itemDefData.dataType = infoNode->first_attribute("Type")->value();
			itemDefData.dataName = infoNode->first_attribute("Value")->value();
			tableBomDefData.bodyDefDataColl.push_back(itemDefData);
		}

		this->tableBomDefDataColl.push_back(tableBomDefData);
	}

	//��ʼ��ϵͳ��Ϣ����
	safety_xml_node<> *systemBomNode = elecBomNode->first_node("SystemBom");
	for (safety_xml_node<> *systemNode = systemBomNode->first_node("System"); systemNode != NULL; \
		systemNode = systemNode->next_sibling("System"))
	{
		string systemName = systemNode->first_attribute("Name")->value();
		if ("EAct" == systemName)
		{
			if (0x0 == strcmp("MSSQL", systemNode->first_attribute("DatabaseType")->value()))
			{
				eActSysDefData.dataBaseType = DataBaseType::SqlType;
			}
			string eActUser = systemNode->first_attribute("User")->value();
			string eActPassword = systemNode->first_attribute("Password")->value();
			string eActConString = systemNode->first_attribute("ConnectionString")->value();
			
			char connString[MAX_PATH] = "";
			sprintf_s(connString, MAX_PATH - 1, "User ID = %s; Password = %s; data source = %s", eActUser.c_str(), eActPassword.c_str(), \
				eActConString.c_str());

			eActSysDefData.conString = connString;

			for (safety_xml_node<> *infoNode = systemNode->first_node("Info"); infoNode != NULL; \
				infoNode = infoNode->next_sibling("Info"))
			{
				EActBomData itemDefData;
				itemDefData.field = infoNode->first_attribute("Name")->value();
				itemDefData.dataType = infoNode->first_attribute("Type")->value();
				itemDefData.dataName = infoNode->first_attribute("Value")->value();
				eActSysDefData.defDataColl.push_back(itemDefData);
			}
		}
		else if ("EMan" == systemName)
		{
			eManSysDefData.baseUrl = systemNode->first_attribute("Api")->value();
			eManSysDefData.corpid = systemNode->first_attribute("Corpid")->value();

			for (safety_xml_node<> *infoNode = systemNode->first_node("Info"); infoNode != NULL; \
				infoNode = infoNode->next_sibling("Info"))
			{
				EActBomData itemDefData;
				itemDefData.field = infoNode->first_attribute("Name")->value();
				itemDefData.dataType = infoNode->first_attribute("Type")->value();
				itemDefData.dataName = infoNode->first_attribute("Value")->value();
				eManSysDefData.defDataColl.push_back(itemDefData);
			}
		}
	}
}

void ElectrodeBom::InitElectrodeBom(const int &dialogID)
{
	this->EActApp_old::InitializeUI(dialogID);
	this->InitElecBomUI();
	this->InitializeUIData();
	this->FillElectrodeList();
	this->ToggleSelectAllElec();
}

void ElectrodeBom::InitElecBomUI()
{
	//��ʼ���缫�б�
	this->elecListCtrl->SetNXHostWindow("�����:", "static", 3);
	this->elecListCtrl->CreateListCtrl(10016,LVS_REPORT|WS_BORDER,LVS_EX_DOUBLEBUFFER|LVS_EX_GRIDLINES|
			LVS_EX_FULLROWSELECT|LVS_EX_SINGLEROW|LVS_EX_CHECKBOXES);
	this->elecListCtrl->SetListUserStyle(TRUE);
	this->elecListCtrl->InsertColumn(0, "���", LVCFMT_CENTER, 60);
	this->elecListCtrl->InsertColumn(1, "�缫����", LVCFMT_CENTER, 200);
	this->elecListCtrl->InsertColumn(2, "ͼ��", LVCFMT_CENTER, 60);
	this->elecListCtrl->AddBitmap(IDB_EACT_ELECTRODE);
	this->elecListCtrl->AddBitmap(IDB_EACT_COMPONENT);
	this->elecListCtrl->UpdataImageList();

	//ע��ص�
	vector<EditInfo> editInfoColl;
	this->elecListCtrl->RegisterEditType(editInfoColl, ElectrodeBom::ElecListCtrlLButtonDown,\
		NULL,NULL,NULL,NULL,NULL,NULL,this);

	//��ʼ����ʾģ��,���ŵȳ�ʼ����Ϣ
	string dieNo = this->displayPart->GetAttrValueByTitleName(EACT_DIE_NO_OF_WORKPIECE);
	this->uiStyler->SetStringControlOfValue(ELEC_BOM_STR_MOLD_NUMBER, dieNo.c_str());

	string workpieceNo = this->displayPart->GetAttrValueByTitleName(EACT_WORKPIECE_NO_OF_WORKPIECE);
	this->uiStyler->SetStringControlOfValue(ELEC_BOM_STR_PIECE_NUMBER, workpieceNo.c_str());

	string designer = this->displayPart->GetAttrValueByTitleName(EACT_DESIGNER); 
	this->uiStyler->SetStringControlOfValue(ELEC_BOM_STR_DESIGNER, designer.c_str());
	 
	string excelBomPath = EActPart::GetWorkPartDir() + "BOM";
	this->uiStyler->SetStringControlOfValue(ELEC_BOM_STR_EXPORT_TABLE_PATH, excelBomPath.c_str());

	//��ʼ�������б�
	this->elecAttrListCtrl->SetNXHostWindow("�����:", "static", 2);
	this->elecAttrListCtrl->CreateListCtrl(10016,LVS_REPORT|WS_BORDER,LVS_EX_DOUBLEBUFFER|LVS_EX_GRIDLINES|
			LVS_EX_FULLROWSELECT|LVS_EX_SINGLEROW);
	this->elecAttrListCtrl->InsertColumn(0,"",LVCFMT_LEFT,100);
	this->elecAttrListCtrl->InsertColumn(1, "�缫��Ϣ", LVCFMT_CENTER, 220);

	for (vector<EActBomData>::iterator it = this->uiDefDataColl.begin(); it != this->uiDefDataColl.end(); ++it)
	{
		int itemCount = this->elecAttrListCtrl->GetItemCount();
		this->elecAttrListCtrl->InsertItem(itemCount, it->displayName.c_str());
		this->elecAttrListCtrl->SetItemBkColor(itemCount, 0, RGB(192, 192, 192));
	}
	return;
}

void ElectrodeBom::InitializeUIData()
{
	vector<DialogItemData_old> dlgMemDataColl = this->ReadDialogMemoryData();
	for (vector<DialogItemData_old>::iterator it = dlgMemDataColl.begin(); it != dlgMemDataColl.end(); ++it)
	{
		if (it->ID == ELEC_BOM_TOGGLE_SELECT_ALL_ELEC)
		{
			int value = EActTemplate::StringToNumber<int>(it->value);
			this->uiStyler->SetToggleButtonOfValue(ELEC_BOM_TOGGLE_SELECT_ALL_ELEC, value);
		}
		else if (it->ID == ELEC_BOM_TOGGLE_BOM_TABLE)
		{
			int value = EActTemplate::StringToNumber<int>(it->value);
			this->uiStyler->SetToggleButtonOfValue(ELEC_BOM_TOGGLE_BOM_TABLE, value);
		}
		else if (it->ID == ELEC_BOM_TOGGLE_UP_SYSTEM_BOM)
		{
			int value = EActTemplate::StringToNumber<int>(it->value);
			this->uiStyler->SetToggleButtonOfValue(ELEC_BOM_TOGGLE_UP_SYSTEM_BOM, value);
		}
		else if (it->ID == ELEC_BOM_TOGGLE_UP_EMAN_SYSTEM_BOM)
		{
			int value = EActTemplate::StringToNumber<int>(it->value);
			this->uiStyler->SetToggleButtonOfValue(ELEC_BOM_TOGGLE_UP_EMAN_SYSTEM_BOM, value);
		}
	}
}

//����UI
void ElectrodeBom::DestroyUI()
{
	vector<DialogItemData_old> dlgMemData;
	DialogItemData_old toggleSelAllData;
	toggleSelAllData.ID = ELEC_BOM_TOGGLE_SELECT_ALL_ELEC;
	int toggleSelAll = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_SELECT_ALL_ELEC);
	toggleSelAllData.value = EActTemplate::GetString(toggleSelAll);
	dlgMemData.push_back(toggleSelAllData);

	DialogItemData_old toggleTableData;
	toggleTableData.ID = ELEC_BOM_TOGGLE_BOM_TABLE;
	int toggleTable = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_BOM_TABLE);
	toggleTableData.value = EActTemplate::GetString(toggleTable);
	dlgMemData.push_back(toggleTableData);

	DialogItemData_old toggleSystemData;
	toggleSystemData.ID = ELEC_BOM_TOGGLE_UP_SYSTEM_BOM;
	int toggleSystem = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_UP_SYSTEM_BOM);
	toggleSystemData.value = EActTemplate::GetString(toggleSystem);
	dlgMemData.push_back(toggleSystemData);

	DialogItemData_old toggleEManSystemData;
	toggleEManSystemData.ID = ELEC_BOM_TOGGLE_UP_EMAN_SYSTEM_BOM;
	int toggleEManSystem = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_UP_EMAN_SYSTEM_BOM);
	toggleEManSystemData.value = EActTemplate::GetString(toggleEManSystem);
	dlgMemData.push_back(toggleEManSystemData);

	this->WriteDialogMemoryData(dlgMemData);
}

void ElectrodeBom::ElecListCtrlLButtonDown(void *UserData)
{
	ElectrodeBom *elecBom = (ElectrodeBom *)UserData;
	elecBom->UpdataElecAttrList();
}

void ElectrodeBom::UpdataElecAttrList()
{
	int item = this->elecListCtrl->GetSelectionMark();
	if (-1 == item)
		return;

	string elecName = this->elecListCtrl->GetItemText(item,1);
	int infoCount = 0;
	for (vector<EActBomData>::iterator it = this->uiDataColl[elecName].begin(); 
		it != this->uiDataColl[elecName].end(); ++it, ++infoCount)
	{
		this->elecAttrListCtrl->SetItemText(infoCount,1, it->dataValue.c_str());
	}

	int elecCount = 0;
	for(map<string, EActElecPrototype *>::iterator it = this->elecPrototypeColl.begin();\
		it != this->elecPrototypeColl.end(); ++it, ++elecCount)
	{
		it->second->SetHighlight(elecName == it->first ? true : false);
	}
}

void ElectrodeBom::ToggleSelectAllElec()
{
	int toggleSelectAllElec = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_SELECT_ALL_ELEC);
	for (int i = 0; i< this->elecListCtrl->GetItemCount(); i++)
	{
		this->elecListCtrl->SetCheck(i, toggleSelectAllElec);
	}
}

//ѡ�񵼳����·���ص�
void ElectrodeBom::SelectExportTablePath()
{
	string exportTablePath = this->uiStyler->GetStringControlOfValue(ELEC_BOM_STR_EXPORT_TABLE_PATH);
	exportTablePath = EActUIStyler::SelectDirectory("��ѡ�������Ŀ¼", exportTablePath.c_str());
	this->uiStyler->SetStringControlOfValue(ELEC_BOM_STR_EXPORT_TABLE_PATH, exportTablePath.c_str());
}

//�򿪵�ǰ���Ŀ¼�ص�
void ElectrodeBom::OpenCurWorkTablePath()
{
	string strExportTablePath = this->uiStyler->GetStringControlOfValue(ELEC_BOM_STR_EXPORT_TABLE_PATH);
	if (access(strExportTablePath.c_str(), 0) == 0)
	{
		EActWinBase::CreateDirectoryTree(strExportTablePath.c_str());
	}

	ShellExecute(NULL, NULL, strExportTablePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void ElectrodeBom::WriteExcelBom(const vector<string> &elecNameColl)
{
	string fileDir = this->uiStyler->GetStringControlOfValue(ELEC_BOM_STR_EXPORT_TABLE_PATH);
	if ('\\' != fileDir.back())
	{
		fileDir += "\\";
	}

	vector<TableBomDefineData>::iterator iIt = this->tableBomDefDataColl.begin();
	if (!PathFileExistsA(iIt->templateFilePath.c_str()))
	{
		throw EActException("ģ���ļ�������:" + iIt->templateFilePath);
	}

	//��ȡ��׺��
	char fileExt[_MAX_EXT] = "";
	_splitpath(iIt->templateFilePath.c_str(), NULL, NULL, NULL, fileExt);

	string filePath = fileDir;
	string bomName = EActPart::GetWorkPartName();
	if (!iIt->BomName.empty())  //������BOM�ļ���
	{
		EActElecPrototype *elecPrototype = this->elecPrototypeColl[elecNameColl.at(0)];
		stringCoder->SetAssoObject(elecPrototype->GetObjectTag());
		bomName = stringCoder->CalcCoderStr(iIt->BomName);
	}
	filePath.append(bomName).append(fileExt);

	this->repeatOption = -1;
	for (; iIt != this->tableBomDefDataColl.end(); ++iIt)
	{

		bool isSkip = false;
		if (PathFileExistsA(filePath.c_str()))
		{
			if (-1 == this->repeatOption)
			{
				string infoMsg = filePath + "�Ѵ���,��ѡ���������?";
				this->repeatOption = EActUIStyler::ShowMessageBox(infoMsg.c_str(), "����", "������ˮ��", "����");
			}

			switch (this->repeatOption)
			{
				case 1:
					{
						DeleteFileA(filePath.c_str());
					}
						break;
				case 2:
					{
						  string tempFilePath = fileDir + bomName;
						  for (int i = 1; true; i++)
						  {
							  filePath = tempFilePath + "_" + EActTemplate::GetString(i) + fileExt;
							  if (!PathFileExistsA(filePath.c_str()))
							  {
								  break;
							  }
						  }
					}
						break;
				case 3:
					{
						isSkip = true;
					}
					break;
			}
		}
		else
		{
			EActWinBase::CreateDirectoryTree(fileDir.c_str());
		}

		if (isSkip)
		{
			continue;
		}

		if (!CopyFileA(iIt->templateFilePath.c_str(), filePath.c_str(), TRUE))
		{
			throw EActException("��������Excel�ļ�ʧ��:" + filePath);
		}

		EActBase::PrinLogInfo("����Excel��" + filePath + "�ɹ�");
		
		EActBase::PrinLogInfo("���ڼ���Excel BOM���ݼ�......");
		UF_UI_set_status("���ڼ���Excel BOM���ݼ�......");

		//��ȡͷ������
		vector<EActBomData> headDataColl = this->GetPartData(iIt->headDefDataColl);

		//��ȡ���岿������
		vector<vector<EActBomData>> bodyDataColl;
		if ("�缫ԭ��" == iIt->buildType)
		{
			bodyDataColl = this->GetElecDataByElecPrototype(iIt->bodyDefDataColl, elecNameColl);
		}
		else if ("�缫������" == iIt->buildType)
		{
			bodyDataColl = this->GetElecDataByContainType(iIt->bodyDefDataColl, elecNameColl);
		}
		else if ("�缫��β��" == iIt->buildType)
		{
			bodyDataColl = this->GetElecDataByContainTail(iIt->bodyDefDataColl, elecNameColl);
		}

		EActBase::PrinLogInfo("��������Excel BOM��......");
		UF_UI_set_status("��������Excel BOM��......");
		
		Book* book = NULL;
		if (_stricmp(".xls", fileExt) == 0)
			book = xlCreateBook();
		else if (_stricmp(".xlsx", fileExt) == 0)
			book = xlCreateXMLBook();

		if (book == NULL)
			throw exception("����xls������ʧ�ܡ�");

		book->setKey(XL_USER_NAME, XL_USER_KEY);
		if (!book->load(filePath.c_str()))
			throw exception(filePath.append("���ļ���ʧ�ܡ�").c_str());

		Sheet* sheet = book->getSheet(0);

		//ͷ��д��
		for (vector<EActBomData>::iterator jIt = headDataColl.begin(); jIt != headDataColl.end(); ++jIt)
		{
			sheet->writeStr(jIt->rowIndex - 1, jIt->columnIndex - 1, jIt->dataValue.c_str());
		}

		//���岿��д��
		int currentRowIndex = iIt->startRowIndex;
		for (vector<vector<EActBomData>>::iterator jIt = bodyDataColl.begin(); jIt != bodyDataColl.end(); ++jIt, ++currentRowIndex)
		{
			for (vector<EActBomData>::iterator kIt = jIt->begin(); kIt != jIt->end(); ++kIt)
			{
				if (EActTemplate::StringIsNumber(kIt->dataValue))
				{
					double dataValue = EActTemplate::StringToNumber<double>(kIt->dataValue);
					sheet->writeNum(currentRowIndex - 1, kIt->columnIndex - 1, dataValue);
				}
				else
				{
					sheet->writeStr(currentRowIndex - 1, kIt->columnIndex - 1, kIt->dataValue.c_str());
				}
			}
		}

		if (!book->save(filePath.c_str()))
			throw exception(filePath.append("���ļ�����ʧ�ܡ�").c_str());

		book->release();
		book = NULL;

		EActBase::PrinLogInfo("����Excel BOM�����");

		UF_UI_set_status("����Excel BOM�����");
	}
}

vector<EActBomData> ElectrodeBom::GetPartData(const vector<EActBomData> &bomDefDataColl)
{
	vector<EActBomData> bomDataColl;

	for (int i = 0; i < bomDefDataColl.size(); i++)
	{
		EActBomData bomData = bomDefDataColl.at(i);

		if ("Attr" == bomData.dataType)
		{
			bomData.dataValue = this->displayPart->GetAttrValueByAttrName(bomData.dataName.c_str());
		}
		else if ("StringCoder" == bomData.dataType)
		{
			stringCoder->SetAssoObject(this->displayPart->GetObjectTag());
			bomData.dataValue = stringCoder->CalcCoderStr(bomData.dataName);
		}

		bomDataColl.push_back(bomData);
	}

	return bomDataColl;
}

vector<vector<EActBomData>> ElectrodeBom::GetElecDataByElecPrototype(const vector<EActBomData> &bomDefDataColl, \
	const vector<string> &elecNameColl)
{
	vector<vector<EActBomData>> bomDataColl;

	vector<pair<string, string>> elecSubtypeColl = EActElectrode::GetEActElectrodeSubtypeByXml();

	int rowCount = 1;
	for (int i = 0; i < elecNameColl.size(); i++, rowCount++)
	{
		EActElecPrototype *elecPrototype = this->elecPrototypeColl[elecNameColl.at(i)];
		vector<EActBomData> bomDataItemColl;

		for (int k = 0; k < bomDefDataColl.size(); k++)
		{
			EActBomData bomData = bomDefDataColl.at(k);

			if ("Calc" == bomData.dataType)
			{
				if ("��ˮ��" == bomData.dataName)
				{
					bomData.dataValue = EActTemplate::GetString(rowCount);
				}
				else
				{
					bomData = this->GetStandardData(elecPrototype, bomData);
				}
			}
			else
			{
				bomData = this->GetStandardData(elecPrototype, bomData);
			}

			bomDataItemColl.push_back(bomData);
		}

		bomDataColl.push_back(bomDataItemColl);

	}

	return bomDataColl;
}

vector<vector<EActBomData>> ElectrodeBom::GetElecDataByContainType(const vector<EActBomData> &bomDefDataColl,\
	const vector<string> &elecNameColl)
{
	vector<vector<EActBomData>> bomDataColl;

	int rowCount = 1;
	for (int i = 0; i < elecNameColl.size(); i++)
	{
		for (vector<pair<string, string>>::iterator iIt = this->elecSubtypeColl.begin(); iIt != this->elecSubtypeColl.end(); \
			++iIt)
		{
			EActElecPrototype *elecPrototype = this->elecPrototypeColl[elecNameColl.at(i)];

			string numberAttrTitle = iIt->first + EACT_SUBTYPE_NUMBER;//�ֹ�,�й�,���� ����
			string numberAttrValue = elecPrototype->GetAttrValueByAttrName(numberAttrTitle.c_str());
			int numberValue = EActTemplate::StringToNumber<int>(numberAttrValue);
			if (numberValue < 1)
				continue;

			vector<EActBomData> bomDataItemColl;

			for (int k = 0; k < bomDefDataColl.size(); k++, rowCount++)
			{
				EActBomData bomData = bomDefDataColl.at(k);

				if ("Calc" == bomData.dataType)
				{
					if ("��ˮ��" == bomData.dataName)
					{
						bomData.dataValue = EActTemplate::GetString(rowCount);
					}
					else if ("�缫���ƺ�����" == bomData.dataName)
					{
						bomData.dataValue = elecNameColl.at(i) + "-" + iIt->second;
					}
					else
					{
						bomData = this->GetStandardData(elecPrototype, bomData);
					}
				}
				else
				{
					bomData = this->GetStandardData(elecPrototype, bomData);
				}

				bomDataItemColl.push_back(bomData);
			}

			bomDataColl.push_back(bomDataItemColl);
		}
	}

	return bomDataColl;
}

vector<vector<EActBomData>> ElectrodeBom::GetElecDataByContainTail(const vector<EActBomData> &bomDefDataColl, \
	const vector<string> &elecNameColl)
{
	vector<vector<EActBomData>> bomDataColl;

	int rowCount = 1;
	for (int i = 0; i < elecNameColl.size(); i++)
	{
		for (vector<pair<string, string>>::iterator iIt = this->elecSubtypeColl.begin(); iIt != this->elecSubtypeColl.end(); \
			++iIt)
		{
			EActElecPrototype *elecPrototype = this->elecPrototypeColl[elecNameColl.at(i)];

			string numberAttrTitle = iIt->first + string(EACT_SUBTYPE_NUMBER);//�ֹ�,�й�,���� ����
			string numberAttrValue = elecPrototype->GetAttrValueByAttrName(numberAttrTitle.c_str());
			if (!EActTemplate::StringIsNumber(numberAttrValue))
			{
				continue;
			}

			int numberValue = EActTemplate::StringToNumber<int>(numberAttrValue);
			if (numberValue < 1)
			{
				continue;
			}

			for (int j = 1; j <= numberValue; j++, ++rowCount)
			{
				vector<EActBomData> bomDataItemColl;

				for (int k = 0; k < bomDefDataColl.size(); k++)
				{
					EActBomData bomData = bomDefDataColl.at(k);
					EActStringCoder::Replace(bomData.dataName, "Mark", iIt->first);

					if ("Calc" == bomData.dataType)
					{
						if ("��ˮ��" == bomData.dataName)
						{
							bomData.dataValue = EActTemplate::GetString(rowCount);
						}
						else if ("�缫���ƺ�����" == bomData.dataName)
						{
							bomData.dataValue = elecNameColl.at(i) + "-" + iIt->second;
						}
						else if ("�缫���ƺ�β��" == bomData.dataName)
						{
							bomData.dataValue = elecNameColl.at(i) + "-" + iIt->second + EActTemplate::GetString(j);
						}
						else if ("�ֹ�����" == bomData.dataName)
						{
							bomData.dataValue = "1";
						}
						else if ("�й�����" == bomData.dataName)
						{
							bomData.dataValue = "2";
						}
						else if ("��������" == bomData.dataName)
						{
							bomData.dataValue = "3";
						}
						else
						{
							bomData = this->GetStandardData(elecPrototype, bomData);
						}
					}
					else
					{
						bomData = this->GetStandardData(elecPrototype, bomData);
					}

					bomDataItemColl.push_back(bomData);
				}

				bomDataColl.push_back(bomDataItemColl);
			}
		}
	}

	return bomDataColl;
}

EActBomData ElectrodeBom::GetStandardData(EActElecPrototype *elecPrototype, const EActBomData &bomDefData)
{
	EActBomData bomData = bomDefData;
	
	if ("Calc" == bomData.dataType)
	{
		if ("�缫ʵ�ʳߴ�" == bomData.dataName)
		{
			vector<double> size = elecPrototype->GetFirstElec().second->GetSize();
			bomData.dataValue = EActStringCoder::Format("%.2f*%.2f*%.2f", size[0], size[1], size[2]);
		}
		else if ("X��λֵ" == bomData.dataName)
		{
			map<int, EActElectrode *> elecColl = elecPrototype->GetElecCollector();
			for (map<int, EActElectrode *>::iterator it = elecColl.begin(); it != elecColl.end(); ++it)
			{
				if ("" != bomData.dataValue)
				{
					bomData.dataValue += ",";
				}

				bomData.dataValue += EActTemplate::GetString(it->second->GetEDMRunPos().X, 3);
			}
		}
		else if ("Y��λֵ" == bomData.dataName)
		{
			map<int, EActElectrode *> elecColl = elecPrototype->GetElecCollector();
			for (map<int, EActElectrode *>::iterator it = elecColl.begin(); it != elecColl.end(); ++it)
			{
				if ("" != bomData.dataValue)
				{
					bomData.dataValue += ",";
				}

				bomData.dataValue += EActTemplate::GetString(it->second->GetEDMRunPos().Y, 3);
			}
		}
		else if ("Z��λֵ" == bomData.dataName)
		{
			map<int, EActElectrode *> elecColl = elecPrototype->GetElecCollector();
			for (map<int, EActElectrode *>::iterator it = elecColl.begin(); it != elecColl.end(); ++it)
			{
				if ("" != bomData.dataValue)
				{
					bomData.dataValue += ",";
				}

				bomData.dataValue += EActTemplate::GetString(it->second->GetEDMRunPos().Z, 3);
			}
		}
		else if ("C����ת�Ƕ�" == bomData.dataName)
		{
			map<int, EActElectrode *> elecColl = elecPrototype->GetElecCollector();
			for (map<int, EActElectrode *>::iterator it = elecColl.begin(); it != elecColl.end(); ++it)
			{
				if ("" != bomData.dataValue)
				{
					bomData.dataValue += ",";
				}

				bomData.dataValue += EActTemplate::GetString(it->second->GetCAxisAngle(), 3);
			}
		}
	}
	else if ("Attr" == bomData.dataType)
	{
		bomData.dataValue = elecPrototype->GetAttrValueByAttrName(bomData.dataName.c_str());
	}
	else if ("StringCoder" == bomData.dataType)
	{
		stringCoder->SetAssoObject(elecPrototype->GetObjectTag());
		bomData.dataValue = stringCoder->CalcCoderStr(bomData.dataName);
	}

	return bomData;
}

void ElectrodeBom::UploadSystemBom(const vector<string> &elecNameColl)
{
	EActBase::PrinLogInfo("�����ϴ�ϵͳBOM");
	UF_UI_set_status("�����ϴ�ϵͳBOM");

	vector<vector<EActBomData>> bomDataColl = this->GetElecDataByContainTail(this->eActSysDefData.defDataColl, elecNameColl);

	vector<EActSystemData> eActSystemDataColl;
	for (vector<vector<EActBomData>>::iterator iIt = bomDataColl.begin(); iIt != bomDataColl.end(); ++iIt)
	{
		EActSystemData systemData;
		systemData.mouldSN = this->displayPart->GetAttrValueByTitleName(EACT_DIE_NO_OF_WORKPIECE);
		EActBase::PrinLogInfo("ģ��:" + systemData.mouldSN);

		systemData.workpieceSN = this->displayPart->GetAttrValueByTitleName(EACT_WORKPIECE_NO_OF_WORKPIECE);
		EActBase::PrinLogInfo("����:" + systemData.workpieceSN);

		systemData.desginer = this->displayPart->GetAttrValueByTitleName(EACT_DESIGNER);
		EActBase::PrinLogInfo("�����:" + systemData.desginer);

		for (vector<EActBomData>::iterator jIt = iIt->begin(); jIt != iIt->end(); ++jIt)
		{
			EActBase::PrinLogInfo(jIt->dataName + "[" + jIt->field + "]:" + jIt->dataValue);

			if ("PARTFILENAME" == jIt->field)
			{
				systemData.partFileName = jIt->dataValue;
			}
			else if ("CUPRUMSN" == jIt->field)
			{
				systemData.elecSN = jIt->dataValue;
			}
			else if ("STRUFF" == jIt->field)
			{
				systemData.material = jIt->dataValue;
			}
			else if ("CHUCK" == jIt->field)
			{
				systemData.clampType = jIt->dataValue;
			}
			else if ("MATERIALSPEC" == jIt->field)//�Զ���Ĳ��Ϲ��,������EAct���ݿ�
			{
				systemData.spec = jIt->dataValue;
				continue;
			}
			else if ("X" == jIt->field)
			{
				systemData.x = jIt->dataValue;
			}
			else if ("Y" == jIt->field)
			{
				systemData.y = jIt->dataValue;
			}
			else if ("Z" == jIt->field)
			{
				systemData.z = jIt->dataValue;
			}
			else if ("C" == jIt->field)
			{
				systemData.c = jIt->dataValue;
			}

			systemData.elecInfo.push_back(pair<string, string>(jIt->field, jIt->dataValue));
		}

		EActBase::PrinLogInfo("End");

		eActSystemDataColl.push_back(systemData);
	}

	EActSystemClr *eActSystemClr = EActSystemClr::CreateInstance();
	eActSystemClr->SetDataBaseType(this->eActSysDefData.dataBaseType);
	eActSystemClr->SetConnString(this->eActSysDefData.conString);
	eActSystemClr->UploadBom(eActSystemDataColl);
	eActSystemClr->Destroy();

	EActBase::PrinLogInfo("�ϴ�ϵͳBOM����");
	UF_UI_set_status("�ϴ�ϵͳBOM����");
}

void ElectrodeBom::UploadEManSystemBom(const vector<string> &elecNameColl)
{
//#ifndef EACT_DEBUG
//	EActBase::PrinLogInfo("�����ϴ�EManϵͳBOM");
//	UF_UI_set_status("�����ϴ�EManϵͳBOM");
//
//	EManSystemClr *eManSystem = EManSystemClr::CreateInstance();
//	string apiUrl = eManSysDefData.baseUrl + this->displayPart->GetAttrValueByTitleName(EACT_DIE_NO_OF_WORKPIECE);
//	eManSystem->UploadBomByAPI(apiUrl);
//	eManSystem->Destroy();
//
//	EActBase::PrinLogInfo("�ϴ�EManϵͳBOM���");
//	UF_UI_set_status("�ϴ�EManϵͳBOM���");
//#else

	EActBase::PrinLogInfo("�����ϴ�EManϵͳBOM");
	UF_UI_set_status("�����ϴ�EManϵͳBOM");

	vector<vector<EActBomData>> bomDataColl = this->GetElecDataByContainTail(this->eManSysDefData.defDataColl, elecNameColl);

	vector<EManSystemData> eManSystemDataColl;
	for (vector<vector<EActBomData>>::iterator iIt = bomDataColl.begin(); iIt != bomDataColl.end(); ++iIt)
	{
		EManSystemData systemData;
		systemData.mouldBasenum = this->displayPart->GetAttrValueByTitleName(EACT_DIE_NO_OF_WORKPIECE);
		EActBase::PrinLogInfo("ģ��:" + systemData.mouldBasenum);

		systemData.steelPartsName = this->displayPart->GetAttrValueByTitleName(EACT_WORKPIECE_NO_OF_WORKPIECE);
		EActBase::PrinLogInfo("����:" + systemData.steelPartsName);

		for (vector<EActBomData>::iterator jIt = iIt->begin(); jIt != iIt->end(); ++jIt)
		{
			EActBase::PrinLogInfo(jIt->dataName + "[" + jIt->field + "]:" + jIt->dataValue);
			if ("norms" == jIt->field)
			{
				systemData.norms = jIt->dataValue;
			}
			else if ("number" == jIt->field)
			{
				systemData.number = atoi(jIt->dataValue.c_str());
			}
			else if ("partnums" == jIt->field)
			{
				systemData.partnums = jIt->dataValue;
			}
			else if ("materialtexture" == jIt->field)
			{
				systemData.materialtexture = jIt->dataValue;
				for (vector<EActBomData>::iterator kIt = iIt->begin(); kIt != iIt->end(); ++kIt)
				{
					if ("piecename" == kIt->field)
					{
						systemData.piecename = systemData.materialtexture + "�缫";
					}
				}
			}

			systemData.elecInfo.push_back(pair<string, string>(jIt->field, jIt->dataValue));
		}

		EActBase::PrinLogInfo("End");

		eManSystemDataColl.push_back(systemData);
	}

	EManSystemClr *eManSystemClr = EManSystemClr::CreateInstance();
	eManSystemClr->SetApiInfo(this->eManSysDefData.baseUrl, this->eManSysDefData.corpid);
	eManSystemClr->UploadBom(eManSystemDataColl);
	eManSystemClr->Destroy();

	EActBase::PrinLogInfo("�ϴ�EManϵͳBOM����");
	UF_UI_set_status("�ϴ�EManϵͳBOM����");


//#endif
}

bool ElectrodeBom::ApplyElecBom()
{
	try
	{
		bool isExportBomTable = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_BOM_TABLE);
		bool isUploadSystemBom = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_UP_SYSTEM_BOM);
		bool isUploadEManSystemBom = this->uiStyler->GetToggleButtonOfValue(ELEC_BOM_TOGGLE_UP_EMAN_SYSTEM_BOM);

		if (!isExportBomTable && !isUploadSystemBom && !isUploadEManSystemBom)
		{
			uc1601("δѡ���κβ�������", 1);
			return FALSE;
		}

		vector<string> elecNameColl;
		for (int i = 0; i < this->elecListCtrl->GetItemCount(); i++)
		{
			if (this->elecListCtrl->GetCheck(i))
			{
				string elecName = this->elecListCtrl->GetItemText(i, 1).GetBuffer();

				this->elecPrototypeColl[elecName]->SetAllElecCS(EActElectrodeCS::OwningCS);
				this->elecPrototypeColl[elecName]->InitAllElecFeat();
				this->elecPrototypeColl[elecName]->SortElecCollector();

				elecNameColl.push_back(elecName);
			}
		}

		if (elecNameColl.empty())
		{
			uc1601("δѡ���κε缫", 1);
			return FALSE;
		}

		if (isExportBomTable)
		{
			this->WriteExcelBom(elecNameColl);
			uc1601("����BOM�����ɳɹ�", 1);
		}

		if (isUploadSystemBom)
		{
			this->UploadSystemBom(elecNameColl);
			//uc1601("�ϴ�EActϵͳBOM�ɹ�", 1);
		}

		if (isUploadEManSystemBom)
		{
			this->UploadEManSystemBom(elecNameColl);
			//uc1601("�ϴ�EManϵͳBOM����", 1);
		}

		return TRUE;
	}
	catch (exception& ex)
	{
		uc1601((char *)ex.what(), 1);
		EActBase::PrinLogInfo(ex.what());
		return FALSE;
	}
}

//���缫�б�
void ElectrodeBom::FillElectrodeList()
{
	vector<string> elecNameColl;
	for (map<string, EActElecPrototype *>::iterator it = this->elecPrototypeColl.begin(); \
		it != this->elecPrototypeColl.end(); it++)
	{
		int count = this->elecListCtrl->GetItemCount();
		int nItem = this->elecListCtrl->InsertItem(count, "", it->second->IsOccurrence() ? 1 : 0);
		this->elecListCtrl->SetItemText(nItem, 0, EActTemplate::GetString(nItem + 1).c_str());
		this->elecListCtrl->SetItemText(nItem, 1, it->first.c_str());
		this->elecListCtrl->SetItemText(nItem, 2, EActTemplate::GetString(it->second->GetLayer()).c_str());

		elecNameColl.push_back(it->first);
	}

	vector<vector<EActBomData>> uiDataColl = this->GetElecDataByElecPrototype(this->uiDefDataColl, elecNameColl);
	for (int i = 0; i < elecNameColl.size(); i++)
	{
		this->uiDataColl.insert(pair<string, vector<EActBomData>>(elecNameColl.at(i), uiDataColl.at(i)));
	}

	//���õ�һ�е缫Ϊѡ��
	if (!this->elecPrototypeColl.empty())
	{
		this->elecListCtrl->SetFocus(); //ѡ��Ϊ����;
		this->elecListCtrl->SetItemState(0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		ElectrodeBom::ElecListCtrlLButtonDown(this);
	}
}
