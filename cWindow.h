#pragma once

#include <Windows.h>
#include <stdexcept>
#include <string.h>

class cWindow 
{
private:
	HWND m_hWndParrent;
	HWND m_hWndToolbar;
	WNDCLASSEX m_wc;

public:
	cWindow(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className);
	~cWindow();

private:
	bool create();
	bool registerClass();
	bool setWindowSize(const unsigned int Width, const unsigned int Heigth); // надо доработать 

	// возможно нужно реалтзовать гетеры сетеры для приватны переменных 
	//  почитать и вспомнить про наслежование и инициализацию объектов 
	// класс скролла должен быть отдельным и реализовывапть старые функции 

	// навернеое классы будем определять в cApp

	static LRESULT CALLBACK static_window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) ;

	static cWindow* create_class_ptr(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void massageBox(const std::string msg);

private:
	std::wstring m_szClassName{  };
	int m_nToolbarWidth{ 0 }, m_nToolbarHeigth{ 0 };
};