#pragma once
class CWndMyEdit :public CEdit
{
	DECLARE_DYNAMIC(CWndMyEdit)

public:
	CWndMyEdit();
	virtual ~CWndMyEdit();

	virtual BOOL  Create(DWORD  dwStyle, CRect & rect, CWnd * pParentWnd, UINT  nID = 0, CCreateContext* pContext = NULL);
protected:
	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

};

