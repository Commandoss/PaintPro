#pragma once

#include <Windows.h>
#include <stdexcept>
#include <string.h>

#include "ID.h"


class cMenuBar
{
private:
	HMENU hMenuBar;
	HMENU hfile;
	HMENU hedit;
	HMENU hwindow;
	HMENU hhelp;

	HWND m_hWnd;

public:
	cMenuBar();
	cMenuBar(const HWND hWndParrent);
	~cMenuBar();

	void create(const HWND hWndParrent);
	void about();
	int exit();
private:
	void createMenu();
	void append();

	void massageBox(const std::string msg);
};

