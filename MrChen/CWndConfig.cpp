#include "stdafx.h"
#include "CWndConfig.h"


IMPLEMENT_DYNAMIC(CWndConfig, CWndBase)

BEGIN_MESSAGE_MAP(CWndConfig, CWndBase)

	ON_WM_CREATE()
END_MESSAGE_MAP()

CWndConfig::CWndConfig()
{
}


CWndConfig::~CWndConfig()
{
}

BOOL CWndConfig::Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID)
{
	return CWnd::Create(NULL,_T("WndConfig"),dwStyle,rect,pParentWnd,nID);
}

void CWndConfig::ShowPane(bool bShow)
{
	if (bShow)
	{
		if (!IsWindow(m_hWnd)) //IsWindows(HWND) ȷ�� hWND �Ĵ��ھ���Ƿ������һ�����ڵĴ��ڣ�û��������0
		{

			/*Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, CRect(S_START, H_START, 500, 700), theMainFrame->GetActiveView(),
				IDW_WND_CONFIG);*/
			
		}
	}
	else
	{
		if (IsWindow(m_hWnd))
		{
			ShowWindow(SW_HIDE);
		}
	}
}


int CWndConfig::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWndBase::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	
	/*m_DeviType.Create(_T("�豸����"), theApp.m_curDevi->nType.CMrChenApp, WS_CHILD | WS_VISIBLE,
		CRect(0, 0, 100, 20), this, 0);*/
	return 0;
}
