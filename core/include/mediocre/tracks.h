#pragma once

#include <string>
#include <vector>

struct track_artist_credit {
    std::string name;
    std::string join_phrase;
    unsigned artist_id;
};

struct tracks {
    tracks();

    std::string get_title(unsigned id) const;
    std::vector<track_artist_credit> get_credits(unsigned id) const;
};

