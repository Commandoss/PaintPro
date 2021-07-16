#pragma once

#include "cWindow.h"

class cToolbar: public cWindow 
{
public:
	cToolbar();
	cToolbar(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y);
	~cToolbar();

	bool create(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y) override;

private:
	LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};

