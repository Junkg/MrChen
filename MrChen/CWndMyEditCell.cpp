#include "stdafx.h"
#include "CWndMyEditCell.h"


IMPLEMENT_DYNAMIC(CWndMyEditCell, CWnd)

BEGIN_MESSAGE_MAP(CWndMyEditCell, CWnd)

	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
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
	
	m_static.Create(m_str, WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE , CRect(0, 0, m_rect.Width() - m_nEditBoxLen, m_rect.Height()), this, CTLCOLOR_STATIC);
	BOOL bl = m_edit.Create(WS_BORDER|ES_CENTER|WS_CHILD | WS_VISIBLE, CRect(m_rect.Width() - m_nEditBoxLen, 0, m_rect.Width(), m_rect.Height()), this, 0);


	return 0;
}




HBRUSH CWndMyEditCell::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		static HBRUSH hbrStatic = ::CreateSolidBrush(RGB(255, 255, 255));//COLOR是你想设置的背景颜色 此处必须为静态变量，否则不能实现

		pDC->SetBkColor(RGB(255, 255, 255)); //这个在 SetWindowsText 时，会自动用这个背景色刷
		return hbrStatic; //返回该刷
	}
	return hbr;
}
