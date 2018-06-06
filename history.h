#include "command.h"

class Customer;
class History : public Command {
public:
    // Constructor, Copy Constructor and Destructor
    History();
    History(const History&);
    virtual ~History();
    // sets the Data of the book by increasing it's current stock value
    virtual bool setData(string, Inventory*, Customer*);
    // Creates an empty Command object, mainly used by Factory class
    virtual Command* create();
};
