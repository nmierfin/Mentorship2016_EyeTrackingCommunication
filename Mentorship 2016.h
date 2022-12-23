
// Mentorship 2016.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMentorship2016App:
// See Mentorship 2016.cpp for the implementation of this class
//

class CMentorship2016App : public CWinApp
{
public:
	CMentorship2016App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMentorship2016App theApp;