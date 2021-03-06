#include "cApp.h"

cApp::cApp() {
	using std::wstring;
	using std::string;

	try
	{
		this->init_native_window_obj();
		this->create_native_controls();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();
		massageBox(exp_data);
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

void cApp::create_native_controls() {
	this->MenuBar.create(m_hWnd);
	this->Toolbar.create(m_hWnd, m_nAppWidth, 80, L"ToolbarClass", 0, 0);
	this->Wall.create(m_hWnd, GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), L"WallClass", 0, 80);
	this->Canvas.create(m_hWnd, m_nAppWidth - 5, (m_nAppHeigth - 80), L"CanvasClass", 5, 85);

	//this->create_toolbar();
	//this->create_wall();
	//Scrollbar scrollbar_v(this->m_hWndWall, 20, SBS_VERT), scrollvar_h(this->m_hWndWall, 20, SBS_HORZ);
	//this->create_accel_table();
	//this->create_canvas();
//if (this->m_hWndButton = CreateWindowEx(); this->m_hWndButton)
}
//
//void cApp::create_accel_table() {
//	RegisterHotKey(this->m_hWnd, key_id_close, MOD_CONTROL, 0x4E);
//	RegisterHotKey(this->m_hWnd, key_id_exit, MOD_CONTROL, 0x51);
//	RegisterHotKey(this->m_hWnd, key_id_create, MOD_CONTROL, 0x43);
//	RegisterHotKey(this->m_hWnd, key_id_open, MOD_CONTROL, 0x4f);
//	RegisterHotKey(this->m_hWnd, key_id_save, MOD_CONTROL, 0x53);
//	RegisterHotKey(this->m_hWnd, key_id_save_as, MOD_CONTROL, 0x41);
//	RegisterHotKey(this->m_hWnd, key_id_cut, MOD_CONTROL, 0x58);
//	RegisterHotKey(this->m_hWnd, key_id_insert, MOD_CONTROL, 0x56);
//	RegisterHotKey(this->m_hWnd, key_id_copy, MOD_CONTROL, 0x43);
//	RegisterHotKey(this->m_hWnd, key_id_undo, MOD_CONTROL, 0x5a);
//	RegisterHotKey(this->m_hWnd, key_id_return, MOD_CONTROL, 0x55);
//	RegisterHotKey(this->m_hWnd, key_id_roll_up, MOD_ALT, 0x51);
//	RegisterHotKey(this->m_hWnd, key_id_expand, MOD_ALT, 0x57);
//	RegisterHotKey(this->m_hWnd, key_id_about, MOD_ALT, 0x49);
//}
//
//void cApp::create_toolbar_button() {
//}

//Main window
void cApp::init_native_window_obj() {
	using std::runtime_error;
	using namespace std::string_literals;

	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
	_wc.cbClsExtra = 0;
	_wc.cbWndExtra = 0;
	_wc.hbrBackground = (HBRUSH)COLOR_MENU;
	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	_wc.hIcon = (HICON)LoadImage(NULL, (application_path_icon.c_str()), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
	_wc.hIconSm = (HICON)LoadImage(NULL, (application_path_icon_small
		.c_str()), IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
	_wc.hInstance = GetModuleHandle(nullptr);
	_wc.lpfnWndProc = cApp::create_main_window;
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
		WS_OVERLAPPEDWINDOW,
		(GetSystemMetrics(SM_CXSCREEN) - _windowRC.right) / 2,
		(GetSystemMetrics(SM_CYSCREEN) - _windowRC.bottom) / 2,
		_windowRC.right, _windowRC.bottom, nullptr, nullptr, nullptr, this);
	if (!this->m_hWnd)
		throw runtime_error("Error, can't create main window!"s);
}

LRESULT CALLBACK cApp::create_main_window(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	cApp* pApp = cApp::create_class_ptr(hWnd, uMsg, wParam, lParam);
	if (pApp) {
		pApp->m_hWnd = hWnd;
		return pApp->window_proc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK cApp::window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	using std::wstring;
	using std::string;
	switch (uMsg)
	{
	case WM_CREATE:
	{
		//SetWindowRgn(hWnd, (HRGN)626, 1);

	}
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
			if (this->MenuBar.exit() == IDYES) {
				PostQuitMessage(EXIT_FAILURE);
			}
		}
		break;
		case menu_id_about:
		{
			this->MenuBar.about();
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
		}
	}
	return 0;

	case WM_SIZE:
	{
		RECT wnd_rect;
		GetWindowRect(hWnd, &wnd_rect);

		this->m_nAppWidth = LOWORD(lParam);
		this->m_nAppHeigth = HIWORD(lParam);

		/*this->m_nToolbarWidth = GetSystemMetrics(SM_CXSCREEN) - wnd_rect.left;
		SetWindowPos(this->m_hWndToolbar, nullptr, 0, 0, this->m_nToolbarWidth, this->m_nToolbarHeigth, SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);*/

		SetWindowPos(this->m_hWndVScrollBar, nullptr, wnd_rect.right - this->sbHeigth, wnd_rect.top, sbHeigth, wnd_rect.bottom, SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);
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
			if (this->MenuBar.exit() == IDYES) {
				PostQuitMessage(EXIT_FAILURE);
			}
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
			this->MenuBar.about();
		}
		break;
		}
	}
	return 0;

	case WM_DESTROY:
	{
		//if (this->MenuBar.exit() == IDYES) {
		PostQuitMessage(EXIT_FAILURE);
		//}
	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

cApp* cApp::create_class_ptr(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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
	return pApp;
}

//Wall Window
//void cApp::create_wall() {
//	using std::runtime_error;
//	using namespace std::string_literals;
//
//	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
//	_wc.cbClsExtra = 0;
//	_wc.cbWndExtra = 0;
//	_wc.hbrBackground = (HBRUSH)COLOR_MENU;
//	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	_wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
//	_wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
//	_wc.hInstance = GetModuleHandle(nullptr);
//	_wc.lpfnWndProc = cApp::static_wall_proc;
//	_wc.lpszClassName = this->m_szWallName.c_str();
//	_wc.lpszMenuName = nullptr;
//	_wc.style = CS_VREDRAW | CS_HREDRAW;
//
//	if (!RegisterClassEx(&_wc))
//		throw runtime_error("Error, can't register wall class!"s);
//
//	this->m_hWndWall = CreateWindowEx(
//		0,
//		this->m_szWallName.c_str(),
//		L"Wall",
//		WS_CHILD | WS_BORDER | WS_VISIBLE,
//		0,
//		50,
//		this->m_nWallWidth,
//		this->m_nWallHeigth,
//		this->m_hWnd, nullptr, nullptr, this);
//
//	if (!this->m_hWndWall)
//		throw runtime_error("Error, can't create wall!"s);
//}
//
//LRESULT cApp::static_wall_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	cApp* pApp = cApp::create_class_ptr(hWnd, uMsg, wParam, lParam);
//	if (pApp) {
//		pApp->m_hWndWall = hWnd;
//		return pApp->wall_proc(hWnd, uMsg, wParam, lParam);
//	}
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}
//
//LRESULT cApp::wall_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	switch (uMsg)
//	{
//	case WM_CREATE:
//	{
//		/*| WS_HSCROLL | WS_VSCROLL
//			scr1 = CreateWindow(_T("scrollbar"), NULL, WS_CHILD | WS_VISIBLE,
//				10, 10, 200, 20, hWnd, NULL, hInst, NULL);
//		s1Pos = 100; s1Min = 1; s1Max = 100;
//		SetScrollRange(s1Scroll, SB_CTL, s1Min, s1Max, TRUE);
//		SetScrollPos(s1Scroll, SB_CTL, s1Pos, TRUE);*/
//	}
//	return 0;
//
//	case WM_VSCROLL:
//	{
//		//SCROLLINFO scrInfo;
//		//scrInfo.cbSize = sizeof(SCROLLINFO);
//
//		//scrInfo.fMask = SIF_ALL; //???????? ??????? ????????? scrollbar-?
//		//GetScrollInfo(hWnd, SB_VERT, &scrInfo);
//
//		//int currentPos = scrInfo.nPos; //?????????? ??????? ????????? ???????????
//
//		//switch (LOWORD(wParam)) { //?????????? ???????? ???????????? ? ???????? ?????????
//		//case SB_LINEUP: //???? ?? ??????? ?????
//		//	scrInfo.nPos -= 1;
//		//	break;
//		//case SB_LINEDOWN: //???? ?? ??????? ???? 
//		//	scrInfo.nPos += 1;
//		//	break;
//		//case SB_THUMBTRACK: //?????????????? ????????
//		//	scrInfo.nPos = scrInfo.nTrackPos;
//		//	break;
//		//default: return 0; //??? ?????? ???????? (???????? ??????? PageUp/PageDown) ??????????
//		//}
//
//		//scrInfo.fMask = SIF_POS; //??????? ????????? ????? ?????????
//		//SetScrollInfo(hWnd, SB_VERT, &scrInfo, TRUE);
//		//GetScrollInfo(hWnd, SB_VERT, &scrInfo); //(??. ?????????? ????)
//
//		//int yScroll = currentPos - scrInfo.nPos; // ????????? ???????? ?????????
//		//ScrollWindow(hWnd, 0, yScroll, NULL, NULL); //????????? ?????????
//	}
//	return 0;
//
//	}
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}
//
////Canvas Window
//void cApp::create_canvas() {
//	using std::runtime_error;
//	using namespace std::string_literals;
//
//	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
//	_wc.cbClsExtra = 0;
//	_wc.cbWndExtra = 0;
//	_wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
//	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	_wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
//	_wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
//	_wc.hInstance = GetModuleHandle(nullptr);
//	_wc.lpfnWndProc = cApp::static_canvas_proc;
//	_wc.lpszClassName = this->m_szCanvasName.c_str();
//	_wc.lpszMenuName = nullptr;
//	_wc.style = CS_VREDRAW | CS_HREDRAW;
//
//	if (!RegisterClassEx(&_wc))
//		throw runtime_error("Error, can't register canvas class!"s);
//
//	this->m_hWndCanvas = CreateWindowEx(
//		0,
//		this->m_szCanvasName.c_str(),
//		L"Canvas",
//		WS_CHILD | WS_BORDER | WS_VISIBLE,
//		5,
//		5,
//		this->m_nCanvasWidth,
//		this->m_nCanvasHeigth,
//		this->m_hWndWall, nullptr, nullptr, this);
//
//	if (!this->m_hWndToolbar)
//		throw runtime_error("Error, can't create canvas!"s);
//}
//
//LRESULT cApp::static_canvas_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	cApp* pApp = cApp::create_class_ptr(hWnd, uMsg, wParam, lParam);
//	if (pApp) {
//		pApp->m_hWndWall = hWnd;
//		return pApp->canvas_proc(hWnd, uMsg, wParam, lParam);
//	}
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}
//
//LRESULT cApp::canvas_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	switch (uMsg)
//	{
//	case WM_CREATE:
//	{
//		/*| WS_HSCROLL | WS_VSCROLL
//			scr1 = CreateWindow(_T("scrollbar"), NULL, WS_CHILD | WS_VISIBLE,
//				10, 10, 200, 20, hWnd, NULL, hInst, NULL);
//		s1Pos = 100; s1Min = 1; s1Max = 100;
//		SetScrollRange(s1Scroll, SB_CTL, s1Min, s1Max, TRUE);
//		SetScrollPos(s1Scroll, SB_CTL, s1Pos, TRUE);*/
//	}
//	return 0;
//
//	case WM_VSCROLL:
//	{
//		//SCROLLINFO scrInfo;
//		//scrInfo.cbSize = sizeof(SCROLLINFO);
//
//		//scrInfo.fMask = SIF_ALL; //???????? ??????? ????????? scrollbar-?
//		//GetScrollInfo(hWnd, SB_VERT, &scrInfo);
//
//		//int currentPos = scrInfo.nPos; //?????????? ??????? ????????? ???????????
//
//		//switch (LOWORD(wParam)) { //?????????? ???????? ???????????? ? ???????? ?????????
//		//case SB_LINEUP: //???? ?? ??????? ?????
//		//	scrInfo.nPos -= 1;
//		//	break;
//		//case SB_LINEDOWN: //???? ?? ??????? ???? 
//		//	scrInfo.nPos += 1;
//		//	break;
//		//case SB_THUMBTRACK: //?????????????? ????????
//		//	scrInfo.nPos = scrInfo.nTrackPos;
//		//	break;
//		//default: return 0; //??? ?????? ???????? (???????? ??????? PageUp/PageDown) ??????????
//		//}
//
//		//scrInfo.fMask = SIF_POS; //??????? ????????? ????? ?????????
//		//SetScrollInfo(hWnd, SB_VERT, &scrInfo, TRUE);
//		//GetScrollInfo(hWnd, SB_VERT, &scrInfo); //(??. ?????????? ????)
//
//		//int yScroll = currentPos - scrInfo.nPos; // ????????? ???????? ?????????
//		//ScrollWindow(hWnd, 0, yScroll, NULL, NULL); //????????? ?????????
//	}
//	return 0;
//
//	}
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}
//
////void cApp::about() {
////	MessageBox(this->m_hWnd, L"PaintPro\nVersion: 1.0\nCreator: Belousov Ilya.", L"About", MB_ICONINFORMATION | MB_OK);
////////}

void cApp::massageBox(const std::string msg) {
	using std::wstring;
	using std::string;

	MessageBox(NULL, wstring(begin(msg), end(msg)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
	ExitProcess(EXIT_FAILURE);
}
