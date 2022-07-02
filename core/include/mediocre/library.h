#pragma once

#include <string>
#include <vector>
#include <memory>

#include "mediocre/tracks.h"

struct sqlite3;
struct sqlite3_stmt;

/*
Options:
    library allocates and deallocates
        + if library caches, it could just give out pointers to the cache
        - library may need to keep use-counters
        - need to provide functions to communicate which data is not needed
        anymore
        + potentially least number of allocations and copying
        - makes data in file immovable
        - no compression in file
        + most data will be copied to a ui class and can be deallocated soon
        + that's the interface sqlite provides too

    library allocates, caller deallocates
        - library may need to copy data
        + library doesn't need any book-keeping
        - copying even if a pointer to raw data could be provided (rare)

    caller allocates and deallocates
        - caller needs to know how much space to allocate (e.g. title lengths)
        - copying even if a pointer to raw data could be provided (rare)
        - no advantage with sqlite as it can't use user supplied buffers
*/

struct library {
    library();

    std::u8string get_title(unsigned id) const;
    std::vector<track_artist_credit> get_credits(unsigned id) const;

    sqlite3* database;

    sqlite3_stmt* track_select;
};

