#include "cMenuBar.h"

cMenuBar::cMenuBar() {

}

cMenuBar::cMenuBar(const HWND hWndParrent) {
	this->create(hWndParrent);
}

cMenuBar::~cMenuBar() {

}

void cMenuBar::create(const HWND hWndParrent) {
	using std::wstring;
	using std::string;

	this->m_hWnd = hWndParrent;

	try
	{
		this->createMenu();
		this->append();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();
		massageBox(exp_data);
	}
}

void cMenuBar::createMenu() {
	using std::runtime_error;
	using namespace std::string_literals;

	if ((hMenuBar = CreateMenu()) == NULL) {
		throw runtime_error("Error, can't create menu bar: hMenuBar!"s);
	}
	if ((hfile = CreateMenu()) == NULL) {
		throw runtime_error("Error, can't create menu bar: hfile!"s);
	}
	if ((hedit = CreateMenu()) == NULL) {
		throw runtime_error("Error, can't create menu bar: hedit!"s);
	}
	if ((hwindow = CreateMenu()) == NULL) {
		throw runtime_error("Error, can't create menu bar: hwindow!"s);
	}
	if ((hhelp = CreateMenu()) == NULL) {
		throw runtime_error("Error, can't create menu bar: hhelp!"s);
	}
}

void cMenuBar::append() {
	using std::runtime_error;
	using namespace std::string_literals;

	if (AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hfile, L"File") == NULL ||
		AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hedit, L"Edit") == NULL ||
		AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hwindow, L"Window") == NULL ||
		AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hhelp, L"Help") == NULL) {
		throw runtime_error("Error, can't create menu bar: MF_POPUP!"s);
	}

	//HFILE
	if (AppendMenu(hfile, MF_STRING, menu_id_create, L"Create\tCtrl+N") == NULL ||
		AppendMenu(hfile, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hfile, MF_STRING, menu_id_open, L"Open\tCtrl+O") == NULL ||
		AppendMenu(hfile, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hfile, MF_STRING, menu_id_save, L"Save\tCtrl+S") == NULL ||
		AppendMenu(hfile, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hfile, MF_STRING, menu_id_save_as, L"Save as..\tCtrl+A") == NULL ||
		AppendMenu(hfile, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hfile, MF_STRING, menu_id_exit, L"Exit\tCtrl+Q") == NULL) {
		throw runtime_error("Error, can't create menu bar: hfile!"s);
	}

	//HEDIT
	if (AppendMenu(hedit, MF_STRING, menu_id_cut, L"Cut\tCtrl+X") == NULL ||
		AppendMenu(hedit, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hedit, MF_STRING, menu_id_insert, L"Insert\tCtrl+V") == NULL ||
		AppendMenu(hedit, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hedit, MF_STRING, menu_id_copy, L"Copy\tCtrl+C") == NULL ||
		AppendMenu(hedit, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hedit, MF_STRING, menu_id_undo, L"Undo\tCtrl+Z") == NULL ||
		AppendMenu(hedit, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hedit, MF_STRING, menu_id_return, L"Return\tCtrl+U") == NULL) {
		throw runtime_error("Error, can't create menu bar: hedit!"s);
	}

	//HWINDOW
	if (AppendMenu(hwindow, MF_STRING, menu_id_close, L"Close\tAlt+N") == NULL ||
		AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hwindow, MF_STRING, menu_id_roll_up, L"Roll up\tAlt+Q") == NULL ||
		AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL) == NULL ||
		AppendMenu(hwindow, MF_STRING, menu_id_expand, L"Expand\tAlt+W") == NULL) {
		throw runtime_error("Error, can't create menu bar: hwindow!"s);
	}

	//HHELP 
	if (AppendMenu(hhelp, MF_STRING, menu_id_about, L"About\tAlt+I") == NULL) {
		throw runtime_error("Error, can't create menu bar: habout!"s);
	}

	if (SetMenu(this->m_hWnd, hMenuBar) == NULL) {
		throw runtime_error("Error, can't set menu bar!"s);
	}
}

void cMenuBar::massageBox(const std::string msg) {
	using std::wstring;
	using std::string;

	MessageBox(NULL, wstring(begin(msg), end(msg)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
	ExitProcess(EXIT_FAILURE);
}

void cMenuBar::about() {
	MessageBox(this->m_hWnd, L"PaintPro\nVersion: 1.0\nCreator: Belousov Ilya.", L"About", MB_ICONINFORMATION | MB_OK);
}

int cMenuBar::exit() {
	return MessageBox(this->m_hWnd, L"Do you really want to leave?", L"Exit.", MB_YESNO);
}
