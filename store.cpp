#include "store.h"

//---------------------------------------------------------------------------
// Default constructor: sets the name of the Store
Store::Store() :name("")
{

}

//---------------------------------------------------------------------------
// Default constructor: sets the name of the Store
Store::Store(string title) : name(title)
{

}

//---------------------------------------------------------------------------
// Copy constructor
Store::Store(const Store& rhs )
{

}

//---------------------------------------------------------------------------
// Destructor
Store::~Store()
{

}


//---------------------------------------------------------------------------
// createInventory: creates the inventory of the Store by taking in the files
// and analyzing the char in the command. It passes the char to the hash
// where the hash makes the corresponding movie object
void Store::createInventory(istream& infile)
{
    char movieChar = ' ';
    // do until end of file
    for(;;)
    {
        // get movie char command
        infile >> movieChar;

        if (infile.eof())
            break;
        // create the corresponding movie (if possible)
        Inventory *movieInventory = hash.createMovie(movieChar, infile);
        // if not null then set the data of the movie given by the file
        if (movieInventory != NULL)
        {
            movieInventory->setData(infile);
			bool inInventory = inventoryList[hash.convToSubscript(movieChar)]
            .insert(movieInventory, 10);


            // display if not inserted into the BST
            if (!inInventory)
            {
                cout << inInventory << endl;
				cout << movieInventory->getItem();
                delete movieInventory;
                cout << "Not inserted" <<  endl;
                break;

            }
            // test code
			else
			{
				//cout << movieInventory->getItem() << " inserted" << endl;
			}
        }
        // deallocate when done
        movieInventory = NULL;
        delete movieInventory;

    }
}

//---------------------------------------------------------------------------
// createCustomers: take in an input file and create the customer list array
// assumes the input file is correct
void Store::createCustomers(istream& infile)
{
    // do until end of file
    for (;;)
    {
        // create a new customer to set the data
        Customer* pat = new Customer();
        pat->setData(infile);

        if (infile.eof())
        {
            delete pat;
            pat = NULL;
            break;

        }
        // set the customer object
        customerList[pat->getCID()] = *pat;
        // delete when done
        delete pat;
        pat = NULL;
    }
}

//---------------------------------------------------------------------------
// doCommands: take in an input file and executes the commands in the text
// file. Assumes the input is correct
void Store::doCommands(istream& infile) {
	char cmdCh = ' ';
	char movieCh = ' ';
	char bTC = ' ';
	int custID = 0;
	bool found = false;
	string movieType = "";
	char EOL = '\n';
	Inventory *itemLoc = NULL;
	Customer *tempCustomer = NULL;
	Inventory *tempItem = NULL;

	for (;;)
    {
		infile >> cmdCh;
		if (infile.eof()) break; //check for end of file
        // display command
		if (cmdCh == 'S')
        {
			displayCatalog();
			cmdCh = ' ';
		}
        // invalid format type defined by specs
		else if (cmdCh == 'Z')
		{
			cout << "ERROR: Invalid format type Z";
			cout << endl;
		}
		else if (infile.get() == EOL)
			cmdCh = ' ';
		else
        {
				Command * processedTran = hash
				.createCommand(cmdCh, infile);
            // if command char is legit
			if (processedTran != NULL)
            {
				infile >> custID;


				if (infile.eof()) break;
                // customer exists
				if (customerFound(custID))
				{
					tempCustomer = &customerList[custID];
                    // set up the history of the customer
					bool isHistory = processedTran->
						setData(movieType, itemLoc, tempCustomer);
                    // check the file again
					if (infile.get() != EOL && isHistory)
                    {

                        // take in movie command and movie type command
						infile >> movieCh;
						tempItem = hash.createMovie (movieCh, infile);
						infile >> bTC;
						movieType = hash.getMovieType(bTC);
                        // movie genre exists
						if (movieType != "")
						{
                            // set the data for the movie and see if it's
                            // in the list
							if (tempItem != NULL)
							{
								tempItem->setData2(infile);

								found = inventoryList[hash.
									convToSubscript(movieCh)].
									retrieve(*tempItem, itemLoc);
                                // error if movie not in list
								if (found == false)
								{
									cout << "ERROR: Invalid Movie Request!: "
										<< tempItem->getItem() << endl;
								}
								delete tempItem;
								tempItem = NULL;
                                // check again
								bool found2 = processedTran->
									setData(movieType, itemLoc, tempCustomer);

								if ((found && found2) && movieType != "")
                                {
									customerList[custID]
										.addCommand(*processedTran);

								}
								delete processedTran;
								processedTran = NULL;

							}
						else
						{
								cout << "ERROR: Genre: " << movieCh
									<< " not Found!" << endl;

								if (processedTran != NULL)
									delete processedTran;
								processedTran = NULL;
						}

							string temp;
							getline(infile, temp, EOL);
							delete tempItem;
							tempItem = NULL;

						}
						else
						{
							string temp;
							getline(infile, temp, EOL);

							cout << "ERROR: Invalid Movie Genre " << bTC <<
                            endl;

							if (processedTran != NULL)
								delete processedTran;
							processedTran = NULL;
						}
					}
					else
                    {
						if (processedTran != NULL)
							delete processedTran;
						processedTran = NULL;
					}
				}
				else
                {
					cout << "Error: Invalid Customer ID " << custID << endl;

					if (processedTran != NULL)
						delete processedTran;
					processedTran = NULL;

					string temp;
					getline(infile, temp, EOL);
				}
			}
			else {
				cout << "ERROR: Invalid Command Code " << cmdCh << endl;

				if (processedTran != NULL)
					delete processedTran;
				processedTran = NULL;
			}
		}

		found = false;
		custID = 0;
		itemLoc = NULL;
		tempCustomer = NULL;
		tempItem = NULL;
	}
}

//---------------------------------------------------------------------------
// customerFound: find the customer in the list
bool Store::customerFound(int IDNum) const
{
    if (customerList[IDNum].getCID() == -1)
        return false;
    else
        return true;
}

//---------------------------------------------------------------------------
// displayCatalog: display the inventory
void Store::displayCatalog() const
{
	if (name != "")
	{
		cout << "----------------------------------------------" << endl;
		cout << "Inventory for " << name << endl;
		cout << "----------------------------------------------" << endl;
	}
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (!inventoryList[i].isEmpty())
		{
			inventoryList[i].inOrderPrint(inventoryList[i].getRoot());
			cout << endl;
		}

	}
}


//---------------------------------------------------------------------------
// get a specific customer
Customer Store::getCustomer(const int IDNum) const
{
    return customerList[IDNum];;
}
