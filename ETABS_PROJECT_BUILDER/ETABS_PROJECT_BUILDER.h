
// ETABS_PROJECT_BUILDER.h : main header file for the ETABS_PROJECT_BUILDER application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CETABS_PROJECT_BUILDERApp:
// See ETABS_PROJECT_BUILDER.cpp for the implementation of this class
//

class CETABS_PROJECT_BUILDERApp : public CWinAppEx
{
public:
	CETABS_PROJECT_BUILDERApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CETABS_PROJECT_BUILDERApp theApp;
