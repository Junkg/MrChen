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
	//theDoc = (CMrChenDoc *)theFrame->GetActiveDocument();
	byte by;

	m_selTest.Create(_T("测试选择框"), by, WS_CHILD | WS_VISIBLE, CRect(0, 10, 520, 40), this, 0);
	m_selTest.InserItem(_T("TCP 设备"), 0);
	m_selTest.InserItem(_T("UDP 设备"), 1);
	m_selTest.InserItem(_T("串口设备"), 2);
	m_selTest.SetCurSel(0);

	return 0;
}
