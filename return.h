#include "command.h"

class Customer;
class Return : public Command {
public:
    // Constructor, Copy Constructor and Destructor
    Return();
    Return(const Return&);
    virtual ~Return();
    // sets the Data of the book by increasing it's current stock value
    virtual bool setData(string, Inventory*, Customer*);
    // displays command type info for the Patron history output
    virtual void display() const;
    // Creates an empty Command object, mainly used by Factory class
    virtual Command* create();
};
