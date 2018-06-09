#include "inventory.h"

Inventory::Inventory() : stockNum(-1), maxStock(0)
{

}

Inventory::Inventory(const Inventory& rhs)
{

}

Inventory::~Inventory()
{
}

void Inventory::setMaxCopies(const int maxCopy)
{
    maxStock = maxCopy;

    if (stockNum < 0)
        stockNum = maxCopy;
}

void Inventory::increaseCopies()
{
    if (stockNum != maxStock)
        maxStock++;
}

void Inventory::decreaseCopies()
{
    if (stockNum != 0)
        maxStock--;
}
int Inventory::getMaxAmount()
{
    return maxStock;
}

int Inventory::getCurAmount()
{
    return maxStock;
}
