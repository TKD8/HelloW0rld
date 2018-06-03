#include <iostream>
#include <ostream>
#include <string>

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

    virtual string getItem() const;
    void setMaxCopies();
    void increaseCopies();
    void decreaseCopies();
    int getMaxAmount();
    int getCurAmount();

    virtual bool operator==(const Inventory&) const = 0;
    virtual bool operator<(const Inventory&) const = 0;
    virtual Inventory* create() = 0;

private:
    int maxStock;
    int stockNum;

};
