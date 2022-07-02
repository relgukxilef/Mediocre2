#pragma once

#include <charconv>
#include <array>

#define NOMINMAX
#include <windows.h>

#include "controls.h"

namespace ui {
    extern HINSTANCE global_instance;

    struct windows_exception : public std::exception {
        windows_exception(DWORD error);
        const char *what() const override;

        DWORD error;
        std::array<char, 10> string;
    };

    inline void check(BOOL success) {
        if (success)
            return;

        auto error = GetLastError();
        throw windows_exception(error);
    }

    std::wstring to_wstring(std::u8string_view string);

    // TODO: maybe data classes should be in non-exported header
    struct window_data {
        HWND hwnd;
    };

    struct button_data {
        HWND hwnd;
    };
}
