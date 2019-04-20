#pragma once

#include "CWndBase.h"
#include "CWndMySelBox.h"

class CWndConfig :public CWndBase
{
	DECLARE_DYNAMIC(CWndConfig)
public:
	CWndConfig();
	virtual ~CWndConfig();
	virtual BOOL  Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID);

	 
public :
	void  ShowPane(bool bShow);
protected:
	DECLARE_MESSAGE_MAP()
private:
	CWndMySelBox  m_DeviType;//选择设备类型
	
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

