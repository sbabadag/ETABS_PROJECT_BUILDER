
// ETABS_PROJECT_BUILDERDoc.cpp : implementation of the CETABS_PROJECT_BUILDERDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ETABS_PROJECT_BUILDER.h"
#endif

#include "ETABS_PROJECT_BUILDERDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CETABS_PROJECT_BUILDERDoc

IMPLEMENT_DYNCREATE(CETABS_PROJECT_BUILDERDoc, CDocument)

BEGIN_MESSAGE_MAP(CETABS_PROJECT_BUILDERDoc, CDocument)
END_MESSAGE_MAP()


// CETABS_PROJECT_BUILDERDoc construction/destruction

CETABS_PROJECT_BUILDERDoc::CETABS_PROJECT_BUILDERDoc()
{
	// TODO: add one-time construction code here

}

CETABS_PROJECT_BUILDERDoc::~CETABS_PROJECT_BUILDERDoc()
{
}

BOOL CETABS_PROJECT_BUILDERDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CETABS_PROJECT_BUILDERDoc serialization

void CETABS_PROJECT_BUILDERDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CETABS_PROJECT_BUILDERDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CETABS_PROJECT_BUILDERDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CETABS_PROJECT_BUILDERDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CETABS_PROJECT_BUILDERDoc diagnostics

#ifdef _DEBUG
void CETABS_PROJECT_BUILDERDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CETABS_PROJECT_BUILDERDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CETABS_PROJECT_BUILDERDoc commands
