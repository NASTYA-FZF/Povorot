
// Povorot.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CPovorotApp:
// � ���������� ������� ������ ��. Povorot.cpp
//

class CPovorotApp : public CWinApp
{
public:
	CPovorotApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CPovorotApp theApp;