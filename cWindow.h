#pragma once

#include <Windows.h>
#include <stdexcept>
#include <string.h>

class cWindow 
{
protected:
	HWND m_hWndParrent;
	HWND m_hWndWindow;
	WNDCLASSEX m_wc;
	HBRUSH backgroundcolor;
	int position_x = 0, position_y = 0;

public:
	cWindow();
	cWindow(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y);
	~cWindow();

protected:
	virtual bool create(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y) = 0;
	bool createWindow();
	bool registerClass();
	bool setWindowSize(const unsigned int Width, const unsigned int Heigth);

	static LRESULT CALLBACK static_window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

	static cWindow* create_class_ptr(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void massageBox(const std::string msg);

protected:
	std::wstring m_szClassName{  };
	int m_nWindowWidth{ 0 }, m_nWindowHeigth{ 0 };
};