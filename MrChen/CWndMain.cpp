#include "stdafx.h"
#include "CWndMain.h"

IMPLEMENT_DYNAMIC(CWndMain, CWndBase)

BEGIN_MESSAGE_MAP(CWndMain, CWndBase)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(IDB_WND_MAIN_TEST, IDB_WND_MAIN_TEST,&CWndMain::OnMybuttonClk)
	ON_WM_PAINT()
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

	m_selTest.Create(_T("����ѡ���"), by, WS_CHILD | WS_VISIBLE, CRect(10, 10, 260, 40), this, 0);
	m_selTest.InserItem(_T("TCP �豸"), 0);
	m_selTest.InserItem(_T("UDP �豸"), 1);
	m_selTest.InserItem(_T("�����豸"), 2);
	m_selTest.SetCurSel(0);

	m_editTest.Create(_T("���Ա༭��"),by, WS_CHILD | WS_VISIBLE,CRect(10,50,260,90),this,0);


	m_btnTest.Create(_T("���԰�ť"), WS_CHILD | BS_CENTER | WS_VISIBLE, CRect(100, 100, 250, 130),this,IDB_WND_MAIN_TEST);

	return 0;
}

void CWndMain::OnMybuttonClk(UINT nID)
{
	switch (nID)
	{
	case IDB_WND_MAIN_TEST:
	{
		Sleep(0);
		AfxMessageBox(_T("����˲��԰�ť"));
	}
	break;
	default:
		break;
	}
}


void CWndMain::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
}
