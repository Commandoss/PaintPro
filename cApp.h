#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>

#include "Scrollbar.h"
#include "ID.h"


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
	void Create_Menu_Bar();
	void create_toolbar_button();
	void create_accel_table();

	static cApp* create_class_ptr(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void init_native_window_obj();
	static LRESULT CALLBACK create_main_window(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void create_toolbar();
	static LRESULT CALLBACK static_toolbar_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //вроде не нужна
	LRESULT CALLBACK toolbar_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void create_canvas();
	static LRESULT CALLBACK static_canvas_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //вроде не нужна
	LRESULT CALLBACK canvas_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void create_wall();
	static LRESULT CALLBACK static_wall_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK wall_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	//HWND create_horizontal_ScrollBar(HWND hwndParent, int sbHeight);
	//HWND create_vertical_ScrollBar(HWND hwndParent, int sbWidth);

private:

	void create_native_controls();

	void about();

private:
	const std::wstring m_szAppName{ L"DrawPaint" }, m_szClassName{ L"MainWindow" };
	const std::wstring m_szClassNameBar{ L"ToolbarWindow" };
	const std::wstring m_szCanvasName{ L"CanvasWindow" };
	const std::wstring m_szWallName{ L"WallWindow" };
	//const std::wstring m_szHorizontalScrollBar{ L"HorizontalScrollBar" }, m_szVerticalScrollBar{ L"VerticalScrollBar" };

	HWND m_hWnd, m_hWndToolbar, m_hWndCanvas, m_hWndWall;
	HWND m_hWndHScrollBar, m_hWndVScrollBar;

	int m_nAppWidth{ 1280 }, m_nAppHeigth{ 720 };
	//int m_nToolbarWidth{ 1280 }, m_nToolbarHeigth{ 50 };
	//int m_nWallWidth{ 4096 }, m_nWallHeigth{ 3072 };
	int m_nWallWidth{ 1409 }, m_nWallHeigth{ 720 };
	int m_nCanvasWidth{ 1280 }, m_nCanvasHeigth{ 670 };

	const int sbHeigth = 20;
};

