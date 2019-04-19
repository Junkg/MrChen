#include "stdafx.h"
#include "CWndStatic.h"


IMPLEMENT_DYNAMIC(CWndStatic,CStatic)

BEGIN_MESSAGE_MAP(CWndStatic,CStatic)

	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CWndStatic::CWndStatic()
	: m_bTran(TRUE)
	
{
	m_crText = RGB(0, 255, 255);
	m_crBackColor = RGB(255, 255, 255);
	m_nfontSize = 18;
	
}


CWndStatic::~CWndStatic()
{
}


HBRUSH CWndStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	if (CTLCOLOR_STATIC == nCtlColor)
	{
		pDC->SelectObject(&m_font);
		pDC->SetTextColor(m_crText);
		pDC->SetBkColor(m_crBackColor);
		if (m_bTran == true)
			pDC->SetBkMode(TRANSPARENT);
	}
	return NULL;
}

void CWndStatic::SetColor(COLORREF color)
{
	m_crText = color;
}

void CWndStatic::SetBKColor(COLORREF color)
{
	m_crBackColor = color;
}

void CWndStatic::SetTransparent(BOOL bTran)
{
	m_bTran = bTran;
}


BOOL CWndStatic::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: 在此添加专用代码和/或调用基类
	dwStyle |= SS_NOTIFY; 
	return CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
}


int CWndStatic::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_font.CreateFont(m_nfontSize,//指定高度
		0, //指定宽度
		0, //指定角度旋转
		0, //指定角度旋转
		FW_NORMAL, //权重
		TRUE,//斜体
		TRUE, //下划现
		0, //删除线
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision 输出精度
		CLIP_DEFAULT_PRECIS,       // nClipPrecision 剪辑精度
		DEFAULT_QUALITY,           // nQuality 
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily  间距和系列
		_T("Arial"));

	return 0;
}


void CWndStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CStatic::OnLButtonDown(nFlags, point);
}
