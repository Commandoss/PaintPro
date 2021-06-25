//// PaintPro.cpp : Определяет точку входа для приложения.
////
//#include <Windows.h>
//#include <CommCtrl.h>
//
//// Глобальные переменные:
//HINSTANCE hInst;                                // текущий экземпляр
//static WCHAR szTitle[] = _T("PaitDemo");        // Текст строки заголовка
//static WCHAR szWindowClass[] = _T("Main");      // имя класса главного окна
//
//// Отправить объявления функций, включенных в этот модуль кода:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//BOOL CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
//
//HWND CreateToolbar(HWND hWnd);
//
//const UINT nButtons = 4;
//
//
//
//HWND CreateMenuBar(HWND hWnd);
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//
//	// TODO: Разместите код здесь.
//	MyRegisterClass(hInstance);
//
//	// Выполнить инициализацию приложения:
//	if (!InitInstance(hInstance, nCmdShow))
//	{
//		return FALSE;
//	}
//
//	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PAINTPRO));
//
//	MSG msg;
//
//	// Цикл основного сообщения:
//	while (GetMessage(&msg, nullptr, 0, 0))
//	{
//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//
//	return (int)msg.wParam;
//}
//
//
//
////
////  ФУНКЦИЯ: MyRegisterClass()
////
////  ЦЕЛЬ: Регистрирует класс окна.
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PAINTPRO));
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PAINTPRO);
//	wcex.lpszClassName = szWindowClass;
//	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//	return RegisterClassExW(&wcex);
//}
//
////
////   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
////
////   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
////
////   КОММЕНТАРИИ:
////
////        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
////        создается и выводится главное окно программы.
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
//
//	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//	if (!hWnd)
//	{
//		return FALSE;
//	}
//
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	return TRUE;
//}
//
////
////  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
////
////  WM_COMMAND  - обработать меню приложения
////  WM_PAINT    - Отрисовка главного окна
////  WM_DESTROY  - отправить сообщение о выходе и вернуться
////
////
//
//
//UINT_PTR fileMenuCreate = 100;
//UINT_PTR fileMenuOpen = 101;
//UINT_PTR fileMenuSave = 102;
//UINT_PTR fileMenuSaveAs = 103;
//UINT_PTR fileMenuExit = 104;
//
//UINT_PTR editMenuCut = 105;
//UINT_PTR editMenuInsert = 106;
//UINT_PTR editMenuCopy = 107;
//UINT_PTR editMenuUndo = 108;
//UINT_PTR editMenuReturn = 109;
//
//UINT_PTR windowMenuClose = 110;
//UINT_PTR windowMenuRollUp = 111;
//UINT_PTR windowMenuExpand = 112;
//
//UINT_PTR HelpMenuAbout = 113;
//
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_CREATE:
//	{
//		CreateMenuBar(hWnd);
//		CreateToolbar(hWnd);
//		break;
//	}
//
//	case WM_COMMAND:
//	{
//		if (LOWORD(wParam) == fileMenuCreate) {
//
//		}
//		else if (LOWORD(wParam) == fileMenuOpen) {
//
//		}
//		else if (LOWORD(wParam) == fileMenuSave) {
//
//		}
//		else if (LOWORD(wParam) == fileMenuSaveAs) {
//
//		}
//		else if (LOWORD(wParam) == fileMenuExit) {
//
//		}
//		else if (LOWORD(wParam) == editMenuCut) {
//
//		}
//		else if (LOWORD(wParam) == editMenuInsert) {
//
//		}
//		else if (LOWORD(wParam) == editMenuCopy) {
//
//		}
//		else if (LOWORD(wParam) == editMenuUndo) {
//
//		}
//		else if (LOWORD(wParam) == editMenuReturn) {
//
//		}
//		else if (LOWORD(wParam) == windowMenuClose) {
//
//		}
//		else if (LOWORD(wParam) == windowMenuRollUp) {
//
//		}
//		else if (LOWORD(wParam) == windowMenuExpand) {
//
//		}
//		else if (LOWORD(wParam) == HelpMenuAbout) {
//			/*DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, (About), 0);*/
//		}
//		else {
//
//		}
//
//	}
//	break;
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hWnd, &ps);
//		// TODO: Добавьте сюда любой код прорисовки, использующий HDC...
//		EndPaint(hWnd, &ps);
//	}
//	break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
//
//
//
//HWND CreateMenuBar(HWND hWnd)
//{
//	HMENU hMenuBar = CreateMenu();
//	HMENU hfile = CreateMenu();
//	HMENU hedit = CreateMenu();
//	//HMENU himage = CreateMenu();
//	//HMENU hlayers = CreateMenu();
//	HMENU hwindow = CreateMenu();
//	HMENU hhelp = CreateMenu();
//
//	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hfile, L"File");
//	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hedit, L"Edit");
//	//AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hfile, L"Image");
//	//AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hedit, L"Layers");
//	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hwindow, L"Window");
//	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hhelp, L"Help");
//
//	//HFILE
//	AppendMenu(hfile, MF_STRING, fileMenuCreate, L"Create");
//	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hfile, MF_STRING, NULL, L"Open");
//	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hfile, MF_STRING, NULL, L"Save");
//	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hfile, MF_STRING, NULL, L"Save as..");
//	AppendMenu(hfile, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hfile, MF_STRING, NULL, L"Exit");
//
//	//HEDIT
//	AppendMenu(hedit, MF_STRING, NULL, L"Cut");
//	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hedit, MF_STRING, NULL, L"Insert");
//	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hedit, MF_STRING, NULL, L"Copy");
//	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hedit, MF_STRING, NULL, L"Undo");
//	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hedit, MF_STRING, NULL, L"Return");
//	AppendMenu(hedit, MF_SEPARATOR, NULL, NULL);
//
//	//HWINDOW
//	AppendMenu(hwindow, MF_STRING, NULL, L"Close");
//	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hwindow, MF_STRING, NULL, L"Roll up");
//	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hwindow, MF_STRING, NULL, L"Expand");
//	AppendMenu(hwindow, MF_SEPARATOR, NULL, NULL);
//
//
//	//HHELP 
//	AppendMenu(hhelp, MF_STRING, NULL, L"About");
//	SetMenu(hWnd, hMenuBar);
//
//	return hWnd;
//}
//
//UINT_PTR ID_OPTION = 700;
//UINT_PTR ID_CALCOUT = 701;
//UINT_PTR ID_CALCIN = 702;
//UINT_PTR IDTOOLBAR = 703;
//
////HBITMAP 
//
//HWND CreateToolbar(HWND hWnd)
//{
//	// Create the toolbar window.
//
//	TBBUTTON tbb[nButtons];
//	tbb[0].iBitmap = STD_PROPERTIES;   /*id иконки*/
//	tbb[0].idCommand = ID_OPTION;      /*id команды*/
//	tbb[0].fsState = TBSTATE_ENABLED;  /*состояние*/
//	tbb[0].fsStyle = TBSTYLE_BUTTON;   /*стиль*/
//	tbb[0].iString = 0;                /*подпись под кнопкой*/
//
//	tbb[1].iBitmap = STD_REDOW;
//	tbb[1].idCommand = ID_CALCOUT;
//	tbb[1].fsState = TBSTATE_ENABLED;
//	tbb[1].fsStyle = TBSTYLE_BUTTON;
//	tbb[1].iString = 0;
//
//	tbb[2].iBitmap = STD_UNDO;
//	tbb[2].idCommand = ID_CALCIN;
//	tbb[2].fsState = TBSTATE_ENABLED;
//	tbb[2].fsStyle = TBSTYLE_BUTTON;
//	tbb[2].iString = 0;
//	//HWND CreateWindowEx(
//
//	//	DWORD dwExStyle,      // улучшенный стиль окна
//	//	LPCTSTR lpClassName,  // указатель на зарегистрированное имя класса
//	//	LPCTSTR lpWindowName, // указатель на имя окна
//	//	DWORD dwStyle,        // стиль окна
//	//	int x,                // горизонтальная позиция окна
//	//	int y,                // вертикальная позиция окна
//	//	int nWidth,           // ширина окна
//	//	int nHeight,          // высота окна
//	//	HWND hWndParent,      // дескриптор родительского или окна владельца
//	//	HMENU hMenu,          // дескриптор меню или ID дочернего окна
//	//	HINSTANCE hInstance,  // дескриптор экземпляра прикладной программы
//	//	LPVOID lpParam        // указатель на данные создания окна
//
//	//);
//	HMENU HM;
//	HWND hWndToolbar = CreateWindowEx(WS_EX_CLIENTEDGE, L"Toolbar", NULL, WS_VISIBLE, 20, 20, 20, 20, hWnd, nullptr, hInst, nullptr);
//
//
//	return hWnd;
//}
//
//BOOL CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		break;
//
//	case WM_COMMAND:
//		break;
//	case WM_CLOSE:
//		EndDialog(hDlg, LOWORD(wParam));
//		return FALSE;
//	}
//	return FALSE;
//}
//
//
//
////// Обработчик сообщений для окна "О программе".
////INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
////{
////    UNREFERENCED_PARAMETER(lParam);
////    switch (message)
////    {
////    case WM_INITDIALOG:
////        return (INT_PTR)TRUE;
////
////    case WM_COMMAND:
////        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
////        {
////            EndDialog(hDlg, LOWORD(wParam));
////            return (INT_PTR)TRUE;
////        }
////        break;
////    }
////    return (INT_PTR)FALSE;
////}

#include "cApp.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	cApp app;
	return 	app.run();
}