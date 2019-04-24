#include "stdafx.h"
#include "CWndMySelBox.h"

IMPLEMENT_DYNAMIC(CWndMySelBox,CWnd)

BEGIN_MESSAGE_MAP(CWndMySelBox,CWnd)

	ON_WM_CREATE()
	ON_CBN_SELENDOK(IDC_COMBO_CELL,&CWndMySelBox::OnCbnSelectedComboBox)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

CWndMySelBox::CWndMySelBox()
{
}


CWndMySelBox::~CWndMySelBox()
{
}

BOOL CWndMySelBox::Create(LPCTSTR lpszWindName, byte & pNum, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, int nSelLen, CCreateContext * pContext)
{
	m_nID = nID;
	m_rect = rect;
	m_strText = lpszWindName;
	m_nSelLen = nSelLen;
	return CWnd::Create(NULL,lpszWindName,dwStyle,rect,pParentWnd,nID,pContext);
}

void CWndMySelBox::InserItem(CString str, byte n)
{
	m_combox.InsertString(n, str);
}

void CWndMySelBox::SetCurSel(byte n)
{
	m_combox.SetCurSel(n);
}

int CWndMySelBox::GetSelected()
{
	return m_combox.GetCurSel();
}

int CWndMySelBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	m_static.SetBKColor(RGB(255, 255, 255));
	m_static.Create(m_strText, SS_LEFT /*| SS_WHITERECT */ | WS_VISIBLE | WS_CHILD | SS_CENTERIMAGE,
		CRect(0, 0, m_rect.Width() /*- m_nSelLen*/, m_rect.Height()), this, CTLCOLOR_STATIC);
	m_combox.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST/*|CBS_OWNERDRAWFIXED*/,
		CRect((m_rect.Width() - (2 + m_nSelLen)), 2, m_rect.Width() - 5, m_rect.Height() + 400), this, IDC_COMBO_CELL);
	

	return 0;
}

void CWndMySelBox::OnCbnSelectedComboBox(void)
{
	*m_pNum = m_combox.GetCurSel();
}


HBRUSH CWndMySelBox::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		static HBRUSH hbrStatic = ::CreateSolidBrush(RGB(255, 255, 255));//COLOR是你想设置的背景颜色 此处必须为静态变量，否则不能实现
		
		pDC->SetBkColor(RGB(255, 255, 255)); //这个在 SetWindowsText 时，会自动用这个背景色刷
		return hbrStatic; //返回该刷
	}
	return hbr;
}
