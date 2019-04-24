#include "stdafx.h"
#include "CWndMyListBox.h"



IMPLEMENT_DYNAMIC(CMyListBox, CListBox)

CMyListBox::CMyListBox()
	: m_nHighLightLineNum(0)
	, m_nColHight(40)
	, m_nTextHight(18)
	, m_nLenItem(500)
{
	m_colorBackGround = RGB(128, 255, 255);
	m_colorTextColor = RGB(0, 24, 24);
	m_colorRoundRect = RGB(95, 210, 85);//RGB(0,24,24);
}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	//	ON_CONTROL_REFLECT(LBN_SELCHANGE, &CMyListBox::OnLbnSelchange)
	//ON_CONTROL_REFLECT(LBN_SELCHANGE, &CMyListBox::OnLbnSelchange)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//ON_WM_MBUTTONDBLCLK()
	//ON_WM_NCLBUTTONDBLCLK()
	//ON_WM_NCLBUTTONUP()
	//ON_WM_VSCROLL()
END_MESSAGE_MAP()



// CMyListBox message handlers



void CMyListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct /*lpDrawItemStruct*/)
{
	CString tmpString;
	// 	return;
	if (lpDrawItemStruct->itemID == 0xffffffff)
		return;


	// 	lpDrawItemStruct->rcItem.left = 0;
	// 	lpDrawItemStruct->rcItem.right = 500;


	COLORREF crBK[6] = {
		COLOR_ACT_NORMAL,
		COLOR_ACT_PILE,
		COLOR_ACT_INDI,
		COLOR_ACT_LABEL,
		COLOR_ACT_DEVI,
		COLOR_ACT_SPECIALPOINT,
	};


	ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);
	// 	LPCTSTR lpszText = (LPCTSTR) lpDrawItemStruct->itemData;	//when not choose has string
	CString lpszText;												//when  choose has string
	GetText(lpDrawItemStruct->itemID, lpszText);
	SpiltMyString(lpszText, tmpString);

	// 	ASSERT(lpszText != NULL);
	CDC dc /*= new CDC*/;

	dc.Attach(lpDrawItemStruct->hDC);

	// 	m_nLenItem = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left ;

	COLORREF crOldTextColor = dc.GetTextColor();
	COLORREF crOldBkColor = dc.GetBkColor();

	// If this item is selected, set the background color 
	// and the text color to appropriate values. Also, erase
	// rect by filling it with the background color.

	if ((lpDrawItemStruct->itemAction | ODA_SELECT) 
		&&(lpDrawItemStruct->itemState & ODS_SELECTED) )
	{
		//绘制已选择高亮
		dc.SetTextColor(RGB(255 - GetRValue(m_colorTextColor), 255 - GetGValue(m_colorTextColor), 255 - GetBValue(m_colorTextColor)));
		dc.SetBkColor(RGB(255 - GetRValue(m_colorBackGround), 255 - GetGValue(m_colorBackGround), 255 - GetBValue(m_colorBackGround)));
		dc.FillSolidRect(&lpDrawItemStruct->rcItem,
			RGB(255 - GetRValue(m_colorBackGround), 255 - GetGValue(m_colorBackGround), 255 - GetBValue(m_colorBackGround)));

	}
	else
	{
		
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, m_colorBackGround);
		dc.SetTextColor(m_colorTextColor);
	}

	
	lpDrawItemStruct->rcItem.left += 5;


	if (CString(lpszText).GetLength() > 40)
	{
		SetTextHight(16);
	}

	CFont         fnt;
	fnt.CreateFont(m_nTextHight, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, 0, 1, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("黑体"));
	// 	fnt.lfHeight = 24;

	CFont *pOldFont = dc.SelectObject(&fnt);

	SetTextHight(18);

	// 	pDC->DrawText(szTitle, -1, captionRect, DT_WORDBREAK | DT_CENTER | DT_CALCRECT);

	dc.DrawText(
		lpszText,
		CString(lpszText).GetLength(),
		&lpDrawItemStruct->rcItem,
		// 		DT_WORDBREAK | DT_CENTER | DT_CALCRECT);
		DT_LEFT | DT_SINGLELINE |/*DT_WORDBREAK|*/DT_VCENTER/*|DT_CALCRECT*/);

	dc.SelectObject(pOldFont);

	dc.SetTextColor(crOldTextColor);
	dc.SetBkColor(crOldBkColor);
	fnt.DeleteObject();

	dc.Detach();


	
	return;

}

// 描述菜单
void CMyListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct/*lpMeasureItemStruct*/)
{
	ASSERT(lpMeasureItemStruct->CtlType == ODT_LISTBOX);

	lpMeasureItemStruct->itemHeight = m_nColHight;

}

void CMyListBox::SetColHight(int colHight)
{
	m_nColHight = colHight;
}

void CMyListBox::SetBackGroundColor(COLORREF bgColor)
{
	m_colorBackGround = bgColor;
	m_colorRoundRect = RGB(255 - GetRValue(m_colorBackGround), 255 - GetGValue(m_colorBackGround), 255 - GetBValue(m_colorBackGround));
	m_colorTextColor = m_colorRoundRect;
}

void CMyListBox::SetTextColor(COLORREF textColor)
{
	m_colorTextColor = textColor;
}

void CMyListBox::ReplaceText(void)
{

}

void CMyListBox::SetTextHight(int nTextHight)
{
	m_nTextHight = nTextHight;
}

void CMyListBox::SetHighLightNum(int nHL)
{
	m_nHighLightLineNum = nHL;
}



void CMyListBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect   rect;
	GetClientRect(&rect);
	// 	rect = dc.m_ps.rcPaint;
	// 	dc.FillSolidRect(rect,RGB(0,0,0));

	CDC   MemDC;//内存DC 
	CBitmap   MemBmp;
	MemDC.CreateCompatibleDC(&dc);
	MemBmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	// 	MemBmp.CreateCompatibleBitmap(&dc, m_nLenItem, rect.Height());

	MemDC.SelectObject(&MemBmp);
	//这时创建的位图只是一张黑色的纸
	//先画上背景    
	// 	MemDC.FillSolidRect(rect, RGB(255, 255, 255));
	//再画上图形
	//这一句是调用默认的OnPaint(),把图形画在内存DC表上 
	DefWindowProc(WM_PAINT, (WPARAM)MemDC.m_hDC, (LPARAM)0);

	//输出 
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);
	// 	dc.BitBlt(0, 0, m_nLenItem, rect.Height(), &MemDC, 0, 0, SRCCOPY); 

	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CMyListBox::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));

	return TRUE;
	// 	return CListBox::OnEraseBkgnd(pDC);
}

void CMyListBox::SpiltMyString(CString& oString, CString& tmpString) //按'|'截成两段字符
{
	int n = oString.ReverseFind('|');
	if (n != 0xffffffff)
	{
		tmpString = oString.Right(oString.GetLength() - n);
		oString = oString.Left(n);
	}
}

void CMyListBox::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 	CListBox::OnLButtonDblClk(nFlags, point);
}

void CMyListBox::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

}

void CMyListBox::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	

}