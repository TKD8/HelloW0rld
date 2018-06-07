#include "bintree.h"


//---------------------------------------------------------------------------
// Default constructor: Takes in no parameters
// and creates empty tree with NULL root
BinTree::BinTree() : root(NULL)
{
}


//---------------------------------------------------------------------------
// Copy Constructor: takes an existing tree and copies every node in that tree
// to new copy tree.
BinTree::BinTree(const BinTree & treeCopied)
{
}



//---------------------------------------------------------------------------
// Destructor: Clears memeory for binary tree by calling makeEmpty function.
BinTree::~BinTree()
{
    makeEmpty();
}


//---------------------------------------------------------------------------
// makeEmpty: Makes an empty tree by calling destroyTree,
// a recursive helper method
void BinTree::makeEmpty()
{
    destroyTree(root);
}

//---------------------------------------------------------------------------
// destroyTree: destroyTree goes thorugh a tree and destroys all nodes
// by recursively going through the left and right part of the tree
void BinTree::destroyTree(Node*& cur)
{
    if (cur != NULL)
    {
        // go through cur's left and right paths
        destroyTree(cur->left);
        destroyTree(cur->right);
        // correctly delete the cur memory
        delete cur->movieData;
        cur->movieData = NULL;
        delete cur;
        cur = NULL;
    }

}

//---------------------------------------------------------------------------
// isEMpty: returns bool value whether or not tree is empty
bool BinTree::isEmpty() const
{
    return (root == NULL);
}


//---------------------------------------------------------------------------
// retrieve: function returns bool value if NodeData that is being searched
// for, dataSearch, is found in the tree.
// retrieveHelper: helper method for retrieve. retrieveHelper recursively
// goes through tree looking for dataSearch
bool BinTree::retrieve(const Inventory &dataSearch, Inventory*& dataReturn) const
{
    retrieveHelper(root, dataSearch, dataReturn);

    // if dataReturn was found and changed, return true
    // otherwise if not changed then return false
    if (dataReturn != NULL)
        return true;
    else
        return false;

}

void BinTree::retrieveHelper(Node* cur, const Inventory &dataSearch,
    Inventory*& dataReturn) const
{
    // if cur remainds unchanged, then return NULL
    if (cur == NULL)
        dataReturn = NULL;
    // if dataSearch is found, then set cur
    else if (dataSearch == *cur->movieData)
        dataReturn = cur->movieData;
    // look through the left part of tree
    else if (dataSearch < *cur->movieData)
        retrieveHelper(cur->left, dataSearch, dataReturn);
    // look through the right part of the tree
    else
        retrieveHelper(cur->right, dataSearch, dataReturn);
}

//---------------------------------------------------------------------------
// insert: function inserts new Inventory into the tree with its data ptr
// = to newData
// Will return to user if the node was inserted into the tree
bool BinTree::insert(Inventory *newMovie, const int numInsert)
{
    // create Node to link to Inventory parameter
    Node* newPtr = new Node;
    newPtr->movieData = newMovie;
    // when inserting, set the max copies for the movie
    newPtr->movieData->setMaxCopies(numInsert);
    newMovie = NULL;
    newPtr->left = newPtr->right = NULL;
    // if tree is empty then make root = to created Node
    if (isEmpty())
        root = newPtr;
    else
    {
        Node* cur = root;
        bool insertFlag = false;

        // go thorugh
        while (!insertFlag)
        {
            // checks if the item already exists, removes pointer if it does
            if (*newPtr->movieData == *cur->movieData)
            {
                delete newPtr;
                newPtr = NULL;
                return false;
            }
            // found the leaf, insert on the left and ends
            else if (*newPtr->movieData < *cur->movieData)
            {
                if (cur->left == NULL)
                {
                    cur->left = newPtr;
                    insertFlag = true;
                }
                // goes left
                else
                    cur = cur->left;
            }
            // found the leaf, insert on the right and ends
            else
            {
                if (cur->right == NULL)
                {
                    cur->right = newPtr;
                    insertFlag = true;
                }
                // goes right
                else
                    cur = cur->right;
            }
        }
    }

    // got to end, so return true
    return true;
}


//---------------------------------------------------------------------------
// operator<<: overloaded << to print out data of Nodes in order
// inOrderPrint: recursive helper method that goes through BST and prints
// out the data in order
ostream& operator<<(ostream& out, const BinTree& bst)
{
    // checks if empty tree
    if (bst.isEmpty())
        out << "Empty tree" << endl;
    // otherwise run helper method to recursively print everything
    else {
        bst.inOrderPrint(bst.root);
        out << endl;

    }
    return out;
}


void BinTree::inOrderPrint(Node *cur) const
{
    // if node isn't null, goes through left and right and subtree and
    // prints out data
    if (cur == root)
    {
        cur->movieData->displayHeader();
    }
    if (cur != NULL)
    {
        inOrderPrint(cur->left);
		cout << right << setw(2) << cur->movieData->getCurAmount() << " ";
		cur->movieData->display();
        inOrderPrint(cur->right);
    }
}

BinTree::Node * BinTree::getRoot() const
{
	return this->root;
}
