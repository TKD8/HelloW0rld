class Movie;
class Command;
const int MAX_CMD = 26;
#include "command.h"
#include "drama.h"
#include "comedy.h"
#include "history.h"
#include "return.h"
#include "borrow.h"
#include "classic.h"
#include <iostream>
#include <string>
using namespace std;

class HashTable
{
public:
    // Constructor and destructor
    // hashTable constructor will set up two arrays that will have its indexes
    // correspond with the specific genre or
    // specific commands that the data translates to after
    // convToSubscript
    HashTable();
    // clears the array
    ~HashTable();
    // Create empty object commands
    // both methods follow this pseudo:
    /*
    hash the ch of the command being passed in
    store into an int var
    if its null then return null
    otherwise return the array at the hashed int and create a new order or movie
    */
    Inventory *creatMovie(char, istream&);
    Command *createCommand(char, istream&);
    // Gets array int from method
    int convToSubscript(char);
    // gets the bookType from the object
    string getMovieType(char);

private:
    // Arrays to create objects depending on what the subscript is
    Inventory *storeMovie[MAX_CMD];
    Command *cmdInventory[MAX_CMD];
    string movieType[MAX_CMD];
    // gets an int from a char
    // does this by doing:
    // if ch < a
    // then return ch - 'A'
    int hash(char) const;
    // Sets up values for the array
    void setUpInventory();
};
