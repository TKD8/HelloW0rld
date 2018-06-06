#ifndef COMMAND_H
#define COMMAND_H
#include "movie.h"

class Customer;
class Command
{
public:
    // Constructor, Destructor, and Copy Constructor
    Command();
    Command(const Command&);
    virtual ~Command();
    // Sets the data of the Inventory item
    virtual bool setData(string movie, Inventory* item, Customer* customerAction);
    // displays the command type to the user
    virtual void display() const;
    // creates an empty Command object
    virtual Command* create();
    // getter methods
    string getMovieType();
    string getCommand();
    Inventory* getItem() const;
protected:
    // Command type of the object. Only 3 kinds
    string cmdType;

    string movieType;
    // Inventory pointer object to modify when needed
    Inventory *anItem;
};

#endif
