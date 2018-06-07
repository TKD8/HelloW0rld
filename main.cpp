#include "movie.h"
#include "store.h"

using namespace std;

int main()
{
    // Name for library
    Store  storeManager("Best Store ");
    // Take in input files and set them
    ifstream infile1("data4customers.txt");
    ifstream infile2("data4movies.txt");
    ifstream infile3("data4commands.txt");
    // if files are incorrect
    if (!infile1 || !infile2 || !infile3)
    {
        cout << "File could not be opened" << endl;
        return 1;
    }
    // Create patron, inventory, and execute commands
    storeManager.createCustomers(infile1);
    storeManager.createInventory(infile2);
    storeManager.doCommands(infile3);

    return 0;

}
