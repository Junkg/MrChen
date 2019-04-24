#include "stdafx.h"
#include "CWndMyStatic.h"


IMPLEMENT_DYNAMIC(CWndMyStatic, CStatic)

CFont  CWndMyStatic::m_font;
BEGIN_MESSAGE_MAP(CWndMyStatic,CStatic)

//	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CWndMyStatic::CWndMyStatic()
	: m_bTran(TRUE)
	
{
	m_crText = RGB(0, 255, 255);
	m_crBackColor = RGB(255, 255, 255);
	m_nfontSize = 18;

	if (m_font.GetSafeHandle() == NULL)
	{
		BOOL bl = m_font.CreateFont(m_nfontSize,//ָ���߶�
			0, //ָ�����
			0, //ָ���Ƕ���ת
			0, //ָ���Ƕ���ת
			FW_NORMAL, //Ȩ��
			FALSE,//б��
			FALSE, //�»���
			0, //ɾ����
			ANSI_CHARSET,              // nCharSet
			OUT_DEFAULT_PRECIS,        // nOutPrecision �������
			CLIP_DEFAULT_PRECIS,       // nClipPrecision ��������
			DEFAULT_QUALITY,           // nQuality 
			DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily  ����ϵ��
			_T("����"));
		if (!bl)
		{
			DWORD dwErr = GetLastError();
		}
			

	}
	
}


CWndMyStatic::~CWndMyStatic()
{
}


//HBRUSH CWndMyStatic::CtlColor(CDC* pDC, UINT nCtlColor)
//{
//	// TODO:  �ڴ˸��� DC ���κ�����
//
//	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
//	//if (CTLCOLOR_STATIC == nCtlColor)
//	{
//		pDC->SelectObject(&m_font);
//		pDC->SetTextColor(m_crText);
//		pDC->SetBkColor(m_crBackColor);
//		if (m_bTran == TRUE)
//			pDC->SetBkMode(TRANSPARENT);
//	}
//	return NULL;
//}

void CWndMyStatic::SetColor(COLORREF color)
{
	m_crText = color;
}

void CWndMyStatic::SetBKColor(COLORREF color)
{
	m_crBackColor = color;
}

void CWndMyStatic::SetTransparent(BOOL bTran)
{
	m_bTran = bTran;
}

void CWndMyStatic::SetFont(CFont font)
{
	if (font.GetSafeHandle() != NULL)
	{
		CWnd::SetFont(&font);
	}
}


BOOL CWndMyStatic::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: �ڴ����ר�ô����/����û���
	//dwStyle |= SS_NOTIFY;
	m_str = lpszText;
	return CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
}


int CWndMyStatic::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	
	//SetWindowText(m_str);
	return 0;
}


void CWndMyStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CStatic::OnLButtonDown(nFlags, point);
}
