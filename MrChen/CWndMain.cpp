#include "stdafx.h"
#include "CWndMain.h"

IMPLEMENT_DYNAMIC(CWndMain, CWndBase)

BEGIN_MESSAGE_MAP(CWndMain, CWndBase)
	ON_WM_CREATE()
END_MESSAGE_MAP()

CWndMain::CWndMain()
{
}


CWndMain::~CWndMain()
{
}

BOOL CWndMain::Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID)
{
	return CWnd::Create(NULL, _T("WndMain"), dwStyle, rect, pParentWnd, nID);
}

void CWndMain::ShowPane(bool bShow)
{
	if (bShow)
	{
		if (!IsWindow(m_hWnd))
		{
			CRect rect;
			theFrame->GetClientRect(&rect);
			Create(WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, rect, theFrame->GetActiveView(), IDW_WND_MAIN);
		}

	}
	else
	{
		ShowWindow(SW_HIDE);
	}
}

int CWndMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWndBase::OnCreate(lpCreateStruct) == -1)
		return -1;

	byte by;

	m_selTest.Create(_T("²âÊÔÑ¡Ôñ¿ò"), by, WS_CHILD | WS_VISIBLE, CRect(300, 10, 520, 40), this, 0);
	return 0;
}
