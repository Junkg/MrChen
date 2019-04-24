#pragma once

#include "CWndBase.h"
#include "CWndMyListBox.h"

#define MAX_STRING_CNT  10
class CWndMyListCell  : public CWndBase
{
	DECLARE_DYNAMIC(CWndMyListCell)

public:
	CWndMyListCell();
	virtual ~CWndMyListCell();

public:
	//当需要增加一条信息时，调用这个函数
	//     void AddText(LPCTSTR lpszText);

protected:
	//     CStringArray  m_lpStrings;
	//     CFont         m_fntActLst;

protected:
	DECLARE_MESSAGE_MAP()
	// 	LRESULT OnUpdateMcuStatus(WPARAM wp, LPARAM lp);

public:
	//     afx_msg void OnPaint();

private:
	// 	int m_lastDocLine;

	CRect m_rectAction;
	//	CListCtrl m_listAction;
	CMyListBox m_listAction;
	//	CListBox m_listAction;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// private:
public:
	//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	int SetNowActionLine(int nNowAction);
	void InsertActionLine(int nNowLineNum);
	void RemoveActionLine(int nNowLineNum);
	void ModifyActionLine(int nNowLineNum);
	void RefreshActionLine(int nNowLineNum);


private:
	// 	int m_recentActionLine;
public:
	virtual void ShowPane(bool bShow);

private:
	void OnLbnSelchangeList(void);
public:
	/*void SetHScroll(void);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);*/
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	BOOL m_bInited;
	int InitAction(void);

	//	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//afx_msg void OnDestroy();
};
