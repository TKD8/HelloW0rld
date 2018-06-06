#include "movie.h"
#include "command.h"

//---------------------------------------------------------------------------
// Default constructor: sets the command of the command movie object by default
Command::Command() : cmdType("Command"), movieType(""), anItem(NULL)
{
}

//---------------------------------------------------------------------------
// Copy constructor: Copies the inputted Command  object to the current
// Command object. Assumes the inputted object has correct values
Command::Command(const Command& rhs)
{
    cmdType = rhs.cmdType;
    movieType = rhs.movieType;
    anItem = rhs.anItem;
}

//---------------------------------------------------------------------------
// Destructor: deallocates unused Command objects
Command::~Command()
{
}

//-----------------------------------------------------------------------------
//setData(): takes in an input file and then sets the movieType (Hardcopy), and
// which item of the Inventory it is
// of the command object according to the input file.
// Assumes that the input file is a valid file and that there is
// a command object to set it's attributes.
bool Command::setData(string movie, Inventory* item, Customer *patronAction)
{
    movieType = movie;
    anItem = item;
    return true;
}

//----------------------------------------------------------------------------
// display(): Displays the command type for the Customer history output
void Command::display() const
{
    cout << cmdType << ": ";
}

//----------------------------------------------------------------------------
// create(): Creates an empty Checkout object for the user. Mostly used by
// the factory class to create empty objects from the text file.
Command* Command::create()
{
    return new Command();
}

//----------------------------------------------------------------------------
// getBookType: returns the movieType of the objecct, which of this assn
// is only Hardcopy. Assumes there is a movieType to return
string Command::getMovieType()
{
    return movieType;
}

//----------------------------------------------------------------------------
// getCommand(): gets the Command type of the object and returns it to the user
// Assumes there is a command type to return
string Command::getCommand()
{
    return cmdType;
}

//----------------------------------------------------------------------------
// getItem(): get a pointer to the item the commmand object is holding.
// assumes there is an item to retrieve from the object
Inventory* Command::getItem() const
{
    return anItem;
}
