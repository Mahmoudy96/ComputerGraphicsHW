#pragma once


// CParams dialog

class CParams : public CDialog
{
	DECLARE_DYNAMIC(CParams)

public:
	CParams(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CParams();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_aparam;
	int m_bparam;
	int m_sparam;
};
