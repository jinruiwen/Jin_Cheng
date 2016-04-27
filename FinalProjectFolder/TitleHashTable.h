#ifndef TITLE_HASH_TABLE
#define TITLE_HASH_TABLE

#include "HashTable.h"
#include <string>

class TitleHashTable: public HashTable
{
 public:
    // Calculate the hash key.
    virtual int hashSum (Movie movie);
    void deleteMovie (std::string movieName);
    //Delete the movie with the specified name.
    void findMovie (std::string movieName);
    //Find the movie that has the specified name.
    void findMovieStartingWith (std::string name);
    std::string searchKeyword(std::string keyword);
};

#endif
