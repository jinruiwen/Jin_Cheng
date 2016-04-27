#include "Movie.h"
#include <string>

Movie::Movie()
{
    this -> name = "";
    this -> quantity = 0;
    this -> next = NULL;
    this -> year = 0;
}

Movie::Movie (std::string name, int quantity, int year)
{
    this -> name = name;
    this -> quantity = quantity;
    this -> next = NULL;
    this -> year = year;
}
