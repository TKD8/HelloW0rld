#include "classic.h"

Classic::Classic() : Movie(), GENRE("Classic"), month(0), firstName(""),
                                                                lName("")
{

}

Classic::Classic(const Classic& rhs)
{
    title = rhs.title;
    director = rhs.director;
    year = rhs.year;
    month = rhs.month;
    firstName = rhs.firstName;
    lName = rhs.lName;
}

Classic::~Classic()
{
}

void Classic::display() const
{
    cout << left << setw(22) << title << " " <<  setw(3) <<
    month << " " << setw(5) << year << " "
    << firstName << lName << endl;
}

void Classic::displayHeader() const{
    cout << "AVAIL TITLE                DIRECTOR            YEAR " << endl;
    cout << "--------------------------------------------------------------"
    << "-----------------" << endl;
}

void Classic::setData(istream& infile)
{

    infile.get();
    getline(infile, director, ',');
    infile.get();
    getline(infile, title, ',');
    infile.get();
    infile >> firstName >> lName;
    infile >> month >>  year;
}

void Classic::setData2(istream& infile)
{
    infile >> month;
    infile >> year;
    infile >> firstName;
    infile >> lName;
}

bool Classic::operator==(const Inventory& rhs) const{
    const Classic classicMovie = static_cast<const Classic&>(rhs);
    return (year == classicMovie.year && month == classicMovie.month
    && firstName == classicMovie.firstName && lName == classicMovie.lName);
}

bool Classic::operator<(const Inventory& rhs) const
{
    const Classic classicMovie = static_cast<const Classic&>(rhs);

    if (year < classicMovie.year)
        return true;
    else if (year == classicMovie.year)
    {
        if (firstName < classicMovie.firstName)
            return true;
        else if (firstName == classicMovie.firstName)
            return (lName < classicMovie.lName);
        else
            return false;
    }
    else
        return false;
}

Inventory * Classic::create()
{
    return new Classic();
}
