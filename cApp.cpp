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
	_wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hInstance = GetModuleHandle(nullptr);
	_wc.lpfnWndProc = cApp::application_proc;
	_wc.lpszClassName = this->m_szClassName.c_str();
	_wc.lpszMenuName = nullptr;
	_wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&_wc))
		throw runtime_error("Error, can't register main window class!"s);

	RECT _windowRC{ 0, 0, this->m_nAppWidth, this->m_nAppHeigth };
	AdjustWindowRect( &_windowRC, WS_OVERLAPPEDWINDOW, false);

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


LRESULT cApp::application_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	cApp* pApp;




	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT cApp::window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_COMMAND: 
	{
		switch (static_cast<cApp::CTL_ID>(LOWORD(wParam)))
		{
		case cApp::CTL_ID::CALCBUTTON_ID:
		{

		}
		break;
		}
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
	AppendMenu(hfile, MF_STRING, NULL, L"Create");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, NULL, L"Open");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, NULL, L"Save");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, NULL, L"Save as..");
	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hfile, MF_STRING, NULL, L"Exit");

	//HEDIT
	AppendMenu(hedit, MF_STRING, NULL, L"Cut");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, NULL, L"Insert");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, NULL, L"Copy");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, NULL, L"Undo");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hedit, MF_STRING, NULL, L"Return");
	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);

	//HWINDOW
	AppendMenu(hwindow, MF_STRING, NULL, L"Close");
	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hwindow, MF_STRING, NULL, L"Roll up");
	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hwindow, MF_STRING, NULL, L"Expand");
	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);


	//HHELP 
	AppendMenu(hhelp, MF_STRING, NULL, L"About");
	SetMenu(this->m_hWnd, hMenuBar);
}

void cApp::create_toolbar() {
	using std::runtime_error;
	using namespace std::string_literals;

	const std::wstring m_szClassNameChl{ L"ToolbarWindow" };

	UnregisterClass(m_szClassNameChl.c_str(), GetModuleHandle(nullptr));
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.lpszClassName = m_szClassNameChl.c_str();
	wc.lpfnWndProc = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;
	
	

	this->m_hWndToolbar = CreateWindowEx (
		0,
		WC_BUTTON,
		L"Child",
		WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE ,
		12,
		55,
		200, 
		200, 
		this->m_hWnd, reinterpret_cast<HMENU>(cApp::CTL_ID::RESULTEDID_ID), GetModuleHandle(nullptr), nullptr);

	//WNDCLASS w;
	//memset(&w, 0, sizeof(WNDCLASS));
	//w.lpfnWndProc = ChildProc;
	//w.hInstance = hinst;
	//w.hbrBackground = GetStockBrush(WHITE_BRUSH);
	//w.lpszClassName = "ChildWClass";
	//w.hCursor = LoadCursor(NULL, IDC_CROSS);
	//RegisterClass(&w);
	//HWND child;
	//child = CreateWindowEx(0, "ChildWClass", (LPCTSTR)NULL,
	//	WS_CHILD | WS_BORDER | WS_VISIBLE, i * 10, i * 10,
	//	50, 50, hwnd, (HMENU)(int)(ID_FIRSTCHILD + i), hinst, NULL);

	if (!this->m_hWndToolbar)
		throw runtime_error("Error, can't Toolbar!"s);
	//UpdateWindow(this->m_hWnd);
	//SetParent(hwnd, hwndparent);
	//ShowWindow(hwnd, SW_SHOWNORMAL);
}

void cApp::create_native_controls() {
	using std::wstring;
	using std::string;

	try
	{
		this->Create_Menu_Bar();
		this->create_toolbar();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();

		MessageBox(NULL, wstring(begin(exp_data), end(exp_data)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
		ExitProcess(EXIT_FAILURE);
	}


	//if (this->m_hWndButton = CreateWindowEx(); this->m_hWndButton)
}
