#include "ui/controls_win32.h"

namespace ui {
    HINSTANCE global_instance;

    std::wstring to_wstring(std::u8string_view string) {
        int size = MultiByteToWideChar(
            CP_UTF8, 0, (LPCSTR)string.data(), (int)string.length(), NULL, 0
        );
        std::wstring wstring(size, 0);
        MultiByteToWideChar(
            CP_UTF8, 0, (LPCSTR)string.data(), (int)string.length(),
            wstring.data(),
            size
        );
        return wstring;
    }

    windows_exception::windows_exception(DWORD error) : error(error) {
        std::to_chars(string.data(), string.data() + string.size(), error);
    }

    const char *windows_exception::what() const {
        return string.data();
    }

}
