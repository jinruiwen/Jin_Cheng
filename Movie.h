#ifndef MOVIE
#define MOVIE
#include <string>

/**
 * This class represents information about a movie.
 * It also contains a pointer that can be used to insert
 * it into a linked list.
 */
class Movie {
 public:
    std::string name;
    int year;
    int quantity;
    Movie();
    Movie (std::string name, int quantity, int year);
    Movie* next;   // the next element in a linked list
};

#endif
