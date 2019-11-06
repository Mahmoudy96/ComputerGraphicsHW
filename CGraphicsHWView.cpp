
// CGraphicsHWView.cpp : implementation of the CCGraphicsHWView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CGraphicsHW.h"
#endif

#include "CGraphicsHWDoc.h"
#include "CGraphicsHWView.h"
#include "CParams.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCGraphicsHWView

IMPLEMENT_DYNCREATE(CCGraphicsHWView, CView)

BEGIN_MESSAGE_MAP(CCGraphicsHWView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SETTINGS_PARAMETERS, &CCGraphicsHWView::OnSettingsParameters)
	ON_COMMAND(ID_MODE_VALUES, &CCGraphicsHWView::OnModeValues)
	ON_COMMAND(ID_MODE_ZEROS, &CCGraphicsHWView::OnModeZeros)
	ON_UPDATE_COMMAND_UI(ID_MODE_VALUES, &CCGraphicsHWView::OnUpdateModeValues)
	ON_UPDATE_COMMAND_UI(ID_MODE_ZEROS, &CCGraphicsHWView::OnUpdateModeZeros)
END_MESSAGE_MAP()

// CCGraphicsHWView construction/destruction

CCGraphicsHWView::CCGraphicsHWView() noexcept
{
	// TODO: add construction code here

}

CCGraphicsHWView::~CCGraphicsHWView()
{
}

BOOL CCGraphicsHWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCGraphicsHWView drawing

void CCGraphicsHWView::OnDraw(CDC* pDC)
{
	CCGraphicsHWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	if(m_values == true){
		pDC->Ellipse(100, 100, 300, 300);
		/* f(a,b,s) value representation */
	}
	else{
		pDC->Rectangle(50, 100, 400, 200);
		/* f(a,b,s) zeros representation */
	}

}



// CCGraphicsHWView printing

BOOL CCGraphicsHWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGraphicsHWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGraphicsHWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCGraphicsHWView diagnostics

#ifdef _DEBUG
void CCGraphicsHWView::AssertValid() const
{
	CView::AssertValid();
}

void CCGraphicsHWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGraphicsHWDoc* CCGraphicsHWView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGraphicsHWDoc)));
	return (CCGraphicsHWDoc*)m_pDocument;
}
#endif //_DEBUG


// CCGraphicsHWView message handlers


void CCGraphicsHWView::OnSettingsParameters()
{
	CParams dlgParam;
	dlgParam.DoModal();
}


void CCGraphicsHWView::OnModeValues()
{
	m_values = true;
	Invalidate();
	UpdateWindow();
	// TODO: Add your command handler code here
}


void CCGraphicsHWView::OnModeZeros()
{
	m_values = false;
	Invalidate();
	UpdateWindow();
	// TODO: Add your command handler code here
}


void CCGraphicsHWView::OnUpdateModeValues(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_values);
}


void CCGraphicsHWView::OnUpdateModeZeros(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(!m_values);
}
