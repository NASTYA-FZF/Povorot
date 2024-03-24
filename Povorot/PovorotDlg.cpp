
// PovorotDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Povorot.h"
#include "PovorotDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CPovorotDlg



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


// ����������� ��������� CPovorotDlg

BOOL CPovorotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	My_ugol.SetRange(-180, 180, TRUE);
	My_ugol.SetPos(0);
	My_ugol.SetTicFreq(1);
	ugol.SetWindowTextW(L"0");
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CPovorotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CPovorotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPovorotDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	//CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	MyPicture.ugol_povorota = My_ugol.GetPos();
	CString str;
	str.Format(L"%d", MyPicture.ugol_povorota);
	ugol.SetWindowTextW(str);
	MyPicture.Invalidate(FALSE);
}
