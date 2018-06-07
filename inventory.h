#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>

using namespace std;
class Inventory
{
public:
    Inventory();
    Inventory(const Inventory&);
    virtual ~Inventory();

    virtual void display() const = 0;
    virtual void displayHeader() const = 0;

    virtual void setData(istream& infile) = 0;
    virtual void setData2(istream&) = 0;


    void setMaxCopies(const int maxCopy);
    void increaseCopies();
    void decreaseCopies();
    int getMaxAmount();
    int getCurAmount();
    virtual string getItem() const = 0;

    virtual bool operator==(const Inventory&) const = 0;
    virtual bool operator<(const Inventory&) const = 0;
    virtual Inventory* create() = 0;

private:
    int maxStock;
    int stockNum;

};

#endif
