#include "hashtable.h"

//----------------------------------------------------------------------------
// Default constructor: Initializes the inventory and sets up each movie genre
// and command type in it's arrays.
HashTable::HashTable()
{

	setUpInventory();
    // Each index of the array corresponds to the letter the data file is
    // passing in to indicate which movie genre or command it is
    // After converting the ch to an int value, all genres and commands
    // will go into it's specified array

    cmdInventory[1] = new Borrow();
    cmdInventory[7] = new History();
    cmdInventory[17] = new Return();
    movieType[3] = "DVD";
    storeMovie[3] = new Drama();
    storeMovie[5] = new Comedy();
    storeMovie[2] = new Classic();

}

//----------------------------------------------------------------------------
// Destructor: goes through the Inventory list of the Library and
// disconnects all the objects in the array and deletes them.
HashTable::~HashTable()
{
    for (int i = 0; i < MAX_CMD; i++)
    {
        if (storeMovie[i] != NULL)
        {
            delete storeMovie[i];
            storeMovie[i] = NULL;
        }

        if  (cmdInventory[i] != NULL)
        {
            delete cmdInventory[i];
            cmdInventory[i] = NULL;
        }
    }
}

//----------------------------------------------------------------------------
// getBookType: gets the movie Type of the object and returns it back to the user
string HashTable::getMovieType(char ch)
{
    return movieType[hash(ch)];
}

//----------------------------------------------------------------------------
// createBook: creates an empty movie object for the Library. First it checks
// if the inputted char from the data file corresponds to any of the genre
// arrays and if it isnt null. If not, then it creates the empty movie genre obj
Inventory *HashTable::createMovie(char ch, istream& infile)
{
    string tmp;

    int sub = hash(ch);
    if (storeMovie[sub] == NULL)
    {
        getline(infile, tmp, '\n');
        return NULL;
    }
    else
        return storeMovie[sub]->create();
}

//----------------------------------------------------------------------------
// createCommand: creates an empty command obj for the Library. First it checks
// if the inputted char from the data file corresponds to any of the cmd
// arrays and if it isnt null. If not, then it creates the empty command obj
Command *HashTable::createCommand(char ch, istream& infile)
{
    string tmp;

    int sub = hash(ch);
    if (cmdInventory[sub] == NULL)
    {
        getline(infile, tmp, '\n');
        return NULL;
    }
    else
        return cmdInventory[sub]->create();
}

//----------------------------------------------------------------------------
// hash: Takes in a char and then converts it into an int so the HashTable
// can determine which object it needs to create
int HashTable::hash(char ch) const
{
    if (ch < 'a')
        return ch - 'A';
    else
        return 0;
}

// convToSubscript: a helper method for hash to determine what int the char
// is so the factory can create an object
int HashTable::convToSubscript(char ch)
{
    return hash(ch);
}

//----------------------------------------------------------------------------
// setUpInventory: sets up the hash table by initializing it's variables
void HashTable::setUpInventory()
{
    for (int i = 0; i < MAX_CMD; i++)
    {
		storeMovie[i] = NULL;
        cmdInventory[i] = NULL;
        movieType[i] = "";
    }
}
