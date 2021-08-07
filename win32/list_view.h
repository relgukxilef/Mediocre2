#pragma once

#include <windows.h>

struct list_view_delegate {
    virtual void draw(HDC hdc) = 0;
    virtual void set_rectangle(
        unsigned index, unsigned x, unsigned y, unsigned width, unsigned height
    );
    virtual void set_range(unsigned begin, unsigned end);
};

struct list_view {
    list_view(list_view_delegate* delegate);

    list_view_delegate* delegate;
    unsigned element_height;
    unsigned scroll_position;
};

