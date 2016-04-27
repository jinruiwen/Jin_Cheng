#ifndef YEAR_HASH_TABLE
#define YEAR_HASH_TABLE

#include "HashTable.h"
#include <string>

class YearHashTable: public HashTable
{
 public:
    // Calculate the hash key.
    virtual int hashSum (Movie movie);
    void deleteMovie (int year, std::string movieName);
    // Search for the movie, starting in the linked list
    // hashed by name, then looking to see if the title matches.
    // If the title is found, delete the movie.
    void findMovie (int userYear);
    //Find the movie that has the specified year.
};

#endif
