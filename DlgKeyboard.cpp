// DlgKeyboard.cpp : implementation file
//

#include "stdafx.h"
#include "Mentorship 2016.h"
#include "DlgKeyboard.h"
#include "afxdialogex.h"
#include "Mentorship 2016Dlg.h"
#include <sapi.h>

// CDlgKeyboard dialog

IMPLEMENT_DYNAMIC(CDlgKeyboard, CDialogEx)


CDlgKeyboard::CDlgKeyboard(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_KEYBOARD, pParent)
	, m_pParent(NULL)
	, m_txtDisplayBox(_T(""))
{

}

CDlgKeyboard::~CDlgKeyboard()
{
}

void CDlgKeyboard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_Space, m_btnSpace);
	DDX_Control(pDX, IDC_BUTTON_Q, m_btnQ);
	DDX_Control(pDX, IDC_BUTTON_W, m_btnW);
	DDX_Control(pDX, IDC_BUTTON_E, m_btnE);
	DDX_Control(pDX, IDC_BUTTON_R, m_btnR);
	DDX_Control(pDX, IDC_BUTTON_T, m_btnT);
	DDX_Control(pDX, IDC_BUTTON_Y, m_btnY);
	DDX_Control(pDX, IDC_BUTTON_U, m_btnU);
	DDX_Control(pDX, IDC_BUTTON_I, m_btnI);
	DDX_Control(pDX, IDC_BUTTON_O, m_btnO);
	DDX_Control(pDX, IDC_BUTTON_P, m_btnP);
	DDX_Control(pDX, IDC_BUTTON_A, m_btnA);
	DDX_Control(pDX, IDC_BUTTON_S, m_btnS);
	DDX_Control(pDX, IDC_BUTTON_D, m_btnD);
	DDX_Control(pDX, IDC_BUTTON_F, m_btnF);
	DDX_Control(pDX, IDC_BUTTON_G, m_btnG);
	DDX_Control(pDX, IDC_BUTTON_H, m_btnH);
	DDX_Control(pDX, IDC_BUTTON_J, m_btnJ);
	DDX_Control(pDX, IDC_BUTTON_K, m_btnK);
	DDX_Control(pDX, IDC_BUTTON_L, m_btnL);
	DDX_Control(pDX, IDC_BUTTON_Z, m_btnZ);
	DDX_Control(pDX, IDC_BUTTON_X, m_btnX);
	DDX_Control(pDX, IDC_BUTTON_C, m_btnC);
	DDX_Control(pDX, IDC_BUTTON_V, m_btnV);
	DDX_Control(pDX, IDC_BUTTON_B, m_btnB);
	DDX_Control(pDX, IDC_BUTTON_N, m_btnN);
	DDX_Control(pDX, IDC_BUTTON_M, m_btnM);
	DDX_Control(pDX, IDC_BUTTON_Speak, m_btnSpeak);
	DDX_Control(pDX, IDC_BUTTON_Period, m_btnPeriod);
	DDX_Control(pDX, BTN_MENU, m_btnMenu);
	DDX_Control(pDX, IDCANCEL, m_btnExit);
	DDX_Text(pDX, TXT_DISPLAYBOX, m_txtDisplayBox);
}


BEGIN_MESSAGE_MAP(CDlgKeyboard, CDialogEx)
	ON_BN_CLICKED(BTN_MENU, &CDlgKeyboard::OnBnClickedMenu)
	ON_BN_CLICKED(IDC_BUTTON_Q, &CDlgKeyboard::OnBnClickedButtonQ)
	ON_BN_CLICKED(IDC_BUTTON_Space, &CDlgKeyboard::OnBnClickedButtonSpace)
	ON_BN_CLICKED(IDC_BUTTON_W, &CDlgKeyboard::OnBnClickedButtonW)
	ON_BN_CLICKED(IDCANCEL, &CDlgKeyboard::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_E, &CDlgKeyboard::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_R, &CDlgKeyboard::OnBnClickedButtonR)
	ON_BN_CLICKED(IDC_BUTTON_T, &CDlgKeyboard::OnBnClickedButtonT)
	ON_BN_CLICKED(IDC_BUTTON_Y, &CDlgKeyboard::OnBnClickedButtonY)
	ON_BN_CLICKED(IDC_BUTTON_U, &CDlgKeyboard::OnBnClickedButtonU)
	ON_BN_CLICKED(IDC_BUTTON_I, &CDlgKeyboard::OnBnClickedButtonI)
	ON_BN_CLICKED(IDC_BUTTON_O, &CDlgKeyboard::OnBnClickedButtonO)
	ON_BN_CLICKED(IDC_BUTTON_P, &CDlgKeyboard::OnBnClickedButtonP)
	ON_BN_CLICKED(IDC_BUTTON_A, &CDlgKeyboard::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_S, &CDlgKeyboard::OnBnClickedButtonS)
	ON_BN_CLICKED(IDC_BUTTON_D, &CDlgKeyboard::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_F, &CDlgKeyboard::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_G, &CDlgKeyboard::OnBnClickedButtonG)
	ON_BN_CLICKED(IDC_BUTTON_H, &CDlgKeyboard::OnBnClickedButtonH)
	ON_BN_CLICKED(IDC_BUTTON_J, &CDlgKeyboard::OnBnClickedButtonJ)
	ON_BN_CLICKED(IDC_BUTTON_K, &CDlgKeyboard::OnBnClickedButtonK)
	ON_BN_CLICKED(IDC_BUTTON_L, &CDlgKeyboard::OnBnClickedButtonL)
	ON_BN_CLICKED(IDC_BUTTON_Z, &CDlgKeyboard::OnBnClickedButtonZ)
	ON_BN_CLICKED(IDC_BUTTON_X, &CDlgKeyboard::OnBnClickedButtonX)
	ON_BN_CLICKED(IDC_BUTTON_C, &CDlgKeyboard::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_V, &CDlgKeyboard::OnBnClickedButtonV)
	ON_BN_CLICKED(IDC_BUTTON_B, &CDlgKeyboard::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_N, &CDlgKeyboard::OnBnClickedButtonN)
	ON_BN_CLICKED(IDC_BUTTON_M, &CDlgKeyboard::OnBnClickedButtonM)
	ON_BN_CLICKED(IDC_BUTTON_Period, &CDlgKeyboard::OnBnClickedButtonPeriod)
	ON_EN_CHANGE(TEXTBOX, &CDlgKeyboard::OnEnChangeTextbox)
	ON_BN_CLICKED(IDC_BUTTON_Speak, &CDlgKeyboard::OnBnClickedButtonSpeak)
END_MESSAGE_MAP()


// CDlgKeyboard message handlers


void CDlgKeyboard::OnBnClickedMenu()
{
	if (word != "")
	{
		word = word.Left(word.GetLength() - 1);
	}
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonQ()
{
	word += "q";
	m_txtDisplayBox = word; 
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonSpace()
{
	word += " ";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::GetKeyboardButtonCrd()
{
	CRect test;
	m_btnQ.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnW.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnE.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnR.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnT.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnY.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnU.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnI.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnO.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnP.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnA.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnS.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnD.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnF.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnG.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnH.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnJ.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnK.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnL.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnZ.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnX.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnC.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnV.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnB.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnN.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnM.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnSpace.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnPeriod.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnSpeak.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnPeriod.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnMenu.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
	m_btnExit.GetWindowRect(&test);
	m_vKeyboardButtonCrd.push_back(test);
}


void CDlgKeyboard::OnBnClickedButtonW()
{
	word += "w";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	((CMentorship2016Dlg*)m_pParent)->screenindex = 0;
	((CMentorship2016Dlg*)m_pParent)->m_flagKeyboardOpen = 0;
	CDialogEx::OnCancel();
}


void CDlgKeyboard::OnBnClickedButtonE()
{
	word += "e";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonR()
{
	word += "r";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonT()
{
	word += "t";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonY()
{
	word += "y";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonU()
{
	word += "u";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}
void CDlgKeyboard::OnBnClickedButtonI()
{
	word += "i";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonO()
{
	word += "o";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonP()
{
	word += "p";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonA()
{
	word += "a";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonS()
{
	word += "s";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonD()
{
	word += "d";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonF()
{
	word += "f";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonG()
{
	word += "g";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonH()
{
	word += "h";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonJ()
{
	word += "j";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonK()
{
	word += "k";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonL()
{
	word += "l";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonZ()
{
	word += "z";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonX()
{
	word += "x";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonC()
{
	word += "c";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}

void CDlgKeyboard::OnBnClickedButtonV()
{
	word += "v";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonB()
{
	word += "b";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonN()
{
	word += "n";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonM()
{
	word += "m";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnBnClickedButtonPeriod()
{
	word += ".";
	m_txtDisplayBox = word;
	UpdateData(FALSE);
}


void CDlgKeyboard::OnEnChangeTextbox()
{
	
}


void CDlgKeyboard::OnBnClickedButtonSpeak()
{
	ISpVoice * pVoice = NULL;
	
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize(); 
	
}
