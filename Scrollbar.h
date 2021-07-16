#pragma once

#include "cWindow.h"

class Scrollbar
{
private:
	HWND m_hWndParent;
	HWND m_hWndScrollbar;
	SCROLLBARINFO scr_inf;

public:
	Scrollbar(const HWND hWndParent, const int sbWidth, const DWORD type);
	~Scrollbar();

	HWND create(const DWORD type);
	SCROLLINFO Initialise(const SCROLLINFO si, const RECT rect);

private:
	void massageBox(const std::string msg);

private:	
	int s_Width;
};

