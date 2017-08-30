
// ETABS_PROJECT_BUILDERDoc.h : interface of the CETABS_PROJECT_BUILDERDoc class
//


#pragma once


class CETABS_PROJECT_BUILDERDoc : public CDocument
{
protected: // create from serialization only
	CETABS_PROJECT_BUILDERDoc();
	DECLARE_DYNCREATE(CETABS_PROJECT_BUILDERDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CETABS_PROJECT_BUILDERDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
