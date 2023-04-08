// MessageIPC.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <Windows.h>
#include <processthreadsapi.h>
#include <stdio.h>

LRESULT CALLBACK WndowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main()
{
    const char* className = "MyWindowClass";
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASSEXA wcx;
    wcx.cbSize = sizeof(WNDCLASSEXA);
    wcx.style = 0;
    wcx.lpfnWndProc = WndowProc;
    wcx.cbClsExtra = 0;
    wcx.cbWndExtra = 0;
    wcx.hInstance = hInstance;
    wcx.hIcon = NULL;
    wcx.hCursor = NULL;
    wcx.hbrBackground = NULL;
    wcx.lpszMenuName = NULL;
    wcx.lpszClassName = className;
    wcx.hIconSm = NULL;
    if (!RegisterClassExA(&wcx))
    {
        return 1;
    }

    HWND hWnd = CreateWindowExA(
        0,
        className,
        NULL,
        0,
        0,
        0,
        0,
        0,
        HWND_MESSAGE,
        NULL,
        hInstance,
        NULL
    );
    if (!hWnd)
    {
        return 1;
    }

    DWORD curProcID = GetCurrentProcessId();
    printf("curProcID=%d hWnd=%08x\n", curProcID, (DWORD)(DWORDLONG)hWnd);

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0))
    {
    }

    return 0;
}

LRESULT CALLBACK WndowProc(HWND hwnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
    printf("=> msgID=%08x: wParam=%08x, lParam=%08x\n", msgID, (int)wParam, (int)lParam);

    LRESULT result = 0;
    switch (msgID)
    {
    case WM_APP:
        printf("WM_APP received.\n");
        break;

    default:
        result = DefWindowProcA(hwnd, msgID, wParam, lParam);
        break;
    }
    return result;
}
