
// ocx32nnDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ocx32nn.h"
#include "ocx32nnDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// Cocx32nnDlg 대화 상자



Cocx32nnDlg::Cocx32nnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OCX32NN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cocx32nnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AUTHOCXCTRL1, m_ocx);
	DDX_Control(pDX, IDC_btnPCFaceAuth, m_imgFaceAuth);
	DDX_Control(pDX, IDC_btnMobileFaceAuth, m_imgMobileFaceAuth);
	DDX_Control(pDX, IDC_btnOTP, m_imgMobileOTPAuth);
	DDX_Control(pDX, IDC_btnQR, m_imgMobileQRAuth);
}

BEGIN_MESSAGE_MAP(Cocx32nnDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Cocx32nnDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cocx32nnDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_btnPCFaceAuth, &Cocx32nnDlg::OnBnClickedbtnpcfaceauth)
	ON_BN_CLICKED(IDC_btnMobileFaceAuth, &Cocx32nnDlg::OnBnClickedbtnmobilefaceauth)
	ON_BN_CLICKED(IDC_btnOTP, &Cocx32nnDlg::OnBnClickedbtnotp)
	ON_BN_CLICKED(IDC_btnQR, &Cocx32nnDlg::OnBnClickedbtnqr)
END_MESSAGE_MAP()


// Cocx32nnDlg 메시지 처리기

BOOL Cocx32nnDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_ocx.Init_AuthOCX();

	m_imgFaceAuth.SetBitmaps(IDB_FaceAuth, RGB(100, 0, 0));
	m_imgFaceAuth.DrawTransparent(TRUE);
	m_imgFaceAuth.DrawBorder(FALSE);
	m_imgMobileFaceAuth.SetBitmaps(IDB_MobileFaceAuth, RGB(100, 0, 0));
	m_imgMobileFaceAuth.DrawTransparent(TRUE);
	m_imgMobileFaceAuth.DrawBorder(FALSE);
	m_imgMobileOTPAuth.SetBitmaps(IDB_MobileOTPAuth, RGB(100, 0, 0));
	m_imgMobileOTPAuth.DrawTransparent(TRUE);
	m_imgMobileOTPAuth.DrawBorder(FALSE);
	m_imgMobileQRAuth.SetBitmaps(IDB_MobileQRAuth, RGB(100, 0, 0));
	m_imgMobileQRAuth.DrawTransparent(TRUE);
	m_imgMobileQRAuth.DrawBorder(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cocx32nnDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cocx32nnDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cocx32nnDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cocx32nnDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
	CString strVersion = m_ocx.GetVersion();
	AfxMessageBox(strVersion);
}


void Cocx32nnDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void Cocx32nnDlg::OnBnClickedbtnpcfaceauth()
{
	TCHAR id[64] = { 0, };
	GetDlgItemText(IDC_USERID, id, 64);

	CString result = m_ocx.PC_FaceAuth(id);
	MessageBox(result, _T("테스트 프로그램"));
}


void Cocx32nnDlg::OnBnClickedbtnmobilefaceauth()
{
	TCHAR id[64] = { 0, };
	GetDlgItemText(IDC_USERID, id, 64);

	CString result = m_ocx.Mobile_FaceAuth(id);
	MessageBox(result, _T("테스트 프로그램"));
}


void Cocx32nnDlg::OnBnClickedbtnotp()
{
	TCHAR id[64] = { 0, };
	GetDlgItemText(IDC_USERID, id, 64);

	CString result = m_ocx.Mobile_OTP(id);
	MessageBox(result, _T("테스트 프로그램"));
}


void Cocx32nnDlg::OnBnClickedbtnqr()
{
	TCHAR id[64] = { 0, };
	GetDlgItemText(IDC_USERID, id, 64);

	CString result = m_ocx.Mobile_QR(id);
	MessageBox(result, _T("테스트 프로그램"));
}
