#include "inventory.h"

Inventory::Inventory() : stockNum(-1), maxStock(0)
{

}

Inventory::Inventory(const& rhs)
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
        stockNum++;
}

void Inventory::decreaseCopies()
{
    if (stockNum != 0)
        stockNum--;
}
int Inventory::getMaxAmount()
{
    return maxStock;
}

int Inventory::getCurAmount()
{
    return maxStock - stockNum;
}
