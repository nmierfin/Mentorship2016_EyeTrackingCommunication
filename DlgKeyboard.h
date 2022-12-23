#pragma once
#include "afxwin.h"
#include <vector>
// CDlgKeyboard dialog
using namespace std;

class CDlgKeyboard : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgKeyboard)

public:
	CDlgKeyboard(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgKeyboard();
	CString word;
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_KEYBOARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMenu();
	afx_msg void OnBnClickedButtonQ();
	afx_msg void OnBnClickedButtonSpace();
	CButton m_btnSpace;
	CButton m_btnQ;
	CButton m_btnW;
	CButton m_btnE;
	CButton m_btnR;
	CButton m_btnT;
	CButton m_btnY;
	CButton m_btnU;
	CButton m_btnI;
	CButton m_btnO;
	CButton m_btnP;
	CButton m_btnA;
	CButton m_btnS;
	CButton m_btnD;
	CButton m_btnF;
	CButton m_btnG;
	CButton m_btnH;
	CButton m_btnJ;
	CButton m_btnK;
	CButton m_btnL;
	CButton m_btnZ;
	CButton m_btnX;
	CButton m_btnC;
	CButton m_btnV;
	CButton m_btnB;
	CButton m_btnN;
	CButton m_btnM;
	CButton m_btnSpeak;
	CButton m_btnPeriod;
	CButton m_btnMenu;
	CButton m_btnExit;
	void GetKeyboardButtonCrd();
	vector <CRect> m_vKeyboardButtonCrd;
	afx_msg void OnBnClickedButtonW();
	afx_msg void OnBnClickedCancel();
	void* m_pParent;
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonR();
	afx_msg void OnBnClickedButtonT();
	afx_msg void OnBnClickedButtonY();
	afx_msg void OnBnClickedButtonU();
	afx_msg void OnBnClickedButtonI();
	afx_msg void OnBnClickedButtonO();
	afx_msg void OnBnClickedButtonP();
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonS();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonF();
	afx_msg void OnBnClickedButtonG();
	afx_msg void OnBnClickedButtonH();
	afx_msg void OnBnClickedButtonJ();
	afx_msg void OnBnClickedButtonK();
	afx_msg void OnBnClickedButtonL();
	afx_msg void OnBnClickedButtonZ();
	afx_msg void OnBnClickedButtonX();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonV();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonN();
	afx_msg void OnBnClickedButtonM();
	afx_msg void OnBnClickedButtonPeriod();
	afx_msg void OnEnChangeTextbox();
	CString m_txtDisplayBox;
	afx_msg void OnBnClickedButtonSpeak();
};

