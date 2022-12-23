
// Mentorship 2016Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mentorship 2016.h"
#include "Mentorship 2016Dlg.h"
#include "afxdialogex.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace cv;
using namespace std;
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMentorship2016Dlg dialog



CMentorship2016Dlg::CMentorship2016Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MENTORSHIP2016_DIALOG, pParent)
	, m_rows(0)
	, m_colms(0)
	, m_alpha(0)
	, m_beta(0)
	, ddepth(0)
	, anchor(0)
	, delta(0)
	, erosion_elem(0)
	, erosion_size(0)
	, dilation_elem(0)
	, dilation_size(0)
	, m_center2(0)
	, m_max_elem(0)
	, m_max_kernel_size(0)
	, m_erosion_elem(0)
	, m_erosion_size(0)
	, m_dilation_elem(0)
	, m_dilation_size(0)
	, bRecordedEyeClosedTime(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pKeyboardDlg = NULL;
	m_pPromptsDlg = NULL;

}

CMentorship2016Dlg::~CMentorship2016Dlg()
{
	if (m_pKeyboardDlg) {
		m_pKeyboardDlg->DestroyWindow();
		delete m_pKeyboardDlg;
		m_pKeyboardDlg = NULL;
	}

	if (m_pPromptsDlg) {
		m_pPromptsDlg->DestroyWindow();
		delete m_pPromptsDlg;
		m_pPromptsDlg = NULL;
	}
}

void CMentorship2016Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, BTN_PROMPTS, m_btnPrompts);
	DDX_Control(pDX, BTN_KEYBOARD, m_btnKeyboard);
	DDX_Control(pDX, BTN_RUN, m_btnRun);
	DDX_Control(pDX, BTN_CALIBRATION, m_btnCalibrate);
	DDX_Control(pDX, IDEXIT, m_btnExit);
}

BEGIN_MESSAGE_MAP(CMentorship2016Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMentorship2016Dlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_BN_CLICKED(BTN_CALIBRATION, &CMentorship2016Dlg::OnBnClickedCalibrate)
	ON_BN_CLICKED(BTN_RUN, &CMentorship2016Dlg::OnBnClickedRun)
	ON_BN_CLICKED(BTN_KEYBOARD, &CMentorship2016Dlg::OnBnClickedKeyboard)
	ON_BN_CLICKED(BTN_PROMPTS, &CMentorship2016Dlg::OnBnClickedPrompts)
	ON_BN_CLICKED(IDEXIT, &CMentorship2016Dlg::OnBnClickedExit)
END_MESSAGE_MAP()


// CMentorship2016Dlg message handlers

BOOL CMentorship2016Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MAXIMIZE);

	// TODO: Add extra initialization here
	m_cap.open(0);
	if (m_cap.isOpened() == false)
	{
		MessageBox(_T("Unable to initialize camera."), _T("Camera not found."), MB_OK | MB_ICONERROR);
	}
	else 
	{
		if (!m_lefteye_cascade.load(LEFT_EYE_CASCADE_NAME)) { printf("--(!)Error loading\n"); return -1; }
		ddepth = -1;
		kernelsharpen = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
		anchor = Point(-1, -1);
		delta = 0;
		m_erosion_elem = 2;
		m_erosion_size = 10;
		m_dilation_elem = 0;
		m_dilation_size = 1;
		m_alpha = 1;
		m_beta = 50;
		element = getStructuringElement(MORPH_ELLIPSE, Size(2 * m_dilation_size + 1, 2 * m_dilation_size + 1), Point(m_dilation_size, m_dilation_size));
		element2 = getStructuringElement(MORPH_ELLIPSE, Size(2 * m_erosion_size + 1, 2 * m_erosion_size + 1), Point(m_erosion_size, m_erosion_size));
		params.minThreshold = 1;
		params.maxThreshold = 10000;
		// Filter by area
		params.filterByArea = true;
		params.minArea = 1;
		// Filter by Circularity
		params.filterByCircularity = true;
		params.minCircularity = 0;
		params.filterByConvexity = true;
		params.minConvexity = 0;
		// Filter by Inertia
		params.filterByInertia = true;
		params.minInertiaRatio = 0;
		detector = SimpleBlobDetector::create(params);
	}
	CRect RectMainWindow;
	CRect RectKeyboardWindow;
	CRect RectPromptsWindow;
	int xcoorofKeyboard;
	int ycoorofKeyboard;
	int xcoorofprompts;
	int ycoorofprompts;
	GetClientRect(&RectMainWindow);
	m_pKeyboardDlg = new CDlgKeyboard;
	m_pKeyboardDlg->Create(DIALOG_KEYBOARD);
	m_pKeyboardDlg->GetClientRect(&RectKeyboardWindow);
	xcoorofKeyboard = (RectMainWindow.Width() / 2) - (RectKeyboardWindow.Width() / 2);
	ycoorofKeyboard = (RectMainWindow.Height() / 2)  - (RectKeyboardWindow.Height() / 2);
	m_pKeyboardDlg->SetWindowPos(&CWnd::wndTopMost, xcoorofKeyboard, ycoorofKeyboard, 500, 200, SWP_NOSIZE);
	m_pKeyboardDlg->m_pParent = this;
	m_pKeyboardDlg->ShowWindow(SW_HIDE);

	m_pPromptsDlg = new CDlgPrompts;
	m_pPromptsDlg->Create(DIALOG_PROMPTS);
	m_pPromptsDlg->GetClientRect(&RectPromptsWindow);
	xcoorofprompts = (RectMainWindow.Width() / 2) - (RectPromptsWindow.Width() / 2);
	ycoorofprompts = (RectMainWindow.Height() / 2) - (RectPromptsWindow.Height() / 2);
	m_pPromptsDlg->SetWindowPos(&CWnd::wndTopMost, xcoorofprompts, ycoorofprompts, 500, 200, SWP_NOSIZE);
	m_pPromptsDlg->m_pParent2 = this;
	m_pPromptsDlg->ShowWindow(SW_HIDE);
	
	GetMainButtonCrd();
	m_pPromptsDlg->GetPromptButtonCrd();
	m_pKeyboardDlg->GetKeyboardButtonCrd();
	m_flagPromptsOpen = 0;
	m_flagKeyboardOpen = 0;
	screenindex = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMentorship2016Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMentorship2016Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMentorship2016Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMentorship2016Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}//main


void CMentorship2016Dlg::OnTimer(UINT_PTR nIDEvent)
{
	
	// TODO: Add your message handler code here and/or call default
	m_cap >> m_matImage; 
	m_lefteye_cascade.detectMultiScale(m_matImage, m_eyes, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	if (m_eyes.size() == 1)
	{
		m_eyeROI = m_matImage(m_eyes[0]);
		m_rectLeftEye.x = cvRound(m_eyes[0].width * 0.2);
		m_rectLeftEye.y = cvRound(m_eyes[0].height *0.35);
		m_rectLeftEye.width = cvRound(m_eyes[0].width / 1.8);
		m_rectLeftEye.height = cvRound(m_eyes[0].height / 2);
		m_eyeROI(m_rectLeftEye).copyTo(m_crop);
		resize(m_crop, m_crop, Size(170, 100));
		m_rows = m_crop.rows;
		m_colms = m_crop.cols;
		m_eyeboxsize.height = m_rows;
		m_eyeboxsize.width = m_colms;
		for (int y = 0; y < m_crop.rows; y++)
		{
			for (int x = 0; x < m_crop.cols; x++)
			{
				for (int c = 0; c < 3; c++)
				{
					m_crop.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(m_alpha * (m_crop.at<Vec3b>(y, x)[c]) + m_beta);
				}
			}
		}
		//Filters image
		cvtColor(m_crop, m_crop, CV_BGR2GRAY);
		m_crop.copyTo(m_Test);
		fastNlMeansDenoising(m_crop, m_crop, 30.0, 7, 5);
		GaussianBlur(m_crop, m_crop, Size(0, 0), 5);
		filter2D(m_crop, m_crop, ddepth, kernelsharpen, anchor, delta, BORDER_DEFAULT);
		bitwise_not(m_crop, m_crop);
		filter2D(m_Test, m_Test, ddepth, kernelsharpen, anchor, delta, BORDER_DEFAULT);
		//Draw eye detection circles on main image
		Point center_threshold(m_eyes[0].x + m_eyes[0].width*0.5, m_eyes[0].y + m_eyes[0].height*0.5);
		int radius = cvRound((m_eyes[0].width + m_eyes[0].height) / 5);
		circle(m_matImage, center_threshold, radius, Scalar(255, 0, 0), 4, 8, 0);
		//Blob-Detection
		dilate(m_crop, m_crop, element);
		erode(m_crop, m_crop, element2);
		detector->detect(m_crop, keypoints);
		if (keypoints.size() > 0)
		{
			//drawKeypoints(m_cropshow, keypoints, m_cropshow, Scalar(255, 255, 0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
			Point threshold_point1(m_roi.left, m_roi.bottom);
			Point threshold_point2(m_roi.right, m_roi.top);
			//Point kernelsharpenthreshold_point2(roi.x + roi.width,roi.y - roi.height);
			rectangle(m_crop, threshold_point1, threshold_point2, Scalar(255, 0, 0), 2, 8, 0);
			rectangle(m_Test, threshold_point1, threshold_point2, Scalar(255, 0, 0), 2, 8, 0);
			Point verticalcrosshairstart(keypoints[0].pt.x, keypoints[0].pt.y - 5);
			Point verticalcrosshairend(keypoints[0].pt.x, keypoints[0].pt.y + 5);
			Point horizontalcrosshairstart(keypoints[0].pt.x + 5, keypoints[0].pt.y);
			Point horizontalcrosshairend(keypoints[0].pt.x - 5, keypoints[0].pt.y);
			line(m_crop, verticalcrosshairstart, verticalcrosshairend, Scalar(255, 255, 0), 1, 8, 0);
			line(m_crop, horizontalcrosshairstart, horizontalcrosshairend, Scalar(255, 255, 0), 1, 8, 0);
		}
		Mat AllDisplayedImages(m_matImage.rows + m_crop.rows, m_matImage.cols, CV_8UC3);
		cvtColor(AllDisplayedImages, AllDisplayedImages, CV_BGR2GRAY);
		cvtColor(m_matImage, m_matImage, CV_BGR2GRAY);
		m_matImage.copyTo(AllDisplayedImages(cv::Rect(0, m_crop.rows, m_matImage.cols, m_matImage.rows)));
		m_crop.copyTo(AllDisplayedImages(cv::Rect(0, 0, m_crop.cols, m_crop.rows)));
		m_Test.copyTo(AllDisplayedImages(cv::Rect(m_crop.cols, 0, m_Test.cols, m_Test.rows)));
		imshow("Eye_Track", AllDisplayedImages);
		if (keypoints.size() != 0)
		{
			if (keypoints[0].pt.x > m_roi.right)
			{
				if (screenindex != 0)
				{
					screenindex -= 1;
				}
			}
			else if (keypoints[0].pt.x < m_roi.left)
			{
				screenindex += 1;
			}
			if (m_flagPromptsOpen == 0 && m_flagKeyboardOpen == 0)
			{
				if (screenindex == m_vMainButtons.size()) 
				{
					screenindex = 0;
				}
				XcoordinateOfMouse = m_vMainButtons[screenindex].left + ((m_vMainButtons[screenindex].right - m_vMainButtons[screenindex].left) / 2);
				YcoordinateOfMouse = m_vMainButtons[screenindex].top +  ((m_vMainButtons[screenindex].bottom - m_vMainButtons[screenindex].top) / 2);
			}
			if (m_flagPromptsOpen == 1 && m_flagKeyboardOpen == 0)
			{
				if (screenindex == m_pPromptsDlg->m_vPromptButtons.size())
				{
					screenindex = 0;
				}
				XcoordinateOfMouse = m_pPromptsDlg->m_vPromptButtons[screenindex].left + ((m_pPromptsDlg->m_vPromptButtons[screenindex].right - m_pPromptsDlg->m_vPromptButtons[screenindex].left) / 2);
				YcoordinateOfMouse = m_pPromptsDlg->m_vPromptButtons[screenindex].top + ((m_pPromptsDlg->m_vPromptButtons[screenindex].bottom - m_pPromptsDlg->m_vPromptButtons[screenindex].top) / 2);
			}
			if (m_flagPromptsOpen == 0 && m_flagKeyboardOpen == 1)
			{
				if (screenindex == m_pKeyboardDlg->m_vKeyboardButtonCrd.size())
				{
					screenindex = 0;
				}
				XcoordinateOfMouse = m_pKeyboardDlg->m_vKeyboardButtonCrd[screenindex].left + ((m_pKeyboardDlg->m_vKeyboardButtonCrd[screenindex].right - m_pKeyboardDlg->m_vKeyboardButtonCrd[screenindex].left) / 2);
				YcoordinateOfMouse = m_pKeyboardDlg->m_vKeyboardButtonCrd[screenindex].top + ((m_pKeyboardDlg->m_vKeyboardButtonCrd[screenindex].bottom - m_pKeyboardDlg->m_vKeyboardButtonCrd[screenindex].top) / 2);
			}
			SetCursorPos(XcoordinateOfMouse, YcoordinateOfMouse);
		}
	}
	if (keypoints.size() == 0)
	{
		if (bRecordedEyeClosedTime == false)
		{
			timeEyeClosed = time(NULL);
			bRecordedEyeClosedTime = true;
		}
	}
	if (keypoints.size()>0 && bRecordedEyeClosedTime == true)
	{
		timeEyeOpen = time(NULL);
		seconds = difftime(timeEyeOpen, timeEyeClosed);
		if (seconds >= 2)
		{
			MOUSEINPUT click[2]{ { 0,0,0, MOUSEEVENTF_LEFTDOWN,0, NULL },
			{ 0,0,0, MOUSEEVENTF_LEFTUP,0, NULL } };
			INPUT mouse_click[2]{ { INPUT_MOUSE, click[0] },{ INPUT_MOUSE, click[1] } };
			SendInput(2, mouse_click, sizeof(mouse_click[0]));
		}
		bRecordedEyeClosedTime = false;
	}
	m_eyes.clear();
	keypoints.clear();
	CDialogEx::OnTimer(nIDEvent);
}


void CMentorship2016Dlg::OnBnClickedCalibrate()
{
	namedWindow("Test");
	float distance_from_y_axis;
	float distance_from_x_axis;
	// TODO: Add your control notification handler code here
	MessageBox(_T("Look at the center of the screen"));
	m_cap >> m_matImage;
	m_lefteye_cascade.detectMultiScale(m_matImage, m_eyes, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	if (m_eyes.size() == 1) 
	{
		m_eyeROI = m_matImage(m_eyes[0]);
		m_rectLeftEye.x = cvRound(m_eyes[0].width * 0.2);
		m_rectLeftEye.y = cvRound(m_eyes[0].height *0.35);
		m_rectLeftEye.width = cvRound(m_eyes[0].width / 1.8);
		m_rectLeftEye.height = cvRound(m_eyes[0].height / 2);
		m_eyeROI(m_rectLeftEye).copyTo(m_crop);
		resize(m_crop, m_crop, Size(170, 100));
		m_rows = m_crop.rows;
		m_colms = m_crop.cols;
		m_eyeboxsize.height = m_rows;
		m_eyeboxsize.width = m_colms;
		for (int y = 0; y < m_crop.rows; y++)
		{
			for (int x = 0; x < m_crop.cols; x++)
			{
				for (int c = 0; c < 3; c++)
				{
					m_crop.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(m_alpha * (m_crop.at<Vec3b>(y, x)[c]) + m_beta);
				}
			}
		}
		imshow("Test", m_crop);
		//Filters image
		cvtColor(m_crop, m_crop, CV_BGR2GRAY);
		m_crop.copyTo(m_Test);
		fastNlMeansDenoising(m_crop, m_crop, 30.0, 7, 5);
		GaussianBlur(m_crop, m_crop, Size(0, 0), 5);
		filter2D(m_crop, m_crop, ddepth, kernelsharpen, anchor, delta, BORDER_DEFAULT);
		bitwise_not(m_crop, m_crop);
		//Blob-Detection
		dilate(m_crop, m_crop, element);
		erode(m_crop, m_crop, element2);
		detector->detect(m_crop, keypoints);
		drawKeypoints(m_crop, keypoints, m_crop, Scalar(255, 255, 0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
        if (keypoints.size()>0)
        {
            distance_from_x_axis = cvRound(keypoints[0].pt.y);
            distance_from_y_axis = cvRound(keypoints[0].pt.x);
			//Calculate Threshold Box 
			m_roi.left = distance_from_y_axis - 18;
			m_roi.bottom = distance_from_x_axis + 14;
			m_roi.right = m_roi.left + 23;
			m_roi.top = m_roi.bottom - 15;
			keypoints.clear();
			destroyWindow("Test");
			MessageBox(_T("Calibration test complete, press run to start"));
        }
		else
		{
			MessageBox(_T("Eye was not detected, try again"));
		}
    }
	else if (m_eyes.size() > 1)
	{
		MessageBox(_T("More than one eye was detected"));
	}
	else 
	{
		MessageBox(_T("No eyes were detected."));
	}

}


void CMentorship2016Dlg::OnBnClickedRun()
{
	// TODO: Add your control notification handler code here
	namedWindow("Eye_Track");
	SetTimer(0, 30, NULL);
}



void CMentorship2016Dlg::OnBnClickedKeyboard()
{
	// TODO: Add your control notification handler code here
	screenindex = 0;
	m_flagKeyboardOpen = 1;
	m_pKeyboardDlg->ShowWindow(SW_SHOW);
}


void CMentorship2016Dlg::OnBnClickedPrompts()
{
	// TODO: Add your control notification handler code here
	screenindex = 0;
	m_flagPromptsOpen = 1;
	m_pPromptsDlg->ShowWindow(SW_SHOW);
}


void CMentorship2016Dlg::OnBnClickedExit()
{
	EndDialog(0);
}


void CMentorship2016Dlg::GetMainButtonCrd()
{
	CRect test;
	m_btnPrompts.GetWindowRect(&test);
	m_vMainButtons.push_back(test);
	m_btnKeyboard.GetWindowRect(&test);
	m_vMainButtons.push_back(test);
	m_btnRun.GetWindowRect(&test);
	m_vMainButtons.push_back(test);
	m_btnCalibrate.GetWindowRect(&test);
	m_vMainButtons.push_back(test);
	m_btnExit.GetWindowRect(&test);
	m_vMainButtons.push_back(test);
}

