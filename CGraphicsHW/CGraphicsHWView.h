
// CGraphicsHWView.h : interface of the CCGraphicsHWView class
//

#pragma once


class CCGraphicsHWView : public CView
{
protected: // create from serialization only
	CCGraphicsHWView() noexcept;
	DECLARE_DYNCREATE(CCGraphicsHWView)

	// Attributes
public:
	CCGraphicsHWDoc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Implementation
public:
	virtual ~CCGraphicsHWView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSettingsParameters();
	afx_msg void OnModeValues();
	afx_msg void OnModeZeros();
private:
	bool m_values{true};
public:

	afx_msg void OnUpdateModeValues(CCmdUI *pCmdUI);
	afx_msg void OnUpdateModeZeros(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in CGraphicsHWView.cpp
inline CCGraphicsHWDoc* CCGraphicsHWView::GetDocument() const
   { return reinterpret_cast<CCGraphicsHWDoc*>(m_pDocument); }
#endif

