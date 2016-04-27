#ifndef HASHTABLE
#define HASHTABLE
#include <string>
#include "Movie.h"
#define DEFAULT_TABLE_SIZE 10

class HashTable {
 public:
    HashTable();
    HashTable(int tableSize);
    virtual ~HashTable();
    virtual void printTableContents();
    virtual void insertMovie (Movie movie);
    // Defer these to subclasses.
    //  virtual void deleteMovie (Movie movie);
    //  virtual void findMovie (Movie movie) = 0;
    void buildHashTable(Movie movie);

 protected:
    // Calculate the hash key. This MUST be overridden in subclasses.
    virtual int hashSum (Movie movie) = 0;
    int tableSize;
    Movie** hashTable = NULL;
    //pointer hashTable to pointer that point to NULL

 private:
    void init();
};

#endif
