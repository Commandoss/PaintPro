#include "cWindow.h"

cWindow::cWindow() {

}

cWindow::cWindow(const HWND hWndParrent, const int Width, const int Heigth, const std::wstring className, const int x, const int y) {
	using std::wstring;
	using std::string;

	this->m_hWndParrent = hWndParrent;
	this->m_szClassName = className;
	this->position_x = x;
	this->position_y = y;

	try
	{
		this->registerClass();
		this->setWindowSize(Width, Heigth);
		this->createWindow();
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();
		massageBox(exp_data);
	}
}

cWindow::~cWindow() {

}

bool cWindow::createWindow() {
	using std::runtime_error;
	using namespace std::string_literals;

	this->m_hWndWindow = CreateWindowEx(
		0,
		this->m_szClassName.c_str(),
		nullptr,
		WS_CHILD | WS_BORDER | WS_VISIBLE,
		this->position_x,
		this->position_y,
		m_nWindowWidth,
		m_nWindowHeigth,
		this->m_hWndParrent, nullptr, nullptr, this);

	if (!this->m_hWndWindow) {
		throw runtime_error("Error, can't create window!"s);
	}

	return true;
}

bool cWindow::registerClass() {
	using std::runtime_error;
	using namespace std::string_literals;

	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
	_wc.cbClsExtra = 0;
	_wc.cbWndExtra = 0;
	_wc.hbrBackground = this->backgroundcolor;
	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	_wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hInstance = GetModuleHandle(nullptr);
	_wc.lpfnWndProc = cWindow::static_window_proc;
	_wc.lpszClassName = this->m_szClassName.c_str();
	_wc.lpszMenuName = nullptr;
	_wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&_wc))
		throw runtime_error("Error, can't register class!"s);

	this->m_wc = _wc;

	return true;
}

bool cWindow::setWindowSize(const unsigned int Width, const unsigned int Heigth) {
	this->m_nWindowHeigth = Heigth;
	this->m_nWindowWidth = Width;
	return true;
}

void cWindow::massageBox(const std::string msg) {
	using std::wstring;
	using std::string;

	MessageBox(NULL, wstring(begin(msg), end(msg)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
	ExitProcess(EXIT_FAILURE);
}

LRESULT CALLBACK cWindow::static_window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	cWindow* pApp = cWindow::create_class_ptr(hWnd, uMsg, wParam, lParam);
	if (pApp) {
		pApp->m_hWndWindow = hWnd;
		return pApp->window_proc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

cWindow* cWindow::create_class_ptr(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	cWindow* pApp;
	if (uMsg == WM_CREATE) {
		pApp = static_cast<cWindow*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
		SetLastError(0);
		if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pApp))) {
			if (GetLastError() != 0) return false;
		}
	}
	else {
		pApp = reinterpret_cast<cWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}
	return pApp;
}