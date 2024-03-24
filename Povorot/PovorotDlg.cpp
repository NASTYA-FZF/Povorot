
// PovorotDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Povorot.h"
#include "PovorotDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CPovorotDlg



CPovorotDlg::CPovorotDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPovorotDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPovorotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MY_DRAW, MyPicture);
	DDX_Control(pDX, IDC_EDIT1, ugol);
	DDX_Control(pDX, IDC_SLIDER1, My_ugol);
}

BEGIN_MESSAGE_MAP(CPovorotDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
//	ON_WM_LBUTTONDOWN()
//ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// обработчики сообщений CPovorotDlg

BOOL CPovorotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	My_ugol.SetRange(-180, 180, TRUE);
	My_ugol.SetPos(0);
	My_ugol.SetTicFreq(1);
	ugol.SetWindowTextW(L"0");
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CPovorotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CPovorotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPovorotDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	//CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	MyPicture.ugol_povorota = My_ugol.GetPos();
	CString str;
	str.Format(L"%d", MyPicture.ugol_povorota);
	ugol.SetWindowTextW(str);
	MyPicture.Invalidate(FALSE);
}
