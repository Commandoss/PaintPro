// PaintPro.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "PaintPro.h"
#include <Windows.h>
#include <CommCtrl.h>

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
static WCHAR szTitle[] = _T("PaitDemo");        // Текст строки заголовка
static WCHAR szWindowClass[] = _T("Main");      // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND CreateToolbar(HWND hWndParent);
UINT IDTOOLBAR;
const UINT nButtons = 4;



HWND CreateMenuBar(HWND hWnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PAINTPRO));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PAINTPRO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PAINTPRO);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

UINT_PTR About_PTR;
UINT_PTR File_PTR;
UINT_PTR Option_PTR;
UINT_PTR Edit_PTR;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE: 
	{
		CreateMenuBar(hWnd);
		CreateToolbar(hWnd);
		break;
	}

	case WM_COMMAND:
        {

		if (LOWORD(wParam) == About_PTR) {
			MessageBox(hWnd, L"Version 1.0\n\n © 2021 Company Secure", L"About", NULL);
		}
			
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

HWND CreateMenuBar(HWND hWnd)
{
	HMENU hMenuBar = CreateMenu();
	HMENU hfile = CreateMenu();
	HMENU hedit = CreateMenu();
	HMENU hoption = CreateMenu();
	HMENU habout = CreateMenu();

	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hfile, L"File");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hedit, L"Edit");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hoption, L"Option");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)habout, L"About");

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

	//HABOUT
	AppendMenu(habout, MF_STRING, NULL, L"Developer");
	AppendMenu(habout, MF_SEPARATOR, NULL, NULL);

	SetMenu(hWnd, hMenuBar);

	return hWnd;
}

HWND CreateToolbar(HWND hWndParent)
{
	// Create the toolbar window.
	
	TBBUTTON tbb[nButtons];
	tbb[0].iBitmap = STD_PROPERTIES;   /*id иконки*/
	tbb[0].idCommand = ID_OPTION;      /*id команды*/
	tbb[0].fsState = TBSTATE_ENABLED;  /*состояние*/
	tbb[0].fsStyle = TBSTYLE_BUTTON;   /*стиль*/
	tbb[0].iString = 0;                /*подпись под кнопкой*/

	tbb[1].iBitmap = STD_REDOW;
	tbb[1].idCommand = ID_CALCOUT;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].iString = 0;

	tbb[2].iBitmap = STD_UNDO;
	tbb[2].idCommand = ID_CALCIN;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].iString = 0;

	//HWND htb = CreateToolbarEx(
	//	(HINSTANCE)HINST_COMMCTRL,     /*дескриптор модуля, из которого берется ресурс с иконками*/
	//	(UINT)IDB_STD_SMALL_COLOR,     /*id ресурса с иконками*/
	//	(TBBUTTON*)tbb,                /*указатель на массив с информацией о кнопках*/
	//	(int)nButtons,                 /*количество кнопок на панели*/
	//	16, 16,                          /*размеры кнопок*/
	//	15, 15,                          /*размеры иконок для кнопок*/
	//	sizeof(TBBUTTON)                /*размер структуры TBBUTTON*/
	//);

	//HINSTANCE icons = L"D:\PaintPro\IMG\toolbar_img";
	HWND hWndToolbar = CreateToolbarEx(hWndParent, WS_CHILD | WS_VISIBLE | TBSTYLE_TOOLTIPS, IDTOOLBAR, nButtons, ID_BTNS, , tbb, nButtons, 16, 16, 15, 15, sizeof(TBBUTTON));
	


	return hWndParent;
}



//// Обработчик сообщений для окна "О программе".
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
