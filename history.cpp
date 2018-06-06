#include "history.h"
#include "customer.h"

//----------------------------------------------------------------------------
// Default constructor: sets the command type as History by default
History::History() : Command()
{
    cmdType = "History";
}

//----------------------------------------------------------------------------
// Copy constructor: copies the inputted History object to the current
// History object. Assumes the other History object has valid data to copy
// from
History::History(const History& rhs)
{
    cmdType = rhs.cmdType;
    movieType = rhs.movieType;
    anItem = rhs.anItem;
}

//----------------------------------------------------------------------------
// Destructor: deallocates unused Checkout objects
History::~History()
{
}

//----------------------------------------------------------------------------
// setData(): takes in the movieType and the Inventory item and sets it data
// In this case, it just takes the Customer pointer object and displays it's
// history by using the displayCustomerHistory method in the Customer class
bool History::setData(string book, Inventory* item, Customer* customerAction)
{
    customerAction->displayCustomerHistory();
    return false;

}

//----------------------------------------------------------------------------
// create(): Creates an empty Customer object for the user. Mostly used by
// the factory class to create empty objects from the text file.
Command* History::create()
{
    return new History();
}
