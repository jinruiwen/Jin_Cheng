#include "TitleHashTable.h"
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// TODO: This class is basically the same as your current
// HashTable class, but without the menu/submenu stuff.
// Insert the code into the appropriate methods.
// Note that some of the code has been moved into the superclass,
// so it doesn't need to be duplicated here.

int TitleHashTable::hashSum (Movie movie)
{
    // Calculate the hash table key based on movie title.
    // character to lowercase by adding 32 to its value
    char c = movie.name[0];
    //only first character; element 0

    int sum = (int) c;
    if((sum >= 60) && (sum <= 90))
    {
        sum += 32;
    }

  //Finally, do a mod to fit into the existing table size
    sum %= tableSize;
    return sum;
}

void TitleHashTable::deleteMovie (std::string movieName)
{
    Movie m (movieName, 0, 0);
    //object m that We only need to find specific movie title
    int indextable = hashSum(m);
    Movie *temp = hashTable[indextable];

    if(hashTable[indextable] -> name == movieName)
    {
        hashTable[indextable] = hashTable[indextable] -> next;
    }
    else
    {
        temp = temp -> next;
        Movie *previous = NULL;

        while (temp != NULL)
        {
            if (temp -> name == movieName) //found match
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

void TitleHashTable::findMovie (std::string movieName)
{
    Movie m (movieName, 0, 0);
    int key = hashSum(m);
    Movie *root = hashTable[key];
    int index = 0;
    bool found = false;

    while(root != NULL)
    {
        if(root -> name != movieName)
        {
            root = root -> next;
        }
        else
        {
            string title = root -> name;
            cout << "Index is:" << index << " title: " << title << endl;
            found = true;
            break;
        }
        index++;
    }
    if(!found)
    {
        cout << "not found" << endl;
    }
}

void TitleHashTable::findMovieStartingWith (std::string name)
{
    //Find the movie whose name starts with the specified substring.
    Movie m (name, 0, 0);
    int key = hashSum(m);
    Movie *root = hashTable[0];

    for(int i = 0; i < tableSize; i++)
    {
        while(root != NULL)
        {
            if(root -> name == name)
            {
                cout << name << endl;
                root = root -> next;
            }
            else
            {
                root = root -> next;
            }
        }
    }
}

string TitleHashTable::searchKeyword(string keyword)
{
    string result = "";
    for(int i = 0; i < tableSize; i++)
    {
        Movie *node = hashTable[i];
        string askMovieName = keyword;

        while(node != NULL)
        {
            string movieName = node -> name;

            for(int j = 0; j < movieName.length(); j++)
            {
                 if(askMovieName == movieName.substr(j, askMovieName.length()))
                {
                    cout << "FOUND: " << movieName << " " << node -> year << " " << node -> quantity << endl;
                    result = movieName;
                    break;
                }
            }
             node = node -> next;
        }
    }
    return result;
}
