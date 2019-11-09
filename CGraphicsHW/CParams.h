#pragma once


// CParams dialog

class CParams : public CDialog
{
	DECLARE_DYNAMIC(CParams)

public:
	CParams(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CParams();

	static int m_aparam;
	static int m_bparam;
	static int m_sparam;

	static COLORREF c1;
	static COLORREF c2;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};

COLORREF GetContinuousColor(int x, int y);
COLORREF GetDiscreteColor(int x, int y);

