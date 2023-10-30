
// ocx32nnDlg.h: 헤더 파일
//

#pragma once
#include "CAUTHOCXCTRL1.h"
#include "ButtonST.h"

// Cocx32nnDlg 대화 상자
class Cocx32nnDlg : public CDialogEx
{
// 생성입니다.
public:
	Cocx32nnDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CString m_token;
	CButtonST m_imgFaceAuth;
	CButtonST m_imgMobileFaceAuth;
	CButtonST m_imgMobileOTPAuth;
	CButtonST m_imgMobileQRAuth;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OCX32NN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CAUTHOCXCTRL1 m_ocx;
	afx_msg void OnBnClickedbtnpcfaceauth();
	afx_msg void OnBnClickedbtnmobilefaceauth();
	afx_msg void OnBnClickedbtnotp();
	afx_msg void OnBnClickedbtnqr();
	afx_msg void OnBnClickedLogin();
};
