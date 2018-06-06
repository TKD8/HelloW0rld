#include "customer.h"

Customer::Customer() : id(0), firstName(""), lastName("")
{
    commandHistory.reserve(10);
}

Customer::Customer(istream& infile)
{
    setData(infile);
}

Customer::Customer(const Customer& rhs)
{
    id = rhs.id;
    firstName = rhs.firstName;
    lastName = rhs.lastName;
}

Customer::~Customer()
{}

void Customer::setData(istream& infile)
{
    infile >> id;
    if (infile.eof())
        return;
    infile.get();
    infile >> lastName;
    infile.get();
    infile >> firstName;
}

void Customer::addCommand(Command cmd)
{
    commandHistory.push_back(cmd);
}

int Customer::getCID() const
{
    return id;
}

string Customer::getLastName() const
{
    return lastName;
}

string Customer::getFirstName() const
{
    return firstName;
}


void Customer::displayCustomerHistory() const
{
    cout << "*** Customer ID: " << id << " " << lastName << ", " << firstName
        << endl;
    int size = commandHistory.size();
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            commandHistory[i].display();
            commandHistory[i].getItem()->display();
        }
        cout << endl;
    }
    else
        cout << "No history for Customer" << endl;
    cout << endl;
}

void Customer::display() const
{
    displayCustomerHistory();
}

bool Customer::operator==(const Customer& rhs) const
{
    return (id == rhs.id);
}

bool Customer::operator!=(const Customer& rhs) const
{
    return (id != rhs.id);
}
