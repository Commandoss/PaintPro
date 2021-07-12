#include "Scrollbar.h"

Scrollbar::Scrollbar(HWND hWndParent, int sbWidth, DWORD type) {
	using std::wstring;
	using std::string;

	this->m_hWndParent = hWndParent;
	this->s_Width = sbWidth;

	try
	{
		this->create(type);
	}
	catch (const std::exception & e)
	{
		string exp_data = e.what();

		MessageBox(NULL, wstring(begin(exp_data), end(exp_data)).c_str(), (L"Error"), MB_ICONERROR | MB_OK);
		ExitProcess(EXIT_FAILURE);
	}
}

Scrollbar::~Scrollbar() {

}



HWND Scrollbar::create(DWORD type) {
	using std::runtime_error;
	using namespace std::string_literals;
	RECT rect;

	if (!GetClientRect(this->m_hWndParent, &rect))
		throw runtime_error("Error, can't get v-client rect!"s);

	if (type == SBS_VERT) {
		this->m_hWndScrollbar = CreateWindow(
			L"SCROLLBAR",
			NULL,
			WS_CHILD | WS_VISIBLE | type,
			rect.right - this->s_Width,
			rect.top,
			this->s_Width,
			rect.bottom - this->s_Width,
			this->m_hWndParent,
			nullptr,
			nullptr,
			this
		);
	}
	else if (type == SBS_HORZ) {
		this->m_hWndScrollbar = CreateWindow(
			L"SCROLLBAR",
			NULL,
			WS_CHILD | WS_VISIBLE | type,
			rect.left,
			rect.bottom - this->s_Width,
			rect.right,
			this->s_Width,
			this->m_hWndParent,
			nullptr,
			nullptr,
			this
		);
	}

	if (!this->m_hWndScrollbar)
		throw runtime_error("Error, can't create vertical scroll bar!"s);

	//SetScrollRange(this->m_hWndScrollbar, SB_CTL, 0, this->m_nWallHeigth, TRUE);
	//SetScrollPos(this->m_hWndScrollbar, SB_CTL, 0, TRUE);
}
