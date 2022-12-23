
// Mentorship 2016Dlg.h : header file
//

#pragma once
#include "gdiplustypes.h"
#include "atltypes.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/photo/photo.hpp>
#include "DlgKeyboard.h"
#include "DlgPrompts.h"
#include "afxwin.h"

#define LEFT_EYE_CASCADE_NAME "C:\\opencv\\sources\\data\\haarcascades_cuda\\haarcascade_lefteye_2splits.xml" 

using namespace cv;
using namespace std;

// CMentorship2016Dlg dialog
class CMentorship2016Dlg : public CDialogEx
{
// Construction
public:
	CMentorship2016Dlg(CWnd* pParent = NULL);	// standard constructor
	~CMentorship2016Dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENTORSHIP2016_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	Mat m_matImage;
	VideoCapture m_cap;
	CascadeClassifier m_lefteye_cascade;
	vector<Rect> m_eyes;
	Mat m_eyeROI;
	Rect m_rectLeftEye;
	Mat m_crop;
	int m_rows;
	int m_colms;
	Size m_eyeboxsize;
	double m_alpha;
	int m_beta;
	Mat m_Test;
	int ddepth;
	Mat kernelsharpen;
	Point anchor;
	double delta;
	Mat element;
	Mat element2;
	int erosion_elem;
	int erosion_size;
	int dilation_elem;
	int dilation_size;
	Ptr<SimpleBlobDetector> detector;
	cv::SimpleBlobDetector::Params params;
	std::vector<KeyPoint> keypoints;
	afx_msg void OnBnClickedCalibrate();
	CRect m_roi;
	afx_msg void OnBnClickedRun();
	CPoint m_center2;
	int const m_max_elem = 2;
	int const m_max_kernel_size = 10000000;
	int m_erosion_elem;
	int m_erosion_size;
	int m_dilation_elem;
	int m_dilation_size;
	CDlgKeyboard * m_pKeyboardDlg;
	CDlgPrompts * m_pPromptsDlg;
	Mat m_cropshow;
	int m_flagPromptsOpen;
	int m_flagKeyboardOpen;
	int screenindex;
	afx_msg void OnBnClickedKeyboard();
	afx_msg void OnBnClickedPrompts();
	afx_msg void OnBnClickedExit();
	CButton m_btnPrompts;
	CButton m_btnKeyboard;
	CButton m_btnRun;
	CButton m_btnCalibrate;
	CButton m_btnExit;
	vector <CRect> m_vMainButtons;
	void GetMainButtonCrd();
	int XcoordinateOfMouse;
	int YcoordinateOfMouse;
	bool bRecordedEyeClosedTime = false;
	time_t timeEyeClosed;
	time_t timeEyeOpen;
	double seconds;
};
