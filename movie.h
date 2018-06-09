/* movie.h
controls all of the different genres of movies
is stored in the inventory
the factory can create a movie object
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <ostream>
#include <string>
#include "inventory.h"
using namespace std;
class Movie : public Inventory
{

public:

    // constructors and destructor
    Movie();
    Movie(const Movie& rhs);
    ~Movie();

    // display method for header to show that it's displaying movies
    // and another display method for outputting the movie variables
    virtual void display() const;
    virtual void displayHeader() const = 0;

    // siumple getter/setter methods to get the object's variables
    virtual string getItem() const;
    string getDirector();
    string getTitle();
    int getYear();

    //  overloaded operators to compare two book/genre objects
    // used for BST operations so it knows where to isnert what
    // compares by comparing titles or directors of the object depending
    // on the genre
    virtual bool operator==(const Inventory&) const = 0;
    virtual bool operator<(const Inventory&) const = 0;

    // create method for Inventory class to create a specific genre of movie
    // object
    virtual Inventory* create() = 0;

    // takes in the text file and sets the data of the Movie object
    // according to what is inside the data file
    // setData psuedo for most genres would be:
    /*
    infile.get
    getline(infile, director/title/etc, ',')
    repeat above lines and set data for specific variables for the genre
    */
    virtual void setData(istream& infile);


protected:
    string title;
    string director;
    int year;
    string stock;

};
#endif
