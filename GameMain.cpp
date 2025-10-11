# include "GameGlobal.h"
#include <mmsystem.h> // 멀티미디어 시스템, timeGetTime() 함수 사용
#pragma comment(lib, "winmm.lib") // winmm.lib 라이브러리 링크  

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ZApp Game(_T("My D3D Test", 0, 0, 800, 600));
	return Game.Run();
	
}

ZApp::ZApp(const TCHAR* pszCaption, DWORD XPos, DWORD YPos, DWORD Width, DWORD Height)
	: ZApplication(XPos, YPos, Width, Height)
{
	_tcscpy_s(m_Caption, pszCaption);
	//m_pGraphics = nullptr;
}

ZApp::~ZApp()
{
	SAFEARRAY(m_pGraphics);
}

DWORD ZApp::GetWidth()
{
	return m_Width;
}

DWORD ZApp::GetHeight()
{
	return m_Height;
}

LRESULT CALLBACK ZApp::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	return ZApplication::MsgProc(hWnd, uMsg, wParam, lParam);
}



BOOL ZApp::Shutdown()
{
	return TRUE;
}

BOOL ZApp::Init()
{
	m_pGraphics = new ZGraphics(GetHWnd());

	ShowMouse(TRUE);

	return TRUE;
}

BOOL ZApp::Frame()
{
	// 배경을 파란색으로 지운다.
	m_pGraphics->ClearBuffer(0.0f, 0.2f, 0.4f);
	// 프레임을 종료하고 화면에 출력
	m_pGraphics->EndFrame();
	Sleep(1); // CPU 점유율을 낮추기 위해 잠시 대기
	return TRUE;
}