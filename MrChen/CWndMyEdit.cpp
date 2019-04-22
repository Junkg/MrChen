
#include "stdafx.h"

#include "CWndMyEdit.h"

IMPLEMENT_DYNAMIC(CWndMyEdit,CEdit)

BEGIN_MESSAGE_MAP(CWndMyEdit,CEdit)

	ON_WM_LBUTTONDOWN()
	

END_MESSAGE_MAP()

CWndMyEdit::CWndMyEdit()
{
}

CWndMyEdit::~CWndMyEdit()
{
}

BOOL CWndMyEdit::Create(DWORD dwStyle, CRect & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{
	return CWnd::Create(NULL,_T("CWndMyEdit"),dwStyle,rect,pParentWnd,nID, pContext);
}

void CWndMyEdit::OnLButtonDown(UINT nFlags, CPoint point)
{
	Sleep(0);
	//AfxMessageBox(_T("nihao"));
}
