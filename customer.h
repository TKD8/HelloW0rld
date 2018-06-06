using namespace std;
#include "movie.h"
#include "command.h"
#include <iostream>
#include <vector>
#include <string>

class Customer
{
public:
    // constructors and destructor
    // constructor with ifstream will take in data from the data file for
    // customers and call setData
    Customer();
    Customer(istream&);
    Customer(const Customer&);
    virtual ~Customer();

    // takes in the data file for customers and then sets its variables
    // with the corresponding customer files
    void setData(istream&)

    // simple getter methods to get Customer information
    int getCID() const;
    string getFirstName() const;
    string getLastName() const;

    // display information methods
    // displayng the customer history pseudo-code:
    /*
    get size of vector
    if there are commands
    for loop through vector and display items in the vector
    else say it's empty
    */
    void displayCustomerHistory() const;
    // adds a command to the command vector by pushing it into the vector
    void addCommand(Command);
    virtual void display() const;
    // overloaded operators to compare customers
    virtual bool operator==(const Patron& rhs) const;
    virtual bool operator!=(const Patron& rhs) const;
private:
    // id of the customer
    int id;
    // variables for their names
    string firstName;
    string lastName;
    // vector to hold in the history of the commands that the customers make
    //
    vector<Command> commandHistory;
};
