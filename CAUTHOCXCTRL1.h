#pragma once

// 머신에서 Microsoft Visual C++를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// 참고: 이 파일의 콘텐츠를 수정하지 마세요. Microsoft Visual C++를 통해 이 클래스가 다시 생성될 경우 
// 수정 내용을 덮어씁니다.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class CAUTHOCXCTRL1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CAUTHOCXCTRL1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= {0x8c640a97, 0x5898, 0x4d28, {0x88, 0x48, 0x6c, 0xeb, 0xab, 0xcd, 0xa0, 0x20}};
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
				BSTR bstrLicKey = nullptr)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 특성
public:


// 작업
public:
// _DauthOCX

// 함수
//

	CString GetVersion()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	void Init_AuthOCX()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

	CString PC_FaceAuth(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString Mobile_FaceAuth(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString CheckRegisteredFace(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString CheckRegisteredPattern(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString Mobile_OTP(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString CheckRegisteredOtp(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString Mobile_QR(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString CheckRegisteredQr(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xA, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}



};
