#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>

using namespace msclr::interop;
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

//https://blog.csdn.net/huihut/article/details/81984271
//http://www.cppblog.com/mzty/archive/2007/08/07/29307.html
//https://stackoverflow.com/questions/12212198/converting-characters-to-unicode-with-c-cli-results-in-random-characters
namespace AgoraClrLibrary {

	//static std::string MarshalString(String^ s) {
	//	/*if (s == nullptr) return std::string();
	//	IntPtr middleStr = Runtime::InteropServices::Marshal::StringToHGlobalUni(s);
	//	std::string result((char *)middleStr.ToPointer());
	//	Runtime::InteropServices::Marshal::FreeHGlobal(middleStr);
	//	return result;*/

	//	if (s == nullptr) return std::string();

	//	marshal_context^ context = gcnew marshal_context();
	//	const char* name1 = context->marshal_as<const char*>(s);

	//	char* pch = _strdup(name1); //const char* => char*
	//	delete context;

	//	return std::string(pch);
	//}

	//static std::string MarshalString2(String^ s) {
	//	if (s == nullptr) return std::string();
	//	IntPtr middleStr = Runtime::InteropServices::Marshal::StringToHGlobalUni(s);
	//	std::string result((char*)middleStr.ToPointer());
	//	Runtime::InteropServices::Marshal::FreeHGlobal(middleStr);
	//	return result;
	//}

	static  String^ ConvertUNICODE2String(CHAR* input) {

		int bufSize = MultiByteToWideChar(CP_UTF8, 0, input, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[bufSize];
		MultiByteToWideChar(CP_UTF8, 0, input, -1, wstr, bufSize);
		String^ val = gcnew String(wstr);
		delete[] wstr;

		return val;
	}
}
