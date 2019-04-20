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

	// TODO: 在此处添加消息处理程序代码

	if (0 == m_Rect.left && 0 == m_Rect.right
		&& 0 == m_Rect.top && 0 == m_Rect.bottom) //第一次启动对话框时，大小变化不做处理
	{

	}
	else
	{
		if (0 == cx && 0 == cy) //最小化
			return;
		//有新的尺寸变化
		CRect rect;
		GetClientRect(&rect);
		
	}
	GetClientRect(&m_Rect); //save size of dialog  
	Invalidate();//更新窗口  
}
