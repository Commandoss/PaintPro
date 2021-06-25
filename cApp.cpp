#include "cApp.h"

cApp::cApp() {
	using std::wstring;
	using std::string;

	try
	{
		this->init_native_window_obj();
		this->create_native_controls();
	}
	catch (const std::exception& e)
	{
		string exp_data = e.what();

		MessageBox(NULL, wstring(begin(exp_data), end(exp_data)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
		ExitProcess(EXIT_FAILURE);
	}
}

cApp::~cApp() {

}

int cApp::run() {
	MSG msg;
	ShowWindow(this->m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(this->m_hWnd);
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}

void cApp::init_native_window_obj() {
	using std::runtime_error;
	using namespace std::string_literals;

	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
	_wc.cbClsExtra = 0;
	_wc.cbWndExtra = 0;
	_wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	_wc.hIcon = (HICON)LoadImage(NULL, (application_path_icon.c_str()), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
	_wc.hIconSm = (HICON)LoadImage(NULL, (application_path_icon_small.c_str()), IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
	_wc.hInstance = GetModuleHandle(nullptr);
	_wc.lpfnWndProc = cApp::application_proc;
	_wc.lpszClassName = this->m_szClassName.c_str();
	_wc.lpszMenuName = nullptr;
	_wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&_wc))
		throw runtime_error("Error, can't register main window class!"s);

	RECT _windowRC{ 0, 0, this->m_nAppWidth, this->m_nAppHeigth };
	AdjustWindowRect(&_windowRC, WS_OVERLAPPEDWINDOW, false);

	this->m_hWnd = CreateWindowEx(
		0,
		this->m_szClassName.c_str(),
		this->m_szAppName.c_str(),
		WS_DLGFRAME | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZE,
		(GetSystemMetrics(SM_CXSCREEN) - _windowRC.right) / 2,
		(GetSystemMetrics(SM_CYSCREEN) - _windowRC.bottom) / 2,
		_windowRC.right, _windowRC.bottom, nullptr, nullptr, nullptr, this);
	if (!this->m_hWnd)
		throw runtime_error("Error, can't create main window!"s);
}

LRESULT CALLBACK cApp::application_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	cApp* pApp;
	if (uMsg == WM_CREATE) {
		pApp = static_cast<cApp*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
		SetLastError(0);
		if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pApp))) {
			if (GetLastError() != 0) return false;
		}
	}
	else {
		pApp = reinterpret_cast<cApp*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}

	if (pApp) {
		pApp->m_hWnd = hWnd;
		return pApp->window_proc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void cApp::Create_Menu_Bar()
{
	HMENU hMenuBar = CreateMenu();
	HMENU hfile = CreateMenu();
	HMENU hedit = CreateMenu();
	//HMENU himage = CreateMenu();
	//HMENU hlayers = CreateMenu();
	HMENU hwindow = CreateMenu();
	HMENU hhelp = CreateMenu();

	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hfile, L"File");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hedit, L"Edit");
	//AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hfile, L"Image");
	//AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hedit, L"Layers");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hwindow, L"Window");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hhelp, L"Help");

	//HFILE
	AppendMenu(hfile, MF_STRING, menu_id_create, L"Create\tCtrl+N");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, menu_id_open, L"Open\tCtrl+O");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, menu_id_save, L"Save\tCtrl+S");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, menu_id_save_as, L"Save as..\tCtrl+A");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, menu_id_exit, L"Exit\tCtrl+Q");

	//HEDIT
	AppendMenu(hedit, MF_STRING, menu_id_cut, L"Cut\tCtrl+X");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, menu_id_insert, L"Insert\tCtrl+V");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, menu_id_copy, L"Copy\tCtrl+C");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, menu_id_undo, L"Undo\tCtrl+Z");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, menu_id_return, L"Return\tCtrl+U");

	//HWINDOW
	AppendMenu(hwindow, MF_STRING, menu_id_close, L"Close\tAlt+N");
	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hwindow, MF_STRING, menu_id_roll_up, L"Roll up\tAlt+Q");
	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hwindow, MF_STRING, menu_id_expand, L"Expand\tAlt+W");


	//HHELP 
	AppendMenu(hhelp, MF_STRING, menu_id_about, L"About\tAlt+I");
	SetMenu(this->m_hWnd, hMenuBar);
}

void cApp::create_native_controls() {
	using std::wstring;
	using std::string;

	try
	{
		this->Create_Menu_Bar();
		this->create_toolbar();
		this->create_accel_table();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();

		MessageBox(NULL, wstring(begin(exp_data), end(exp_data)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
		ExitProcess(EXIT_FAILURE);
	}


	//if (this->m_hWndButton = CreateWindowEx(); this->m_hWndButton)
}


void cApp::create_accel_table() {
	RegisterHotKey(this->m_hWnd, key_id_close, MOD_CONTROL, 0x4E);
	RegisterHotKey(this->m_hWnd, key_id_exit, MOD_CONTROL, 0x51);
	RegisterHotKey(this->m_hWnd, key_id_create, MOD_CONTROL, 0x43);
	RegisterHotKey(this->m_hWnd, key_id_open, MOD_CONTROL, 0x4f);
	RegisterHotKey(this->m_hWnd, key_id_save, MOD_CONTROL, 0x53);
	RegisterHotKey(this->m_hWnd, key_id_save_as, MOD_CONTROL, 0x41);
	RegisterHotKey(this->m_hWnd, key_id_cut, MOD_CONTROL, 0x58);
	RegisterHotKey(this->m_hWnd, key_id_insert, MOD_CONTROL, 0x56);
	RegisterHotKey(this->m_hWnd, key_id_copy, MOD_CONTROL, 0x43);
	RegisterHotKey(this->m_hWnd, key_id_undo, MOD_CONTROL, 0x5a);
	RegisterHotKey(this->m_hWnd, key_id_return, MOD_CONTROL, 0x55);
	RegisterHotKey(this->m_hWnd, key_id_roll_up, MOD_ALT, 0x51);
	RegisterHotKey(this->m_hWnd, key_id_expand, MOD_ALT, 0x57);
	RegisterHotKey(this->m_hWnd, key_id_about, MOD_ALT, 0x49);
}

void cApp::create_toolbar() {
	using std::runtime_error;
	using namespace std::string_literals;

	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
	_wc.cbClsExtra = 0;
	_wc.cbWndExtra = 0;
	_wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	_wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hInstance = GetModuleHandle(nullptr);
	_wc.lpfnWndProc = cApp::application_proc;
	_wc.lpszClassName = this->m_szClassNameBar.c_str();
	_wc.lpszMenuName = nullptr;
	_wc.style = CS_VREDRAW | CS_HREDRAW;
	
	if (!RegisterClassEx(&_wc))
		throw runtime_error("Error, can't register main window class!"s);
	
	this->m_hWndToolbar = CreateWindowEx (
		0,
		this->m_szClassNameBar.c_str(),
		L"Toolbar",
		WS_CHILD | WS_BORDER | WS_VISIBLE,
		0,
		0,
		1280, 
		50, 
		this->m_hWnd, nullptr, GetModuleHandle(nullptr), nullptr);

	if (!this->m_hWndToolbar)
		throw runtime_error("Error, can't Toolbar!"s);
}

void cApp::create_toolbar_button() {

}

LRESULT CALLBACK cApp::window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	using std::wstring;
	using std::string;
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case menu_id_close:
		{

		}
		break;
		case menu_id_exit:
		{
			PostQuitMessage(EXIT_FAILURE);
		}
		break;
		case menu_id_about:
		{
			this->about();
		}
		break;
		case menu_id_create:
		{

		}
		break;
		case menu_id_open:
		{

		}
		break;
		case menu_id_save:
		{

		}
		break;
		case menu_id_save_as:
		{

		}
		break;
		case menu_id_cut:
		{

		}
		break;
		case menu_id_insert:
		{

		}
		break;
		case menu_id_copy:
		{

		}
		break;
		case menu_id_undo:
		{

		}
		break;
		case menu_id_return:
		{

		}
		break;
		case menu_id_roll_up:
		{

		}
		break;
		case menu_id_expand:
		{

		}
		break;
		case cApp::CTL_ID::CALCBUTTON_ID:
		{

		}
		break;
		}
	}
	return 0;

	case WM_HOTKEY:
	{
		switch (LOWORD(wParam))
		{
		case key_id_close:
		{

		}
		break;
		case key_id_exit:
		{
			PostQuitMessage(EXIT_FAILURE);
		}
		break;
		case key_id_create:
		{

		}
		break;
		case key_id_open:
		{

		}
		break;
		case key_id_save:
		{

		}
		break;
		case key_id_save_as:
		{

		}
		break;
		case key_id_cut:
		{

		}
		break;
		case key_id_insert:
		{

		}
		break;
		case key_id_copy:
		{

		}
		break;
		case key_id_undo:
		{

		}
		break;
		case key_id_return:
		{

		}
		break;
		case key_id_roll_up:
		{
			SendMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		break;
		case key_id_expand:
		{
			SendMessage(hWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
		}
		break;
		case key_id_about:
		{
			this->about();
		}
		break;
		}
	}
	return 0;

	case WM_SIZE:
	{

	}
	return 0;

	case WM_DESTROY:
	{
		PostQuitMessage(EXIT_FAILURE);
	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


LRESULT CALLBACK cApp::toolbar_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_COMMAND:
	{

	}
	case WM_SIZE:
	{
		LOWORD(lParam);
		MoveWindow(hWnd, 0, 0, LOWORD(lParam), 50, 1);
		ShowWindow(hWnd, SW_SHOWNORMAL);
	}
	return 0;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void cApp::about() {
	MessageBox(this->m_hWnd, L"PaintPro\nVersion: 1.0\nCreator: Belousov Ilya.", L"About", MB_ICONINFORMATION | MB_OK);
}


