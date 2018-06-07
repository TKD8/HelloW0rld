#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "customer.h"
#include "hashtable.h"
#include "bintree.h"
// max amount of customers for list
const int MAX_CUSTOMERS = 10000;
// max amount of inventory for list
const int MAX_INVENTORY = 55;


using namespace std;

class Store
{
public:
    // Constructor, Copy Constructor, and Destructor
    Store();
    Store(string);
    Store(const Store&);
    ~Store();
    // creator methods
    void createCustomers(istream&);
    void createInventory(istream&);
    // executs the commands
    void doCommands(istream&);
    // displays the inventory
    void displayCatalog() const;
    // looks for the customer in the list
    bool customerFound(int) const;
    // gets the specific customer
    Customer getCustomer(const int) const;
    // gets the store name
    string getStoreName() const;

private:
    // arrray of customers
    Customer customerList[MAX_CUSTOMERS];
    // BST to hold the movies
    BinTree inventoryList[MAX_INVENTORY];
    // command history vector to hold commands
    vector<Command> storeCommandHistory;
    // Factory to make objects
    HashTable hash;
    // name of store
    string name;

};
