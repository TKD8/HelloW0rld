#include "command.h"

class Customer;
class Borrow : public Command {
public:
    // Constructor, Copy Constructor and Destructor
    Borrow();
    Borrow(const Borrow&);
    virtual ~Borrow();
    // sets the Data of the book by increasing it's current stock value
    virtual bool setData(string, Inventory*, Customer*);
    // displays command type info for the Patron history output
    virtual void display() const;
    // Creates an empty Command object, mainly used by Factory class
    virtual Command* create();
};
