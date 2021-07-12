#pragma once

#include "cWindow.h"

class Scrollbar: public cWindow
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
	bool SetWindowSize(const unsigned int Width, const unsigned int Heigth) override;

private:
	void massageBox(const std::string msg) override;

private:	
	int s_Width;
};

