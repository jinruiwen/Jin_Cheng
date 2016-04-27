#include "YearHashTable.h"
#include <iostream>
using namespace std;

// TODO: This is a new class.  It's structured the
// same as the TitleHashTable class, but it uses an integer
// for a key instead of a string.  You'll need to flesh out
// these methods.  You can copy & paste from the TitleHashTable
// class once it's working, and make some slight modifications.

int YearHashTable::hashSum (Movie movie)
{
    int value = movie.year;
    if(value < 0)
    {
        value = 0;
    }

    value %= tableSize;
    return value;
}

void YearHashTable::deleteMovie (int year, std::string movieName)
{
    // Search for the movie, starting in the linked list
    // hashed by name, then looking to see if the title matches.
    // If the title is found, delete the movie.
    Movie m (movieName, 0, year);
    //object m that We only need to find specific movie title
    int indextable = hashSum(m);
    Movie *temp = hashTable[indextable];


    if((hashTable[indextable] -> name == movieName) && (hashTable[indextable] -> year == year))
    {
        hashTable[indextable] = hashTable[indextable] -> next;
    }
    else
    {
        temp = temp -> next;
        Movie *previous = NULL;

        while (temp != NULL)
        {
            if ((temp -> name == movieName) && (temp -> year == year)) //found match
            {
                if(previous == NULL)
                {
                    hashTable[indextable] = NULL;
                }
                else
                {
                    previous -> next = temp -> next;
                }
                delete temp;
                break;
            }//if
            temp = temp -> next;
        }//while
    }
}

void YearHashTable::findMovie (int userYear)
{
    // Find the movie in the linked list obtained
    // by using the year to calculate the hash code.
    Movie m (" ", 0, userYear);
    int value = hashSum(m);
    bool found = false;
    Movie *root = hashTable[value];

    while(root != NULL)
    {
        if(root -> year != userYear)
        {
            root = root -> next;
        }
        else
        {
            int outputYear = root -> year;
            cout << " year: " << outputYear << endl;
            break;
        }
    }
    if(!found)
    {
        cout << "not found" << endl;
    }
}

