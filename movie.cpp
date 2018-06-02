#include "movie.h"

Movie::Movie() : Inventory(), title(""), director(""), year(0)
{

}

Movie::Movie(const Movie& rhs)
{
    title = rhs.title;
    director = rhs.director;
    year = rhs.year;
}

Movie::~Movie()
{
}

void Movie::display() const
{
    cout << title << " " << director << " " << year << endl;
}

void Movie::displayHeader() const{
    cout << "******* Movie ITEM *******" << endl;
}

void Movie::setData(istream& infile)
{
    infile.get();
    getline(infile, director, ',');

    infile.get();
    getline(infile, title, ',');

    infile.get();
    infile >> year;
}

string Movie::getTitle()
{
    return title;
}

string Movie::getdirector()
{
    return director;
}

int Movie::getYear()
{
    return year;
}

string Movie::getItem() const {
    return title;
}
