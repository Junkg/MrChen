#include "stdafx.h"
#include "CWndMyEditCell.h"


IMPLEMENT_DYNAMIC(CWndMyEditCell, CWnd)

BEGIN_MESSAGE_MAP(CWndMyEditCell, CWnd)

	ON_WM_CREATE()
END_MESSAGE_MAP()

CWndMyEditCell::CWndMyEditCell()
{
}


CWndMyEditCell::~CWndMyEditCell()
{
}

BOOL CWndMyEditCell::Create(LPCTSTR lpszWindName, byte & pNum, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd  , UINT nID, int nEditLen, CCreateContext * pContext)
{
	m_str = lpszWindName;
	m_rect = rect;
	m_nEditBoxLen = nEditLen;
	return CWnd::Create(NULL,lpszWindName,dwStyle,rect,pParentWnd,nID);
}

int CWndMyEditCell::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct)  == -1)
		return -1;
	
	m_static.Create(m_str, WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE , CRect(0, 0, m_rect.Width() - m_nEditBoxLen, m_rect.Height()), this, 0);
	BOOL bl = m_edit.Create(WS_BORDER|ES_CENTER|WS_CHILD | WS_VISIBLE, CRect(m_rect.Width() - m_nEditBoxLen, 0, m_rect.Width(), m_rect.Height()), this, 0);


	return 0;
}


