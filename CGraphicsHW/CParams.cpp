// CParams.cpp : implementation file
//

#include "stdafx.h"
#include "CGraphicsHW.h"
#include "CParams.h"
#include "MainFrm.h"
#include "afxdialogex.h"
#include "Resource.h"


// CParams dialog

IMPLEMENT_DYNAMIC(CParams, CDialog)

int CParams::m_aparam = 1;
int CParams::m_bparam = 1;
int CParams::m_sparam = 1;

COLORREF CParams::c1 = RGB(0,0,0);
COLORREF CParams::c2 = RGB(255,255,255);

CParams::CParams(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
}

CParams::~CParams()
{
}

void CParams::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_APARAM, CParams::m_aparam);
	DDV_MinMaxInt(pDX, CParams::m_aparam, 1, INT_MAX);
	DDX_Text(pDX, IDC_BPARAM, CParams::m_bparam);
	DDV_MinMaxInt(pDX, CParams::m_bparam, 1, INT_MAX);
	DDX_Text(pDX, IDC_SPARAM, CParams::m_sparam);
	DDV_MinMaxInt(pDX, CParams::m_sparam, 1, INT_MAX);
}


BEGIN_MESSAGE_MAP(CParams, CDialog)

	ON_BN_CLICKED(IDC_BUTTON2, &CParams::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CParams::OnBnClickedButton1)
END_MESSAGE_MAP()


// CParams message handlers

void CParams::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	//
	CColorDialog dlgColor(CParams::c2, CC_FULLOPEN);
	dlgColor.DoModal();
	CParams::c2 = dlgColor.GetColor();
}



void CParams::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlgColor(CParams::c1, CC_FULLOPEN);
	dlgColor.DoModal();
	CParams::c1 = dlgColor.GetColor();
}

double f(int x, int y) {
	//Get client sace width and height:
	CRect MyRect;
	CMainFrame* pDlg = (CMainFrame*)AfxGetMainWnd();
	pDlg->GetClientRect(MyRect);

	int w = MyRect.Width();
	int h = MyRect.Height();

	int a = CParams::m_aparam, b = CParams::m_bparam, s = CParams::m_sparam;

	return cos((pow(a*(x-(w/2)), 4) + pow(b*(y-(h/2)), 4)) / pow(s, 3));
}


COLORREF GetContinuousColor(int x, int y) {
	double t = (f(x, y) + 1) / 2;
	COLORREF c1_r = GetRValue(CParams::c1), c1_g = GetGValue(CParams::c1), c1_b = GetBValue(CParams::c1);
	COLORREF c2_r = GetRValue(CParams::c2), c2_g = GetGValue(CParams::c2), c2_b = GetBValue(CParams::c2);
	COLORREF c_red = (COLORREF)((double)c1_r * ((double)1 - t) + (double)c2_r * t);
	COLORREF c_green = (COLORREF)((double)c1_g * ((double)1 - t) + (double)c2_g * t);
	COLORREF c_blue = (COLORREF)((double)c1_b * ((double)1 - t) + (double)c2_b * t);
	return	RGB(c_red, c_green, c_blue);
}

COLORREF GetDiscreteColor(int x, int y) {
	return f(x, y) > 0 ? CParams::c1 : CParams::c2;
}