#pragma once
#include "cWindow.h"

class cCanvas :	public cWindow
{
public:
	cCanvas();
	cCanvas(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y);
	~cCanvas();

	bool create(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y) override;

private:
	LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};

