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
			= {0x4e3c47a7, 0x5307, 0x49a5, {0x94, 0xd1, 0xa4, 0xc0, 0x67, 0xb0, 0x50, 0x22}};
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
// _DAuthOCX

// 함수
//

	CString GetVersion()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, nullptr);
		return result;
	}

	CString PC_FaceAuth(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	void Init_AuthOCX()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

	CString Mobile_FaceAuth(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString Mobile_OTP(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}

	CString Mobile_QR(LPCTSTR userID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, userID);
		return result;
	}



};
