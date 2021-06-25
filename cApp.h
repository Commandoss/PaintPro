#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>

#include <string>
#include <CommCtrl.h>
//#include <algorithm>
#include <stdexcept>

class cApp
{
	enum CTL_ID {
		CALCBUTTON_ID,
		RESULTEDID_ID,
	};
public:
	explicit cApp();
	~cApp();

	int run();
	//int system_error(const int code, const std::string message);

private:
	void init_native_window_obj();
	void Create_Menu_Bar();
	void create_toolbar();

	static LRESULT CALLBACK application_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void create_native_controls();

private:
	const std::wstring m_szAppName{ L"DrawPaint" }, m_szClassName{ L"MainWindow" };
	HWND m_hWnd, m_hWndToolbar;
	const int m_nAppWidth{ 1280 }, m_nAppHeigth{ 720 };

};

