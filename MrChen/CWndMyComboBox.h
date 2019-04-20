#pragma once
class CWndMyComboBox : public CComboBox
{
	DECLARE_DYNAMIC(CWndMyComboBox)
public:
	CWndMyComboBox();
	~CWndMyComboBox();

public :
	virtual  BOOL Create(DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT  nID);
protected:
	DECLARE_MESSAGE_MAP()


public:
	
private:
	int m_nID;
};

