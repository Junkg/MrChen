#pragma once

#include "CWndBase.h" 
#include "CWndMyStatic.h"
#include "CWndMyEdit.h"
class CWndMyEditCell : public CWnd
{
	DECLARE_DYNAMIC(CWndMyEditCell)
public:

	CWndMyEditCell();
	~CWndMyEditCell();
	virtual BOOL Create(LPCTSTR lpszWindName, byte & pNum, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID = 0 , int nEditLen = 120, CCreateContext * pContext = NULL);

private:
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	DECLARE_MESSAGE_MAP()

private:
	CWndMyStatic  m_static;
	CWndMyEdit    m_edit;


	LPCTSTR  m_str;
	CRect    m_rect;
	int      m_nEditBoxLen;
	

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

