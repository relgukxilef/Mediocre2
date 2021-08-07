#pragma once

#include <string>
#include <vector>
#include <memory>

#include "mediocre/tracks.h"

struct sqlite3;
struct sqlite3_stmt;

struct library {
    library();

    std::u8string get_title(unsigned id) const;
    std::vector<track_artist_credit> get_credits(unsigned id) const;

    sqlite3* database;

    sqlite3_stmt* track_select;
};

