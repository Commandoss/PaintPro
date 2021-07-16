#include "cWall.h"

cWall::cWall() {

}

cWall::cWall(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y) {
	using std::wstring;
	using std::string;

	this->position_x = x;
	this->position_y = y;
	try
	{
		this->registerClass();
		this->createWindow();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();
		massageBox(exp_data);
	}
}

cWall::~cWall() {

}

bool cWall::create(const HWND hWndParraent, const int Width, const int Heigth, const std::wstring className, const int x, const int y) {
	using std::wstring;
	using std::string;

	this->m_hWndParrent = hWndParraent;
	this->m_szClassName = className;
	this->setWindowSize(Width, Heigth);
	this->backgroundcolor = HBRUSH(COLOR_MENU);
	this->position_x = x;
	this->position_y = y;

	try
	{
		this->registerClass();
		this->createWindow();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();
		massageBox(exp_data);
	}

	return true;
}

LRESULT CALLBACK cWall::window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	using std::wstring;
	using std::string;

	switch (uMsg)
	{
	case WM_CREATE:
	{

	}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}