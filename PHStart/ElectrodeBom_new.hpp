#ifndef ELECTRODEBOM_HPP
#define ELECTRODEBOM_HPP

class EActCAD_old;

//Bom����
struct EActBomData
{
	//��������
	string dataType;

	//���ݵ�����
	string dataName;

	//���ݵ���ʾ����
	string displayName;

	//���ݵ�ֵ
	string dataValue;

	//������------Eacelʱ��Ч
	int rowIndex;

	//������------Eacelʱ��Ч
	int columnIndex;

	//���ݿ��ֶ�------System����ʱ��Ч
	string field;

	//���캯��
	EActBomData()
	{
		this->dataType = "";
		this->dataName = "";
		this->displayName = "";
		this->dataValue = "";
		this->rowIndex = -1;
		this->columnIndex = -1;
		this->field = "";
	}
};

//Table Bom��������
struct TableBomDefineData
{
	//ģ���ļ�·��
	string templateFilePath;

	//ģ���ļ�·��
	string BomName;

	//��������
	string buildType;

	//ͷ�����������ռ���
	vector<EActBomData> headDefDataColl;

	//���岿����ʼ��
	int startRowIndex;

	//���岿�ֶ��������ռ���
	vector<EActBomData> bodyDefDataColl;
};

//EActSystem��������
struct EActSystemDefineData
{
	//EActϵͳ���ݿ�������Ϣ
	DataBaseType dataBaseType;

	//EActϵͳ���ݿ������ַ���
	string conString;

	//���������ռ���
	vector<EActBomData> defDataColl;
};

//EManϵͳ��������
struct EManSystemDefineData
{
	//EManϵͳAPI����ַ
	string baseUrl;

	//��ҵ����
	string corpid;

	//���������ռ���
	vector<EActBomData> defDataColl;
};

//�缫BOM��
class EACT_CAD_C_PLUS_PLUS ElectrodeBom : public EActCAD_old
{
public:
	//�����缫BOMʵ��
	static ElectrodeBom * CreateInstance();

	//���ٶ���
	void Destroy();

	//��ʼ���û�����
	void InitElecBomConfig();

	//��ʼ���缫BOM
	void InitElectrodeBom(const int &dialogID);

	//��ʼ��BOM�б�
	void InitElecBomUI();

	//��ʼ��UI����
	void InitializeUIData();

	//���缫�б�
	void FillElectrodeList();

	//���������б�
	void UpdataElecAttrList();

	//ѡ��ȫ���缫
	void ToggleSelectAllElec();

	//�򿪵�ǰ���Ŀ¼�ص�
	void OpenCurWorkTablePath();

	//ѡ�񵼳����·���ص�
	void SelectExportTablePath();

	//Ӧ�õ缫BOM
	bool ApplyElecBom();

	//����UI
	void DestroyUI();

protected:

	//�������ݶ�������
	vector<EActBomData> uiDefDataColl;

	//���BOM���������ռ���
	vector<TableBomDefineData> tableBomDefDataColl;

	//EActϵͳ���������ռ���
	EActSystemDefineData eActSysDefData;

	//EManϵͳ���������ռ���
	EManSystemDefineData eManSysDefData;

	//�缫�������ռ���
	vector<pair<string, string>> elecSubtypeColl;

	//�缫�б�ؼ�
	EActListCtrl *elecListCtrl;

	//�缫�����б�ؼ�
	EActListCtrl *elecAttrListCtrl;

	//��������
	EActPart *displayPart;

	//���������ռ���
	map<string, vector<EActBomData>> uiDataColl;

	//�缫ԭ���ռ���
	map<string, EActElecPrototype *> elecPrototypeColl;

	//������
	EActStringCoder *stringCoder;

	//�ظ���ʾ
	int repeatOption;

	//Ĭ�Ϲ��캯��
	ElectrodeBom();

	//Ĭ����������
	~ElectrodeBom();

	//�缫�б�ѡ�лص�
	static void ElecListCtrlLButtonDown(void *UserData); 

	//дExcel Bom
	void WriteExcelBom(const vector<string> &elecNameColl);

	//��ȡPart������
	vector<EActBomData> GetPartData(const vector<EActBomData> &bomDefDataColl);

	//һ���缫ԭ��һ��
	vector<vector<EActBomData>> GetElecDataByElecPrototype(const vector<EActBomData> &bomDefDataColl, const vector<string> &elecNameColl);

	//һ���缫�����͵�һ��
	vector<vector<EActBomData>> GetElecDataByContainType(const vector<EActBomData> &bomDefDataColl, const vector<string> &elecNameColl);

	//һ���缫��β�ŵ�һ��
	vector<vector<EActBomData>> GetElecDataByContainTail(const vector<EActBomData> &bomDefDataColl, const vector<string> &elecNameColl);

	//��ȡ��׼��Ϣ
	EActBomData GetStandardData(EActElecPrototype *elecPrototype, const EActBomData &bomDefData);

	//�ϴ�ϵͳBom
	void UploadSystemBom(const vector<string> &elecNameColl);

	//�ϴ�EManϵͳBOM
	void UploadEManSystemBom(const vector<string> &elecNameColl);
};

#endif