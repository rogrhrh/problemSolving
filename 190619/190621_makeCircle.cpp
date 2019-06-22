// 190619.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "190619.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <ctime>
#include <iterator>
#define MAX_LOADSTRING 100
#define CIRCLE_SIZE 50

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

												// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

typedef struct __MYCIRCLE
{
	double m_center_x;
	double m_center_y;
	double m_size;
	double m_move_x;
	double m_move_y;
}myCircle;

typedef struct __VECTOR {
	double x;
	double y;
}myVec;

bool isContact(const myCircle& a, const myCircle& b)
{
	double val = pow((a.m_center_x - b.m_center_x), 2)
		+ pow(a.m_center_y - b.m_center_y, 2);

	if (val <= pow((a.m_size + b.m_size), 2))
		return true;
	else
		return false;
}

myVec getNormalVector(myCircle my, myCircle other)
{
	myVec temp;
	temp.x = other.m_center_x - my.m_center_x;
	temp.y = other.m_center_y - my.m_center_y;
	double distance = sqrt(pow(temp.x, 2) + pow(temp.y, 2));
	temp.x = temp.x / distance;
	temp.y = temp.y / distance;

	return temp;
}
myVec getReflectPos(myCircle my, myCircle other)
{
	myVec other_temp;
	other_temp.x = -1 * other.m_move_x;
	other_temp.y = -1 * other.m_move_y;

	myVec normal = getNormalVector(my, other);
	double innerproduct = (other_temp.x * normal.x) + (other_temp.y * normal.y);
	if (innerproduct < 0)
	{
		other_temp.x = other.m_move_x;
		other_temp.y = other.m_move_y;
		return other_temp;
	}
	other_temp.x = innerproduct * (2 * normal.x) + other.m_move_x;
	other_temp.y = innerproduct * (2 * normal.y) + other.m_move_y;

	return other_temp;
}
void CollisonCase(myCircle& my, myCircle& other)
{
	myVec my_temp = getReflectPos(other, my);
	myVec other_temp = getReflectPos(my, other);

	other.m_move_x = other_temp.x;
	other.m_move_y = other_temp.y;
	other.m_center_x += other.m_move_x;
	other.m_center_y += other.m_move_y;

	my.m_move_x = my_temp.x;
	my.m_move_y = my_temp.y;
	my.m_center_x += my.m_move_x;
	my.m_center_y += my.m_move_y;
}


int MergeCase(std::vector<myCircle>::iterator&  my, std::vector<myCircle>::iterator& other)
{
	int result = 1;
	my->m_size += other->m_size;
	if (my->m_size > 250.0)
	{
		result++;
	}
	return result;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY190619, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY190619));

	MSG msg;

	// 기본 메시지 루프입니다.
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY190619));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY190619);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	int p_x, p_y;
	static std::vector<myCircle> circle_arr;
	static RECT rect_view;
	static int currentTimer;


	switch (message)
	{
	case WM_CREATE:
		srand(time(NULL));
		currentTimer = 1;
		SetTimer(hWnd, currentTimer, 60, NULL);
		GetClientRect(hWnd, &rect_view);
		break;
	case WM_COMMAND:

	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_PAINT:
	{
		HDC hdc = BeginPaint(hWnd, &ps);
		for (auto it : circle_arr)
		{
			Ellipse(hdc, it.m_center_x - it.m_size, it.m_center_y - it.m_size,
				it.m_center_x + it.m_size, it.m_center_y + it.m_size);
		}
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_LBUTTONDOWN:
	{
		p_x = LOWORD(lParam);
		p_y = HIWORD(lParam);
		myCircle temp_circle{ p_x, p_y, CIRCLE_SIZE,
		rand() % 31 + 10, rand() % 31 + 10 };
		circle_arr.push_back(temp_circle);
		InvalidateRgn(hWnd, NULL, TRUE);
		break;
	}
	case WM_LBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_CHAR:
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case 0x31:
			currentTimer = 1;
		case 0x32:
			currentTimer = 2;
		}

		SetTimer(hWnd, currentTimer, 60, NULL);
		break;

	case WM_TIMER:
	{
		int mergeResult = 0;
		for (std::vector<myCircle>::iterator& cur_iter = circle_arr.begin(); cur_iter != circle_arr.end();cur_iter++)
		{
			{
				if (cur_iter->m_move_x > 20) cur_iter->m_move_x = -1 * (cur_iter->m_move_x - 20);
				if (cur_iter->m_move_y > 20) cur_iter->m_move_y = -1 * (cur_iter->m_move_y - 20);

				if (cur_iter->m_center_x + CIRCLE_SIZE >= rect_view.right)
				{
					cur_iter->m_center_x = rect_view.right - CIRCLE_SIZE;
					cur_iter->m_move_x *= -1;
				}
				else if (cur_iter->m_center_x + CIRCLE_SIZE <= rect_view.left + 100)
				{
					cur_iter->m_center_x = rect_view.left - CIRCLE_SIZE + 100;
					cur_iter->m_move_x *= -1;
				}
				if (cur_iter->m_center_y + CIRCLE_SIZE <= rect_view.top + 100)
				{
					cur_iter->m_center_y = rect_view.top + 100 - CIRCLE_SIZE;
					cur_iter->m_move_y *= -1;
				}
				else if (cur_iter->m_center_y + CIRCLE_SIZE >= rect_view.bottom)
				{
					cur_iter->m_center_y = rect_view.bottom - CIRCLE_SIZE;
					cur_iter->m_move_y *= -1;
				}

				cur_iter->m_center_x += cur_iter->m_move_x;
				cur_iter->m_center_y += cur_iter->m_move_y;
			}
			for (std::vector<myCircle>::iterator& chk_iter = circle_arr.begin(); chk_iter != circle_arr.end();chk_iter++)
			{
				mergeResult = 0;
				if (cur_iter == chk_iter)
				{
					chk_iter++;
					continue;
				}
				if (isContact(*cur_iter, *chk_iter))
				{
					switch (currentTimer)
					{
					case 1:
						CollisonCase(*cur_iter, *chk_iter);
						break;
					case 2:
						mergeResult = MergeCase(cur_iter, chk_iter);
						break;
					}
				}
			}
		}


		InvalidateRgn(hWnd, NULL, true);
		break;
	}
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
