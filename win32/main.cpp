#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <locale>
#include <codecvt>

#include <windows.h>
#include <winuser.h>

#include "mediocre/library.h"

enum children {
    hello_button,
};

library* library;

RECT draw_text(const HDC& hdc, RECT rectangle, const char8_t* utf8) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
    auto text = convert.from_bytes(reinterpret_cast<const char*>(utf8));
    SIZE size;
    GetTextExtentPointW(hdc, text.c_str(), text.length(), &size);
    DrawTextW(
        hdc, text.c_str(), text.length(), &rectangle, DT_END_ELLIPSIS
    );
    rectangle.left += size.cx;
    return rectangle;
}

LRESULT CALLBACK window_procedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam
) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND:
        if (wParam == BN_CLICKED) {
            if (LOWORD(wParam) == hello_button) {
                std::cout << "clicked" << std::endl;
                return 0;
            }
        }

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            RECT rectangle {
                .left = 10,
                .top = 500,
                .right = 500,
                .bottom = 550,
            };
            /*
            hFont = CreateFont(20, 0, 0, 0, FW_DONTCARE,
                FALSE, FALSE, FALSE, ANSI_CHARSET,
                OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, VARIABLE_PITCH,
                TEXT("Tekton Pro"));*/

            SetTextColor(hdc, RGB(0, 0, 0));
            rectangle =
                draw_text(hdc, rectangle, library->get_title(0).c_str());

            for (const auto& credit : library->get_credits(0)) {
                SetTextColor(hdc, RGB(0, 0, 0));

                rectangle = draw_text(
                    hdc, rectangle, credit.name.c_str()
                );

                //SetTextColor(hdc, RGB(128, 128, 128));

                rectangle = draw_text(
                    hdc, rectangle, credit.join_phrase.c_str()
                );
            }

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
    struct ::library library;
    ::library = &library;

    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Mediocre Music Player";

    WNDCLASS wc{
        .lpfnWndProc = window_procedure,
        .hInstance = hInstance,
        .lpszClassName = CLASS_NAME,
    };

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowExW(
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
        10, 200, 500, 50,
        hwnd, (HMENU)hello_button, hInstance, NULL
    );

    CreateWindowExA(
        0,
        "STATIC",
        reinterpret_cast<const char*>(library.get_title(0).c_str()),
        WS_VISIBLE | WS_CHILD,
        10, 10, 500, 50,
        hwnd, NULL, hInstance, NULL
    );

    CreateWindowExA(
        0,
        "STATIC",
        reinterpret_cast<const char*>(library.get_credits(0)[0].name.c_str()),
        WS_VISIBLE | WS_CHILD | SS_ENDELLIPSIS,
        520, 10, 500, 50,
        hwnd, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);

    std::cout << reinterpret_cast<const char*>(u8"透靈蕐") << std::endl;

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
