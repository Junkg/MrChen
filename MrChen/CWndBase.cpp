#include "stdafx.h"

#include "CWndBase.h"


IMPLEMENT_DYNAMIC(CWndBase, CWnd)
BEGIN_MESSAGE_MAP(CWndBase,CWnd)

	//ON_WM_SIZE()
END_MESSAGE_MAP()

CWndBase::CWndBase()
{
	m_Rect.SetRect(0, 0, 0, 0);
}

CWndBase::~CWndBase()
{
}




void CWndBase::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	if (0 == m_Rect.left && 0 == m_Rect.right
		&& 0 == m_Rect.top && 0 == m_Rect.bottom) //��һ�������Ի���ʱ����С�仯��������
	{

	}
	else
	{
		if (0 == cx && 0 == cy) //��С��
			return;
		//���µĳߴ�仯
		CRect rect;
		GetClientRect(&rect);
		
	}
	GetClientRect(&m_Rect); //save size of dialog  
	Invalidate();//���´���  
}
