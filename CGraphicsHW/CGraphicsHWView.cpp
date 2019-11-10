
// CGraphicsHWView.cpp : implementation of the CCGraphicsHWView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CGraphicsHW.h"
#endif
#include "resource.h"
#include "CGraphicsHWDoc.h"
#include "CGraphicsHWView.h"
#include "CParams.h"
#include "MainFrm.h"
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
	ON_COMMAND(IDC_PARAMTOOLBAR, &CCGraphicsHWView::OnSettingsParameters)
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

	int x;
	int y;
	COLORREF color;
	POINT pt;
	CRect rect; // Client rectangle

	GetClientRect(rect);

	static bool is_first_run = true;
	if (is_first_run) {
		CParams::m_sparam = rect.Width() / 10;
		is_first_run = false;
	}
	

	//Set coordinates system, where the center of the client space is (0,0):
	int origin_x = rect.Width() / 2;
	int origin_y = rect.Height() / 2;
	
	//get relative value in the coordinates system:
	int normalized_x;
	int normalized_y;


	// TODO: add draw code for native data here

	for (x = 0; x < rect.Width(); x++)
	{

		for (y = 0; y < rect.Height(); y++)
		{
			int normalized_x = x - origin_x;
			int normalized_y = origin_y - y;
			pt.x = x;
			pt.y = y;

			if (m_values) {
				color = GetContinuousColor(normalized_x, normalized_y);
			}
			else {
				color = GetDiscreteColor(normalized_x, normalized_y);
			}

			pDC->SetPixel(pt,color);
		}
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
	if (dlgParam.DoModal() == IDOK) {
		/*m_aparam = dlgParam.m_aparam;
		m_bparam = dlgParam.m_bparam;
		m_sparam = dlgParam.m_sparam;*/
	}
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


