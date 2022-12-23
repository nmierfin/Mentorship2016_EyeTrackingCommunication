// DlgPrompts.cpp : implementation file
//

#include "stdafx.h"
#include "Mentorship 2016.h"
#include "DlgPrompts.h"
#include "afxdialogex.h"
#include "Mentorship 2016Dlg.h"
#include <sapi.h>

// CDlgPrompts dialog

IMPLEMENT_DYNAMIC(CDlgPrompts, CDialogEx)

CDlgPrompts::CDlgPrompts(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_PROMPTS, pParent)
	, m_pParent2(NULL)
{
}

CDlgPrompts::~CDlgPrompts()
{
}

void CDlgPrompts::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, BTN_QUESTION, m_btnHowAreYou);
	DDX_Control(pDX, BTN_ANSWER, m_bthImFeelingGood);
	DDX_Control(pDX, BTN_FOOD, m_btnPasta);
	DDX_Control(pDX, BTN_NEEDS, m_btnRepositionMe);
	DDX_Control(pDX, BTN_QUESTION2, m_btnHowsTheWeather);
	DDX_Control(pDX, BTN_ANSWER2, m_btnImFeelingBad);
	DDX_Control(pDX, BTN_FOOD2, m_btnRice);
	DDX_Control(pDX, BTN_NEEDS2, m_btnBathroomPlease);
	DDX_Control(pDX, BTN_QUESTION3, m_btnWhatAmIEating);
	DDX_Control(pDX, BTN_ANSWER3, m_btnThankYou);
	DDX_Control(pDX, BTN_FOOD3, m_btnPudding);
	DDX_Control(pDX, BTN_NEEDS3, m_btnCombMyHair);
	DDX_Control(pDX, BTN_QUESTION4, m_btnWhatIsYourName);
	DDX_Control(pDX, BTN_ANSWER4, m_btnYoureWelcome);
	DDX_Control(pDX, BTN_FOOD4, m_btnMilk);
	DDX_Control(pDX, BTN_NEEDS4, m_btnBrushMyTeeth);
	DDX_Control(pDX, BTN_QUESTION5, m_btnWhatDidtheDoctorSay);
	DDX_Control(pDX, BTN_ANSWER5, m_btnYes);
	DDX_Control(pDX, BTN_FOOD5, m_btnJuice);
	DDX_Control(pDX, BTN_NEEDS5, m_btnItchy);
	DDX_Control(pDX, BTN_QUESTION6, m_btnWhatsWrong);
	DDX_Control(pDX, BTN_ANSWER6, m_btnNo);
	DDX_Control(pDX, BTN_FOOD6, m_btnWater);
	DDX_Control(pDX, BTN_NEEDS6, m_btnTakeMeForAWalk);
	DDX_Control(pDX, IDEXIT, m_btnExit);
}


BEGIN_MESSAGE_MAP(CDlgPrompts, CDialogEx)
	ON_BN_CLICKED(BTN_QUESTION, &CDlgPrompts::OnBnClickedQuestion)
	ON_BN_CLICKED(IDEXIT, &CDlgPrompts::OnBnClickedExit)
	ON_BN_CLICKED(BTN_ANSWER, &CDlgPrompts::OnBnClickedAnswer)
	ON_BN_CLICKED(BTN_FOOD, &CDlgPrompts::OnBnClickedFood)
	ON_BN_CLICKED(BTN_NEEDS, &CDlgPrompts::OnBnClickedNeeds)
	ON_BN_CLICKED(BTN_QUESTION2, &CDlgPrompts::OnBnClickedQuestion2)
	ON_BN_CLICKED(BTN_ANSWER2, &CDlgPrompts::OnBnClickedAnswer2)
	ON_BN_CLICKED(BTN_FOOD2, &CDlgPrompts::OnBnClickedFood2)
	ON_BN_CLICKED(BTN_NEEDS2, &CDlgPrompts::OnBnClickedNeeds2)
	ON_BN_CLICKED(BTN_QUESTION3, &CDlgPrompts::OnBnClickedQuestion3)
	ON_BN_CLICKED(BTN_ANSWER3, &CDlgPrompts::OnBnClickedAnswer3)
	ON_BN_CLICKED(BTN_FOOD3, &CDlgPrompts::OnBnClickedFood3)
	ON_BN_CLICKED(BTN_NEEDS3, &CDlgPrompts::OnBnClickedNeeds3)
	ON_BN_CLICKED(BTN_QUESTION4, &CDlgPrompts::OnBnClickedQuestion4)
	ON_BN_CLICKED(BTN_ANSWER4, &CDlgPrompts::OnBnClickedAnswer4)
	ON_BN_CLICKED(BTN_FOOD4, &CDlgPrompts::OnBnClickedFood4)
	ON_BN_CLICKED(BTN_NEEDS4, &CDlgPrompts::OnBnClickedNeeds4)
	ON_BN_CLICKED(BTN_QUESTION5, &CDlgPrompts::OnBnClickedQuestion5)
	ON_BN_CLICKED(BTN_ANSWER5, &CDlgPrompts::OnBnClickedAnswer5)
	ON_BN_CLICKED(BTN_FOOD5, &CDlgPrompts::OnBnClickedFood5)
	ON_BN_CLICKED(BTN_NEEDS5, &CDlgPrompts::OnBnClickedNeeds5)
	ON_BN_CLICKED(BTN_QUESTION6, &CDlgPrompts::OnBnClickedQuestion6)
	ON_BN_CLICKED(BTN_ANSWER6, &CDlgPrompts::OnBnClickedAnswer6)
	ON_BN_CLICKED(BTN_FOOD6, &CDlgPrompts::OnBnClickedFood6)
	ON_BN_CLICKED(BTN_NEEDS6, &CDlgPrompts::OnBnClickedNeeds6)
END_MESSAGE_MAP()



void CDlgPrompts::GetPromptButtonCrd()
{
	CRect test;
	m_btnHowAreYou.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_bthImFeelingGood.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnPasta.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnRepositionMe.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnHowsTheWeather.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnImFeelingBad.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnRice.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnBathroomPlease.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnWhatAmIEating.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnThankYou.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnPudding.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnCombMyHair.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnWhatIsYourName.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnYoureWelcome.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnMilk.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnBrushMyTeeth.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnWhatDidtheDoctorSay.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnYes.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnJuice.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnItchy.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnWhatsWrong.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnNo.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnWater.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnTakeMeForAWalk.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
	m_btnExit.GetWindowRect(&test);
	m_vPromptButtons.push_back(test);
}


void CDlgPrompts::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	((CMentorship2016Dlg*)m_pParent2)->screenindex = 0;
	((CMentorship2016Dlg*)m_pParent2)->m_flagKeyboardOpen = 0;
	CDialogEx::OnCancel();
}

void CDlgPrompts::OnBnClickedQuestion1() 
{
}
void CDlgPrompts::OnBnClickedAnswer1()
{
}
void CDlgPrompts::OnBnClickedQuestion() 
{
	CString word;
	word = "How are you?";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}

void CDlgPrompts::OnBnClickedAnswer()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "I'm feeling good";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedFood()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "pasta";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedNeeds()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "reposition me";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedQuestion2()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "How's the weather";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedAnswer2()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "I'm feeling bad.";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedFood2()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Rice";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedNeeds2()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Bathroom Please";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedQuestion3()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "What am I eating?";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedAnswer3()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Thanks You";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedFood3()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Pudding";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedNeeds3()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Comb my hair";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedQuestion4()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "What is your name.";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedAnswer4()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "You're Welcome";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedFood4()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Milk";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedNeeds4()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "Brush my teeth";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedQuestion5()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "What did the doctor say.";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedAnswer5()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "yes";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedFood5()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "juice";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedNeeds5()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "I feel itchy";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedQuestion6()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "What's wrong?";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedAnswer6()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "No";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedFood6()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "water";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}


void CDlgPrompts::OnBnClickedNeeds6()
{
	// TODO: Add your control notification handler code here
	CString word;
	word = "take me for a walk";
	ISpVoice * pVoice = NULL;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	hr = pVoice->Speak(word, 0, NULL);
	pVoice->Release();
	pVoice = NULL;

	::CoUninitialize();
}
