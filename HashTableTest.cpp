#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTableTest.h"
#include "TitleHashTable.h"
#include "YearHashTable.h"

using namespace std;

int main (int argc, char **argv)
{
    HashTableTest htt;
    cout << "running test" << endl;
    // Read the movie file.
    htt.readFile (argv[1]);

    // Display the menu and handle menu selections
    // Note that 6 means exit.
    int selection = 0;
    int subselection = 0;
    do
    {
        selection = htt.getMenuSelection();
        htt.handleMenuSelection(selection);

    } while (selection != 6);
}

HashTableTest::HashTableTest()
{

}

HashTableTest::~HashTableTest()
{

}

/**
 * Read the contents of the specified movie file, and insert the movies
 * into the two hash tables.
 */
void HashTableTest::readFile (string filename)
{
    string title = " ", releaseyrs = " ", quan_num = " " , data;

    ifstream in_stream (filename.c_str());
    if(in_stream.is_open())
    {
        while(getline(in_stream, data))
        //read all content in file
        {
            cout << "data: " << data << endl;
            size_t current = 0;
            size_t next = 0;
            int count = 0;
            string token;

            do
            {
                current = next;
                next = data.find_first_of(",", current + 1);
                //find_first of return integer type

                token = data.substr(current + 1, next - current - 1);

                if(count == 1)
                {
                    title = token;
                }
                else if(count == 2)
                {
                    releaseyrs = token;
                }
                else if(count == 3)
                {
                    quan_num = token;
                    break;
                }
                count++;
            }while(next != string::npos);

            cout << "Values: " << title << " " << releaseyrs << " " << quan_num << endl;
            // Insert these values into the two
            // hashtables (titleTable and yearTable).
            int quan = atoi(quan_num.c_str());
            // c_str means extract C language character array from C++ string
            int releaYear = atoi(releaseyrs.c_str());
            Movie buildMovie(title, quan, releaYear);
            titleTable.insertMovie(buildMovie);
            yearTable.insertMovie(buildMovie);

        }// end while
    }
    else
    {
        cout << "Input file open failed. " << endl;
        return;
    }
}

int HashTableTest::getMenuSelection()
{
    int selection;
    cout << "======Main Menu======" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print table contents" << endl;
    cout << "5. Advanced search" << endl;
    cout << "6. Quit" << endl;
    cin >> selection;
    return selection;
}

int HashTableTest::getSubMenu()
{
    int selection;
    cout << "1. Search by keyword" << endl;
    cout << "2. Go back to main menu" << endl;
  /*cout << "2. Search by quantity" << endl;
    cout << "3. Search by movie length" << endl;
    cout << "4. Search by year" << endl;
    cout << "5. Go back to main menu" << endl;*/
    cin >> selection;
    return selection;
}

int HashTableTest::handleSubMenu(int subselect)
{
    if(subselect == 1)
    {
        cout << "What is/are the key word? (Please enter a complete vocabulary)" << endl;
        string keyword;
        cin >> keyword;

        titleTable.searchKeyword(keyword);

        subselect = 0;
    }
    else if(subselect == 2)
    {
        subselect = 0;
    }

  /*else if(subselect == 2)
    {
        cout << "What quantity are you looking for?" << endl;
        int quantity;
        cin >> quantity;
        //movie.searchByquantity(quantity);
        subselect = 0;
    }
    else if(subselect == 3)
    {
        cout << "What is the movie length?" << endl;
        int length;
        cin >> length;
        //titleTable.searchBylength(length);
        subselect = 0;
    }
    else if(subselect == 4)
    {
        cout << "All movies contain 'The' are:" << endl;
        //movie.containThe();
        subselect = 0;
    }
    else if(subselect == 5)
    {
        subselect = 0;
    }*/
}

void HashTableTest::handleMenuSelection (int selection)
{
    if(selection == 1)
        {
            string InputTitle;
            int InputYrs;
            int quan;

            cout << "Enter title:" << endl;
            cin >> InputTitle;
            cout << "Enter year:" << endl;
            cin >> InputYrs;

            Movie newMovie (InputTitle, quan,  InputYrs);
            cout << "Inserting into title table" << endl;
            titleTable.insertMovie(newMovie);
            cout << "Inserting into year table" << endl;
            yearTable.insertMovie(newMovie);
        }
    else if(selection == 2)
        {
            string DelMovieName;
            int year;

            cout << "Enter title:" << endl;
            cin >> DelMovieName;
            cout << "Enter year: " << endl;
            cin >> year;

            titleTable.deleteMovie(DelMovieName);
            yearTable.deleteMovie(year, DelMovieName);
            //Because we might the sane year for movies
        }
    else if(selection == 3)
        {
            string FindMovieName;
            int year;

            cout << "Enter title:" << endl;
            cin >> FindMovieName;
            cout << "Enter year: " << endl;
            cin >> year;

            titleTable.findMovie(FindMovieName);
            yearTable.findMovie(year);
        }
    else if(selection == 4)
        {
            cout << "This hashes by title " << endl;
            titleTable.printTableContents();
            cout << endl;
            cout << endl;
            cout << "This hashes by year" << endl;
            yearTable.printTableContents();
        }
    else if(selection == 5)
        {
            cout << "What would you want to search?" << endl;

            // Put the submenu method in this class
            // instead of the Movie class, and then
            // have this method call the submenu method.
            do
            {
                int subselection = getSubMenu();
                if(subselection >= 1 && subselection <= 2)
                {
                    selection = handleSubMenu(subselection);
                    if(subselection == 2)
                    {
                        break;
                    }
                }
            }while(selection);
        }
    else if(selection == 6)
        {
            cout << "Goodbye!" << endl;
        }
    else
        {
            cout << "Invalid selection!" << endl;
        }
}

