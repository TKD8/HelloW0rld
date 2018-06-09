#include "return.h"


//----------------------------------------------------------------------------
// Default constructor: sets the command type as Return by default
Return::Return() : Command()
{
    cmdType = "Return";
}

//----------------------------------------------------------------------------
// Copy constructor: copies the inputted Return object to the current
// Return object. Assumes the other Return object has valid data to copy
// from
Return::Return(const Return& rhs)
{
    cmdType = rhs.cmdType;
    movieType = rhs.movieType;
    anItem = rhs.anItem;
}

//----------------------------------------------------------------------------
// Destructor: deallocates unused Checkout objects
Return::~Return()
{
}

//----------------------------------------------------------------------------
// setData(): takes in the movie Type and the Inventory item and sets it data
// In this case, it increases the copy if the movie Type is valid and if the
// current amount is less than 10. If it isn't, an error is displayed
// and the method is return false to indicate it didn't go through
bool Return::setData(string movie , Inventory* item, Customer* customerAction)
{
    if (item != NULL)
    {
		movieType = movie ;
		anItem = item;
		if (movieType != "" && anItem->getCurAmount() != 10)
			anItem->increaseCopies();
		else
		{
			cout << "Can't return a movie  that hasn't " <<
				"been borrowed or too many copies" << endl;
			return false;
		}
    }
    return true;

}

//----------------------------------------------------------------------------
// display(): Displays the command type for the Customer history output
void Return::display() const
{
    cout << movieType << " " << cmdType << " ";
}

//----------------------------------------------------------------------------
// create(): Creates an empty Return object for the user. Mostly used by
// the factory class to create empty objects from the text file.
Command* Return::create()
{
    return new Return();
}
