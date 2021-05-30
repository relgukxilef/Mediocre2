#include "mediocre/tracks.h"

tracks::tracks() {

}

std::string tracks::get_title(unsigned) const {
    return "Tears Of The Dragon (Original Mix)";
}

std::vector<track_artist_credit> tracks::get_credits(unsigned) const {
    return {{"Pedro Del Mar", " feat. ", 0}, {"Ridgewalkers", "", 1}};
}
