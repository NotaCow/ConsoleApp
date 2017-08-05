//#define _USE_DEVELOP_
#define _USE_READ_ONLY_

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <tchar.h>
	
float g_BuildVer;
WCHAR *g_BuildName;

void main()
{
	FILE *fp;
	WCHAR title[256];
	//wcsstr()

#ifdef _USE_DEVELOP_
	g_BuildVer = 0.01f;
	g_BuildName = TEXT("test");

	fopen_s(&fp ,"inf.txt", "w");
	fwprintf(fp, L"curBuildName:%s\n", g_BuildName);
	fwprintf(fp, L"curBuildVer :%f\n", g_BuildVer);

#endif
#ifdef _USE_READ_ONLY_
	fopen_s(&fp, "info.txt", "r");
	fwscanf(fp, L"curBuildName:%s\n", g_BuildName);
	fwscanf(fp, L"curBuildName:%f\n", &g_BuildVer);

	//wprintf(L"%s %.2f\n", g_BuildName, &g_BuildVer);
	//wprintf(L"Copyright (C) by Uka.");

#endif
	// _countof(arr) defined in VS. This is sizeof(arr) / sizeof(arr[0]).
	swprintf_s(title, _countof(title), TEXT("%s %.2f"), g_BuildName, g_BuildVer); 
	SetConsoleTitle(title);
	_getch();

	fclose(fp);

	//free(title);
}