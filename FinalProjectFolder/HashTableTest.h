#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "TitleHashTable.h"
#include "YearHashTable.h"

class HashTableTest {
 public:
    HashTableTest();
    ~HashTableTest();
    void readFile (std::string filename);
    int getMenuSelection();
    void handleMenuSelection (int selection);

    int getSubMenu();
    int handleSubMenu(int subselection);


 private:
    TitleHashTable titleTable;
    YearHashTable yearTable;
};
