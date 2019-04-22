#include "stdafx.h"
#include "CWndMyBtnCell.h"

IMPLEMENT_DYNAMIC(CWndMyBtnCell,CButton)

BEGIN_MESSAGE_MAP(CWndMyBtnCell,CButton)

END_MESSAGE_MAP()

CWndMyBtnCell::CWndMyBtnCell()
{
}


CWndMyBtnCell::~CWndMyBtnCell()
{
}

BOOL CWndMyBtnCell::Create(LPCTSTR lpszCaption, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{
	LPCTSTR  m_str = lpszCaption;
	return CButton::Create(lpszCaption, dwStyle, rect, pParentWnd, nID);
}
