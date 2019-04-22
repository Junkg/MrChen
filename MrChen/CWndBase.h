#pragma once

#define  S_START 0 
#define  H_START 0 

#include "MainFrm.h"
#include "MrChenDoc.h"
#include "MrChen.h"

//纯虚基类
class CWndBase : public CWnd
{
	DECLARE_DYNAMIC(CWndBase)
public:
	CWndBase();
	~CWndBase();

	virtual void ShowPane(bool bShow) = 0; //纯虚基类
	
protected:
	DECLARE_MESSAGE_MAP()

	CRect m_Rect;
	
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

