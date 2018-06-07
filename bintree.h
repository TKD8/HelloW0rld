#pragma once
#include "movie.h"
#include <iomanip>
class BinTree {

    // overloaded << operator to display BST
    friend ostream& operator<<(ostream&, const BinTree&);
    struct Node;

public:
    // constructors/destructors
    BinTree();
    // copy constructor
    BinTree(const BinTree &);
    ~BinTree();

    Node * getRoot() const;
    // checks if tree is empty or not, true is empty, false if not
    bool isEmpty() const;
    // make the tree empty so isEmpty returns true
    void makeEmpty();
    // assignment operator
    //BinTree& operator=(const BinTree &);
    // comparison operators
    //bool operator==(const BinTree &) const;
    //bool operator!=(const BinTree &) const;
    // inserts data into the tree
	bool insert(Inventory*, const int);
    // retrieves NodeData from tree
    bool retrieve(
        const Inventory&, Inventory*&
    ) const;
    // print out the tree in order
    void inOrderPrint(Node*) const;


private:
    // Node structure
    struct Node {
        Inventory* movieData;  // pointer to data object
        Node* left;      // left subtree pointer
        Node* right;     // right subtree pointer
    };
    Node* root;      // root of the tree
    // utility functions-----------------------

    // destroys content of tree
    void destroyTree(Node*&);
    // recursive helper method for retrieve function
    void retrieveHelper(Node*, const Inventory&, Inventory*&) const;
    // recursive helper method for == operator
    bool equalCheck(Node*, Node*) const;

};
