#pragma once
class CWndStatic : public CStatic 
{
	DECLARE_DYNAMIC(CWndStatic)
public:
	CWndStatic();
	virtual ~CWndStatic();

protected:
	DECLARE_MESSAGE_MAP()
	
public:
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CFont  m_font; 
	int  m_nfontSize;
	BOOL m_bTran; //Í¸Ã÷Ä£Ê½
	COLORREF m_crText;
	COLORREF m_crBackColor;
public :
	void SetColor(COLORREF color);
	void SetBKColor(COLORREF color);
	void SetTransparent(BOOL bTran);
	
	
};

