#include "comedy.h"

Comedy::Comedy() : Movie(), GENRE("Comedy")
{

}

Comedy::Comedy(const Comedy& rhs)
{
    title = rhs.title;
    director = rhs.director;
    year = rhs.year;
}

Comedy::~Comedy()
{
}

void Comedy::display() const
{
    cout << left << setw(22) << title << " " << setw(18) << director << " "
    << setw(5) << year << endl;
}

void Comedy::displayHeader() const
{
    cout << "AVAIL TITLE                DIRECTOR            YEAR " << endl;
    cout << "--------------------------------------------------------------"
    << "-----------------" << endl;

}

void Comedy::setData(istream& infile)
{
    infile.get();
    getline(infile, title, ',');

    infile.get();
    getline(infile, director, ',');

    infile.get();
    infile >> year;
}

void Comedy::setData2(istream& infile)
{
    infile.get();
    getline(infile, title, ',');

    infile >> year;
}

bool Comedy::operator==(const Inventory& rhs) const{
    const Comedy ComedyMovie = static_cast<const Comedy&>(rhs);
    return (title == ComedyMovie.title && year == ComedyMovie.year);
}

bool Comedy::operator<(const Inventory& rhs) const
{
    const Comedy ComedyMovie = static_cast<const Comedy&>(rhs);

    if (title < ComedyMovie.title)
        return true;
    else if (title == ComedyMovie.title)
        return (year < ComedyMovie.year);
    else
        return false;
}

Inventory * Comedy::create()
{
    return new Comedy();
}
