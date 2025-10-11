#pragma once


// 게임 윈도우

class ZApplication
{
private:
	HINSTANCE		m_hInst;	// 윈도우 인스턴스 핸들
	HWND			m_hWnd;			// 윈도우 핸들

protected:
	TCHAR 		m_Class[MAX_PATH]; // 윈도우 타이틀
	TCHAR 		m_Caption[MAX_PATH]; // 윈도우 타이틀

	WNDCLASSEX m_wcex;

	DWORD m_Style; // 윈도우 스타일
	DWORD m_XPos; // 윈도우 X 위치
	DWORD m_YPos; // 윈도우 Y 위치
	DWORD m_Width; // 윈도우 넓이
	DWORD m_Height; // 윈도우 높이





public:
	ZApplication(DWORD XPos = 0, DWORD YPos = 0, DWORD Width = 640, DWORD Height = 480);

	HWND		GetHWnd();
	HINSTANCE	GetHInst();

	BOOL Run();
	BOOL Error(BOOL Fatal, const TCHAR* Text, ...);


	BOOL Move(long XPos, long YPos);
	BOOL Resize(long Width, long Height);

	BOOL ShowMouse(BOOL Show = TRUE);
	//LRESULT CALLBACK AppWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)

	virtual LRESULT CALLBACK MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	virtual BOOL Init() { return TRUE; }
	virtual BOOL Shutdown() { return TRUE; }
	virtual BOOL Frame() { return TRUE; }

};

static ZApplication* g_pApplication = NULL;
static LRESULT CALLBACK AppWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
