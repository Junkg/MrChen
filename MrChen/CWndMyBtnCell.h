#pragma once


class CWndMyBtnCell : public CButton
{
	DECLARE_DYNAMIC(CWndMyBtnCell)
public:
	CWndMyBtnCell();
	virtual ~CWndMyBtnCell();
	virtual BOOL  Create(LPCTSTR lpszCaption, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID = 0, CCreateContext * pContext = NULL);
protected:
	DECLARE_MESSAGE_MAP()

};

