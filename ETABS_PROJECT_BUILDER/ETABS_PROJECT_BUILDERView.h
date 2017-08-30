
// ETABS_PROJECT_BUILDERView.h : interface of the CETABS_PROJECT_BUILDERView class
//

#pragma once


class CETABS_PROJECT_BUILDERView : public CView
{
protected: // create from serialization only
	CETABS_PROJECT_BUILDERView();
	DECLARE_DYNCREATE(CETABS_PROJECT_BUILDERView)

// Attributes
public:
	CETABS_PROJECT_BUILDERDoc* GetDocument() const;

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
	virtual ~CETABS_PROJECT_BUILDERView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ETABS_PROJECT_BUILDERView.cpp
inline CETABS_PROJECT_BUILDERDoc* CETABS_PROJECT_BUILDERView::GetDocument() const
   { return reinterpret_cast<CETABS_PROJECT_BUILDERDoc*>(m_pDocument); }
#endif

