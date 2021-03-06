#include "movie.h"

using namespace std;
#include <string>
class Classic : public Movie
{
public:
    // Constructor, Copy Constructor, and Destructor
    Classic();
    Classic(const Classic& rhs);
    ~Classic();
    // Displays the movie info to the user
    virtual void display() const;
    virtual void displayHeader() const;
    // takes in the text file and sets the data of the Movie object
    // according to what is inside the data file
    // setData psuedo for most genres would be:
    /*
    infile.get
    getline(infile, director/title/etc, ',')
    repeat above lines and set data for specific variables for the genre
    */
    virtual void setData(istream& infile);
    virtual void setData2(istream&);
    // Overloaded opereator methods
    virtual bool operator==(const Inventory&) const;
    virtual bool operator<(const Inventory&) const;
    // Creates an empty object to fill in
    virtual Inventory * create();

private:
    // genre tag for the movie
    const string GENRE;
    // tags for the classic genre
    int month;
    string firstName, lName;
};
