#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>

#include "Scrollbar.h"
#include "cMenuBar.h"
#include "Toolbar.h"
#include "cWall.h"
#include "cCanvas.h"

#include "cWindow.h"
#include "ID.h"


class cApp
{
private:
	cMenuBar MenuBar;
	cToolbar Toolbar;
	cWall Wall;
	cCanvas Canvas;

public:
	explicit cApp();
	~cApp();

	int run();

private:
	void Create_Menu_Bar();
	void create_toolbar_button();
	void create_accel_table();

	static cApp* create_class_ptr(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void init_native_window_obj();
	static LRESULT CALLBACK create_main_window(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	void create_native_controls();
	void massageBox(const std::string msg);

private:
	const std::wstring m_szAppName{ L"DrawPaint" }, m_szClassName{ L"MainWindow" };
	const std::wstring m_szCanvasName{ L"CanvasWindow" };
	//const std::wstring m_szHorizontalScrollBar{ L"HorizontalScrollBar" }, m_szVerticalScrollBar{ L"VerticalScrollBar" };

	HWND m_hWnd, m_hWndToolbar, m_hWndCanvas, m_hWndWall;
	HWND m_hWndHScrollBar, m_hWndVScrollBar;

	int m_nAppWidth{ 1280 }, m_nAppHeigth{ 720 };
	int m_nCanvasWidth{ 1280 }, m_nCanvasHeigth{ 670 };

	const int sbHeigth = 20;
};

