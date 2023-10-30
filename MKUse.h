#ifndef MK_USE_H_
#define MK_USE_H_

// [argument] 아이디, 채널, 맥어드레스, 카메라인덱스, 대기시간, URL
// [return] 반환값 토큰을 통해 로그인 요청하면 됨 (응답 JSON에서 resultCode, validUntilDate, secureToken, password 를 파싱해서 저장해야함) - FaceAuthResponse 참고
// C:\\Program Files\\Penta Security Systems\\iSIGN+ EE-Win\\MetsaKuur.dll 참조추가
extern "C" __declspec(dllexport) std::string AuthFace(
	std::wstring apc_token,
	std::wstring user_id,
	std::wstring ip,
	unsigned short port,
	int camIdx = 0,
	std::wstring client_computer_type = L"pc",
	std::wstring server_url = L"/api/v1/auth/face-sensor/auth",
	std::wstring channel = L"ASI",
	std::wstring mac_address = L"00-00-00-00-00-00",
	int waitTime = 10000
);

#endif