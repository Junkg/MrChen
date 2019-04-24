#include "stdafx.h"
#include "CWndMyListCell.h"


IMPLEMENT_DYNAMIC(CWndMyListCell, CWndBase)

CWndMyListCell::CWndMyListCell()
	: m_bInited(FALSE)
	// , m_recentActionLine(0)
{

}

CWndMyListCell::~CWndMyListCell()
{
	//     m_fntActLst.DeleteObject();
}


BEGIN_MESSAGE_MAP(CWndMyListCell, CWndBase)
	//	ON_WM_PAINT()
	// 	ON_MESSAGE(WM_UPDATEMCUSTATUS, &CWndMyListCell::OnUpdateMcuStatus)
	ON_WM_CREATE()
	//ON_LBN_SELCHANGE(IDC_LISTBOX_ACTION, &CWndMyListCell::OnLbnSelchangeList)
	// 	ON_WM_ERASEBKGND()
	ON_WM_HSCROLL()
	//	ON_WM_KILLFOCUS()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CWndMyListCell::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));

	return CWndBase::OnEraseBkgnd(pDC);
}


void CWndMyListCell::OnLbnSelchangeList(void)
{
	int n = m_listAction.GetCurSel();

}

void CWndMyListCell::ShowPane(bool bShow)
{
	if (bShow)
	{
		if (IsWindow(m_hWnd))
		{
			m_bInited = FALSE;
			DestroyWindow();
		}
	
		if (m_bInited == FALSE)
		{
			InitAction();
			SetNowActionLine(0);
			m_bInited = TRUE;
		}

		ShowWindow(SW_SHOW);
		BringWindowToTop();
	}
	else
	{
		if (IsWindow(m_hWnd))
		{
			m_bInited = FALSE;
			DestroyWindow();
		}
	}


}


void CWndMyListCell::InsertActionLine(int nNowLineNum)
{


	InitAction();
	m_listAction.SetTopIndex(nNowLineNum - 4);


}

void CWndMyListCell::RemoveActionLine(int nLineNum)
{
	// 	m_listAction.DeleteString(nLineNum);
	InitAction();
	m_listAction.SetTopIndex(nLineNum - 4);

}


void CWndMyListCell::ModifyActionLine(int nLineNum)
{
	// 	m_listAction.DeleteString(nNowLineNum);
	// 	InitAction();
	

	CString str;

	m_listAction.SetRedraw(FALSE);

	m_listAction.DeleteString(nLineNum);
	m_listAction.InsertString(nLineNum, str);

	m_listAction.SetRedraw(TRUE);

	// 		m_listAction.SetTopIndex(nLineNum-4);

}

void CWndMyListCell::RefreshActionLine(int nLineNum)
{

	InitAction();

}

int CWndMyListCell::SetNowActionLine(int nNowAction)
{

	m_listAction.Invalidate(FALSE);

	m_listAction.SetTopIndex(nNowAction - 4);
	return 0;


	m_listAction.Invalidate(FALSE);


	return 0;
}

int CWndMyListCell::InitAction(void)
{


	m_listAction.SetRedraw(FALSE);

	m_listAction.ResetContent();

	


	int nFitLine;
	nFitLine = (m_rectAction.bottom - m_rectAction.top) / 40;
	

	m_listAction.SetRedraw(TRUE);

	return 0;

}


int CWndMyListCell::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWndBase::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rect(0, 0, m_rectAction.Width(), m_rectAction.Height());
	//  	m_listAction.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|WS_VSCROLL|LVS_REPORT,CRect(0,0,300,365),this,IDC_LISTBOX_ACTION);
	m_listAction.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL |/*WS_HSCROLL| */LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LVS_REPORT,
		/*CRect(0,0,300,365)*/rect, this, 0);

	// 	m_listAction.SendMessage(LB_SETHORIZONTALEXTENT,500,0); //水平滚动条

	CFont         fnt;
	fnt.CreateFont(48, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, 0, 1, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("宋体"));
	m_listAction.SetFont(&fnt, 1);


	return 0;
}

