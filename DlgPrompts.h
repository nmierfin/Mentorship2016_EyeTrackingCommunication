#pragma once
#include "afxwin.h"
#include <vector>
// CDlgPrompts dialog
using namespace std;

class CDlgPrompts : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPrompts)

public:
	CDlgPrompts(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPrompts();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_PROMPTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedQuestion1();
	afx_msg void OnBnClickedAnswer1();
	afx_msg void OnBnClickedQuestion();
	
	CButton m_btnHowAreYou;
	CButton m_bthImFeelingGood;
	CButton m_btnPasta;
	CButton m_btnRepositionMe;
	CButton m_btnHowsTheWeather;
	CButton m_btnImFeelingBad;
	CButton m_btnRice;
	CButton m_btnBathroomPlease;
	CButton m_btnWhatAmIEating;
	CButton m_btnThankYou;
	CButton m_btnPudding;
	CButton m_btnCombMyHair;
	CButton m_btnWhatIsYourName;
	CButton m_btnYoureWelcome;
	CButton m_btnMilk;
	CButton m_btnBrushMyTeeth;
	CButton m_btnWhatDidtheDoctorSay;
	CButton m_btnYes;
	CButton m_btnJuice;
	CButton m_btnItchy;
	CButton m_btnWhatsWrong;
	CButton m_btnNo;
	CButton m_btnWater;
	CButton m_btnTakeMeForAWalk;
	CButton m_btnExit;
	vector <CRect> m_vPromptButtons;
	void GetPromptButtonCrd();
	afx_msg void OnBnClickedExit();
	void* m_pParent2;
	afx_msg void OnBnClickedAnswer();
	afx_msg void OnBnClickedFood();
	afx_msg void OnBnClickedNeeds();
	afx_msg void OnBnClickedQuestion2();
	afx_msg void OnBnClickedAnswer2();
	afx_msg void OnBnClickedFood2();
	afx_msg void OnBnClickedNeeds2();
	afx_msg void OnBnClickedQuestion3();
	afx_msg void OnBnClickedAnswer3();
	afx_msg void OnBnClickedFood3();
	afx_msg void OnBnClickedNeeds3();
	afx_msg void OnBnClickedQuestion4();
	afx_msg void OnBnClickedAnswer4();
	afx_msg void OnBnClickedFood4();
	afx_msg void OnBnClickedNeeds4();
	afx_msg void OnBnClickedQuestion5();
	afx_msg void OnBnClickedAnswer5();
	afx_msg void OnBnClickedFood5();
	afx_msg void OnBnClickedNeeds5();
	afx_msg void OnBnClickedQuestion6();
	afx_msg void OnBnClickedAnswer6();
	afx_msg void OnBnClickedFood6();
	afx_msg void OnBnClickedNeeds6();
};
