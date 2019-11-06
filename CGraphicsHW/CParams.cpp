// CParams.cpp : implementation file
//

#include "stdafx.h"
#include "CGraphicsHW.h"
#include "CParams.h"
#include "MainFrm.h"
#include "afxdialogex.h"


// CParams dialog

IMPLEMENT_DYNAMIC(CParams, CDialog)

CParams::CParams(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_aparam(1)
	, m_bparam(1)
{
	/*get client rect size to set sparam*/
	CRect MyRect;
	
	
	CMainFrame* pDlg = (CMainFrame*)AfxGetMainWnd();
	pDlg->GetWindowRect(MyRect);
	m_sparam = MyRect.Width() / 10;


}

CParams::~CParams()
{
}

void CParams::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_APARAM, m_aparam);
	DDV_MinMaxInt(pDX, m_aparam, 1, INT_MAX);
	DDX_Text(pDX, IDC_BPARAM, m_bparam);
	DDV_MinMaxInt(pDX, m_bparam, 1, INT_MAX);
	DDX_Text(pDX, IDC_SPARAM, m_sparam);
	DDV_MinMaxInt(pDX, m_sparam, 1, INT_MAX);
}


BEGIN_MESSAGE_MAP(CParams, CDialog)
END_MESSAGE_MAP()


// CParams message handlers

