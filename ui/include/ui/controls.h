#pragma once

#include <cstdint>
#include <span>
#include <string_view>
#include <memory>

// thin wrappers around native ui elements
// goals: compile-time swappable implementation, native ui, easy to use
// non-goals: thread-safety, binary representation of ui, c-compatibility

namespace ui {
    struct color_type {
        std::uint8_t r, g, b, a;
    };

    struct rectangle {
        int x, y, width, height;
    };

    struct window {
        std::unique_ptr<struct window_data> d;
    };

    struct button {
        button(
            window* parent, std::u8string_view text, rectangle position,
            unsigned callback_index
        );
        ~button();

        void position(rectangle position);
        void text(std::u8string_view text);

        std::unique_ptr<struct button_data> d;
    };
}
