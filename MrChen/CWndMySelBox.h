#pragma once

#include "CWndMyComboBox.h"
#include "CWndMyStatic.h"


class CWndMySelBox:public CWnd 
{
	DECLARE_DYNAMIC(CWndMySelBox)
public:
	CWndMySelBox();
	virtual ~CWndMySelBox();

	virtual BOOL Create(LPCTSTR lpszWindName, byte & pNum, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, int nSelLen = 120, CCreateContext * pContext = NULL);
	
	void InserItem(CString str, byte n);
	void SetCurSel(byte n);
	int  GetSelected();
public:
	
	CWndMyComboBox  m_combox;
	CWndMyStatic   m_static;
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCbnSelectedComboBox(void);

private:
	UINT m_nID; 
	CRect	m_rect;
	CString m_strText;
	byte* m_pNum;
	int m_nSelLen;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

