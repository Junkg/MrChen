#ifndef CWndMyListBox_H
#define CWndMyListBox_H
#pragma once


#define COLOR_ACT_NORMAL	RGB(30,40,110)//   RGB(55,55,80) // 199,237,204  ����
#define COLOR_ACT_PILE		RGB(200,210,85) //�ѵ���ɫ  ��ɫ
// #define COLOR_ACT_INDI		RGB(80,80,0)
#define COLOR_ACT_LABEL		RGB(130,0,135)//��ת��ǩ  �ƺ�ɫ
#define COLOR_ACT_DEVI		RGB(30,80,55)//�ᶯ��
#define COLOR_ACT_INDI		RGB(0,80,123)
#define COLOR_ACT_SPECIALPOINT		RGB(58,88,128)


class CMyListBox : public CListBox
{
	DECLARE_DYNAMIC(CMyListBox)

public:
	CMyListBox();
	virtual ~CMyListBox();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct/*lpDrawItemStruct*/);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct/*lpMeasureItemStruct*/);

private:
	int m_nColHight;
	int m_nHighLightLineNum;
	int m_nTextHight;
	COLORREF m_colorBackGround;
	COLORREF m_colorTextColor;
	COLORREF m_colorRoundRect;


protected:
	DECLARE_MESSAGE_MAP()

public:
	void SetColHight(int colHight);
	void SetBackGroundColor(COLORREF bgColor);
	void SetTextColor(COLORREF textColor);
	void ReplaceText(void);
	void SetTextHight(int nTextHight);
	void SetHighLightNum(int nHL);
	//	afx_msg void OnLbnSelchange();
	//	afx_msg void OnLbnSelchange();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
private:
	void SpiltMyString(CString& oString, CString& tmpString);
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	//	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	//	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	int m_nLenItem;
	//	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	// 	void SetHScroll(void);
};

#endif 