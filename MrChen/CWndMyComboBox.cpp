#include "stdafx.h"
#include "CWndMyComboBox.h"

IMPLEMENT_DYNAMIC(CWndMyComboBox,CComboBox)

BEGIN_MESSAGE_MAP(CWndMyComboBox,CComboBox)

END_MESSAGE_MAP()
CWndMyComboBox::CWndMyComboBox()
{
}


CWndMyComboBox::~CWndMyComboBox()
{
}

BOOL CWndMyComboBox::Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID)
{
	m_nID = nID;
	return CComboBox::Create(dwStyle,rect,pParentWnd,nID);
}
