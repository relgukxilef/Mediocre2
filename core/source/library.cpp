#include "mediocre/library.h"

library::library() {

}

std::u8string  library::get_title(unsigned) const {
    return u8"\u900f\u9748\u8550";
}

std::vector<track_artist_credit> library::get_credits(unsigned) const {
    return {
        {u8"\u304b\u3081\u308a\u3042", u8" and ", 0}, {u8"Nanahira", u8"", 1}
    };
}
