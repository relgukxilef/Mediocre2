#include "ui/controls.h"
#include "ui/controls_win32.h"

#define NOMINMAX
#include <windows.h>

namespace ui {
    button::button(
        window* parent, std::u8string_view text, rectangle position,
        unsigned callback_index
    ) : d(new button_data) {
        auto title_16 = to_wstring(text);
        d->hwnd = CreateWindowExW(
            0,
            L"BUTTON",
            title_16.data(),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
            position.x, position.y, position.width, position.height,
            parent->d->hwnd, (HMENU)static_cast<DWORD64>(callback_index),
            global_instance, NULL
        );
    }

    button::~button() {
        DestroyWindow(d->hwnd);
    }

    void button::position(rectangle position) {
        check(SetWindowPos(
            d->hwnd, NULL,
            position.x, position.y, position.width, position.height, 0
        ));
    }

    void button::text(std::u8string_view text) {
        auto title_16 = to_wstring(text);
        SetWindowTextW(d->hwnd, title_16.data());
    }
}
