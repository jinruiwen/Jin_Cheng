
**********************************NOTE: You have to run the program with Terminal Emulator instead of just codeBlocks.************************************

Project	Summary:
This directory contains the following files:

	HashTableTest.{cpp, h}: The driver program.
	Movie.{cpp, h}: The Movie class.
	HashTable.{cpp, h}: The base HashTable class.
        TitleHashTable.{cpp, h}: A hash table hashed by string.
        YearHashTable.{cpp, h}: A hash table hashed by integer.

	The main method is in HashTableTest.cpp.

This project is based on assignment6 with hash table and function, and we extend with a few extra functions to search some specific conditions. First,
the program would read the assignment6movies.txt file and convert into hashtable. We will have two hashtables, TitleHashTable and YearHashTable 
are subclasses of HashTable, which provides common functionality for general hashing operations. For hashSum function of TitleHashTable,
I convert the first character of the title to lowercase and then mod the ASCII code with the table size, and you need to add 32 because of lowercase.
And all movies on the list will be built with single linked list based on ACSII table in hash-index. We will have two menus. The main menu will have
insert, delete, find, advanced search, and quit options. The submenu is in the advanced search, which can search only by keyword because I ran out of time. 
*********************************************

How to Run:

Since you can only run with Terminal Emulator, you will have to use commend-line argument with the name ""Assignment6Movies.txt""
The advanced search of 'search by keyword' is to read user's input by English letters. You have to type the exact same letters. For example,
if you want to find all movies with 'The', you have to type the exact same. If you type all lowercase 'the', this would give you different result.
For instance, if you type 'The', you can find 'The Godfather'. However, if you type 'the', you will find 'Once Upon a Time in the West'.
For all functions, you will get a require to type title and year, and the functions will do titlehashtable and yearhasstable because sometimes
you might have exception. For instance, if you want to delete a movie, you might have at least two movies that have same release year, so you need
to have the same title name that pass through the same input with the variable title.
*********************************************

Dependencies:

You don't have to install any other libraries. All libraries I included are in the codeBlocks.


System	Requirements:
This program can be compiled in Windows or Mac. There's no additional system requirement.

Group	Members:
Reiwen Jin

Contributors:

Greg H. He made some comments and said I should have '#define DEFAULT_TABLE_SIZE 10' on hashTable.h instead of making a variable in private.

Open issues/bugs: For some unknown reasons, this program can't be compiled in codeBlocks. And I should have added one more hashtable for reading quantity.
Besides, I should have more extra functions such as search by quantity, movie length, or even more.


Phase 2 collaboration recommendation:


