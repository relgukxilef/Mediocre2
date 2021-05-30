#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <winuser.h>

LRESULT CALLBACK window_procedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam
) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);



            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

INT WINAPI WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow
) {
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Mediocre Music Player";

    WNDCLASS wc{
        .lpfnWndProc = window_procedure,
        .hInstance = hInstance,
        .lpszClassName = CLASS_NAME,
    };

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0, // Optional window styles.
        CLASS_NAME, // Window class
        L"Mediocre Music Player", // Window text
        WS_OVERLAPPEDWINDOW, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL, // Parent window
        NULL, // Menu
        hInstance, // Instance handle
        NULL // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    CreateWindowExA(
        0,
        "BUTTON",
        "Hello World!",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
        10, 10, 500, 50,
        hwnd, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
