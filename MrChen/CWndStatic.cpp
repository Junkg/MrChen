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
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
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
	// TODO: �ڴ����ר�ô����/����û���
	dwStyle |= SS_NOTIFY; 
	return CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
}


int CWndStatic::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_font.CreateFont(m_nfontSize,//ָ���߶�
		0, //ָ�����
		0, //ָ���Ƕ���ת
		0, //ָ���Ƕ���ת
		FW_NORMAL, //Ȩ��
		TRUE,//б��
		TRUE, //�»���
		0, //ɾ����
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision �������
		CLIP_DEFAULT_PRECIS,       // nClipPrecision ��������
		DEFAULT_QUALITY,           // nQuality 
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily  ����ϵ��
		_T("Arial"));

	return 0;
}


void CWndStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CStatic::OnLButtonDown(nFlags, point);
}
