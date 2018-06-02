#include "drama.h"

Drama::Drama() : Movie(), GENRE("Drama")
{

}

Drama::Drama(const Drama& rhs)
{
    title = rhs.title;
    director  = rhs.director ;
    year = rhs.year;
}

Drama::~Drama()
{
}

void Drama::display() const
{
    cout << left << setw(22) << title << " " << setw(18) << director  << " "
    << setw(5) << year << endl;
}

void Drama::displayHeader() const{
    cout << "AVAIL DIRECTOR                 TITLE
    YEAR " << endl;
    cout << "--------------------------------------------------------------
    -----------------" << endl;
}

void Drama::setData(istream& infile)
{
    infile.get();
    getline(infile, director , ',');

    infile.get();
    getline(infile, title, ',');

    infile.get();
    infile >> year;
}

void Drama::setData2(istream& infile)
{
    infile.get();
    getline(infile, director , ',');

    infile.get();
    getline(infile, title, ',');
}

bool Drama::operator==(const Inventory& rhs) const{
    const Drama DramaMovie = static_cast<const Drama&>(rhs);
    return (title == DramaMovie.title && director  == DramaMovie.director );
}

bool Drama::operator<(const Inventory& rhs) const
{
    const Drama DramaMovie = static_cast<const Drama&>(rhs);

    if (director  < DramaMovie.director )
        return true;
    else if (director  == DramaMovie.director )
        return (title < DramaMovie.title);
    else
        return false;
}

Inventory * Drama::create()
{
    return new Drama();
}
