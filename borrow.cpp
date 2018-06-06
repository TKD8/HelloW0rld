#include "borrow.h"

//----------------------------------------------------------------------------
// Default constructor: sets the command type as Borrow by default
Borrow::Borrow() : Command()
{
    cmdType = "Borrow";
}

//----------------------------------------------------------------------------
// Copy constructor: copies the inputted Borrow object to the current
// Borrow object. Assumes the other Borrow object has valid data to copy
// from
Borrow::Borrow(const Borrow& rhs)
{
    cmdType = rhs.cmdType;
    movieType = rhs.movieType;
    anItem = rhs.anItem;
}

//----------------------------------------------------------------------------
// Destructor: deallocates unused Borrow objects
Borrow::~Borrow()
{
}

//----------------------------------------------------------------------------
// setData(): takes in the movieType and the Inventory item and sets it data
// In this case, it decreases the copy if the movieType is valid and if the
// current amount is higher than 0. If it isn't, an error is displayed
// and the method is return false to indicate it didn't go through
bool Borrow::setData(string movie , Inventory* item, Customer* customerAction)
{
    // check if item exists
	if (item != NULL)
	{
		movieType = movie ;
		anItem = item;
        // check to see if there's a movieType and that the current val is > 0
		if (movieType != "" && anItem->getCurAmount() > 0)
			anItem->decreaseCopies();
        // current val is 0, thus cant checkout so display error to user
        else
		{
			cout << "ERROR: No more copies left" << endl;
			return false;
		}
	}
    return true;

}

//----------------------------------------------------------------------------
// display(): Displays the command type for the Customer history output
void Borrow::display() const
{
    cout << cmdType << " ";
}

//----------------------------------------------------------------------------
// create(): Creates an empty Borrow object for the user. Mostly used by
// the factory class to create empty objects from the text file.
Command* Borrow::create()
{
    return new Borrow();
}
