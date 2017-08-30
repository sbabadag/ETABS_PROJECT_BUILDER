
// ETABS_PROJECT_BUILDERView.cpp : implementation of the CETABS_PROJECT_BUILDERView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ETABS_PROJECT_BUILDER.h"
#endif

#include "ETABS_PROJECT_BUILDERDoc.h"
#include "ETABS_PROJECT_BUILDERView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CETABS_PROJECT_BUILDERView

IMPLEMENT_DYNCREATE(CETABS_PROJECT_BUILDERView, CView)

BEGIN_MESSAGE_MAP(CETABS_PROJECT_BUILDERView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CETABS_PROJECT_BUILDERView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CETABS_PROJECT_BUILDERView construction/destruction

CETABS_PROJECT_BUILDERView::CETABS_PROJECT_BUILDERView()
{
	// TODO: add construction code here

}

CETABS_PROJECT_BUILDERView::~CETABS_PROJECT_BUILDERView()
{
}

BOOL CETABS_PROJECT_BUILDERView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CETABS_PROJECT_BUILDERView drawing

void CETABS_PROJECT_BUILDERView::OnDraw(CDC* /*pDC*/)
{
	CETABS_PROJECT_BUILDERDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CETABS_PROJECT_BUILDERView printing


void CETABS_PROJECT_BUILDERView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CETABS_PROJECT_BUILDERView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CETABS_PROJECT_BUILDERView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CETABS_PROJECT_BUILDERView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CETABS_PROJECT_BUILDERView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CETABS_PROJECT_BUILDERView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CETABS_PROJECT_BUILDERView diagnostics

#ifdef _DEBUG
void CETABS_PROJECT_BUILDERView::AssertValid() const
{
	CView::AssertValid();
}

void CETABS_PROJECT_BUILDERView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CETABS_PROJECT_BUILDERDoc* CETABS_PROJECT_BUILDERView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CETABS_PROJECT_BUILDERDoc)));
	return (CETABS_PROJECT_BUILDERDoc*)m_pDocument;
}
#endif //_DEBUG


// CETABS_PROJECT_BUILDERView message handlers
