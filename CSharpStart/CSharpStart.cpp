// ������ DLL �ļ���

#include "stdafx.h"

#include "CSharpStart.h"
#include "AssemblyDynamicLoader.h"


using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Reflection;
using namespace System::Collections;

char* Show(char* actionName)
{
	char* result = "";
	try
	{
		String ^ actionNameStr = Marshal::PtrToStringAnsi((IntPtr)actionName);
		auto path = Path::GetDirectoryName(Assembly::GetExecutingAssembly()->Location);
		//��ȡ�ϼ�Ŀ¼
		path = path->Substring(0, path->LastIndexOf("\\"));
		path = Path::Combine(path,"Application");
		ProxyObject::ExecuteMothod(actionNameStr, path);
	}
	catch (Exception^ ex)
	{
		result = (char*)Marshal::StringToHGlobalAnsi(ex->Message).ToPointer();
	}
	return result;
}

