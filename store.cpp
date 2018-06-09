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
void Store::doCommands(istream& infile)
{
	int custID = 0;
	bool found = false;
	string movieType = "";
	char EOL = '\n';

    Inventory * itemLoc = NULL;
	Customer * tempCust = NULL;
	Inventory *  tempItem = NULL;

    char cmdCh = ' ';
    char movCh = ' ';
    char movTCH = ' ';

	for (;;){
		infile >> cmdCh;
		if (infile.eof()) break;

		if (cmdCh == 'I'){
			displayCatalog();
			cmdCh = ' ';
		}
		else if (infile.get() == EOL)
			cmdCh = ' ';
		else {
			Command  * processedTran = hash
							.createCommand(cmdCh, infile);

			if (processedTran != NULL){
				infile >> custID;

				if (infile.eof()) break;

				if (customerFound (custID)){
					tempCust = &customerList[custID];

					bool isHistory = processedTran->
								setData(movieType, itemLoc, tempCust);

					if (infile.get() != EOL && isHistory){

						infile >> movTCH;

						movieType = hash .getMovieType(movTCH);


						if (movieType != ""){

							infile >> movCh;

							tempItem = hash .createMovie(movCh, infile);

							if (tempItem != NULL){
								tempItem->setData2(infile);

								found = inventoryList[hash .
									convToSubscript(movCh)].
									retrieve(*tempItem, itemLoc);

								if (found == false)
								{
									cout << "ERROR: Invalid Movie Request!"
										<< tempItem->getItem() << endl;
								}

								delete tempItem;
								tempItem = NULL;

								bool found2 = processedTran->
									setData(movieType, itemLoc, tempCust);

								if ((found && found2) && movieType != ""){
									customerList[custID]
										.addCommand(*processedTran);

								}
								delete processedTran;
								processedTran = NULL;
							}
							else{
								cout << "ERROR: " << movCh
									 << " Genre not Found!" << endl;

								if (processedTran != NULL)
									delete processedTran;
								processedTran = NULL;
							}


							string temp;
							getline(infile, temp, EOL);
							delete tempItem;
							tempItem = NULL;

						}
						else{
							string temp;
							getline(infile, temp, EOL);

							cout << "ERROR: Bad code " << movTCH << endl;

							if (processedTran != NULL)
								delete processedTran;
							processedTran = NULL;
						}

					}
					else {
						if (processedTran != NULL)
							delete processedTran;
						processedTran = NULL;
					}

				}
				else {
					cout << "Error: Bad customer ID " << custID << endl;

					if (processedTran != NULL)
						delete processedTran;
					processedTran = NULL;

					string temp;
					getline(infile, temp, EOL);
				}
			}
			else {
				cout << "ERROR: Invalid command " << cmdCh << endl;

				if (processedTran != NULL)
					delete processedTran;
				processedTran = NULL;
			}
		}

		found = false;
		custID = 0;
		itemLoc = NULL;
		tempCust = NULL;
		tempItem = NULL;
}//end for
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
