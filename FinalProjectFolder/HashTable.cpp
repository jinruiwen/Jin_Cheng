#include <iostream>
using namespace std;
#include "HashTable.h"

/**
 * Default constructor.  The hashtable size is set to
 * DEFAULT_TABLE_SIZE.
 */
HashTable::HashTable()
{
    this->tableSize = DEFAULT_TABLE_SIZE;
    init();
}

/**
 * Constructor.  The hashtable size is set to the
 * size passed through the parameter list.
 */
HashTable::HashTable (int tableSize)
{
  this->tableSize = tableSize;
  init();
}

/**
 * Destructor.
 */
HashTable::~HashTable()
{
  if (hashTable != NULL)
  {
    for (int i = 0; i < tableSize; ++i)
    {
      if (hashTable[i] != NULL)
      {
	  // TODO: Delete all of the elements of the linked list
      }
    }
    hashTable = NULL;
  }
}

/**
 * Initialization method, shared by constructors.
 */
void HashTable::init()
{
  hashTable = new Movie* [tableSize];

  for (int i = 0; i < tableSize; ++i)
  {
    hashTable[i] = NULL;
  }
}

/**
 * Print the contents of the hash table.
 */
void HashTable::printTableContents()
{
  cout << "--------------------------" << endl;
  cout << "Printing table of contents" << endl;

  for (int i = 0; i < tableSize; ++i)
  {
    if (hashTable[i] != NULL)
    {
      Movie *node = hashTable[i];
      while (node != NULL)
      {
	  // TODO: Fill in a better-formatted output statement
	  cout << node -> name << " " << node -> year << " " << node -> quantity << endl;
	  node = node -> next;
      }
    }
  }
}

/**
 * Insert a movie into the hash table.
 */
void HashTable::insertMovie(Movie movie)
{
  // Note that the hashSum method will be overridden in subclasses.
  // It is used to determine the hash table key.
    int key = hashSum(movie);
    Movie *node = hashTable[key];
    Movie *newNode = new Movie(movie.name, movie.quantity, movie.year);

    if(hashTable[key] == NULL)
    //no movie in the array element 0
    {
        hashTable[key] = newNode;
    }
    else
    {
        Movie *temp = hashTable[key];
        //create a temp pointer to hashtable element
        while(temp -> next != NULL)
        //the last node
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        //insert new movie at the end of list
    }
}
