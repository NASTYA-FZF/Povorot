
// Povorot.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPovorotApp:
// О реализации данного класса см. Povorot.cpp
//

class CPovorotApp : public CWinApp
{
public:
	CPovorotApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPovorotApp theApp;