/*

	\Implementation for class Inventory

	\Author:

*/

#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <iomanip>

Inventory::Inventory()
{
	numberOfProducts = 0;
}

Product Inventory::findProduct(int productNum)
{
	Product a;
	return a;
}
void Inventory::addToInventory(int num, char* desc, float cost, bool tax)
{
	if( !isFull() )
	{
		products[numberOfProducts].addProduct(num, desc, cost, tax);
		numberOfProducts++;
	}	
}

void Inventory::printInventory()
{
	using namespace std;
	
	cout << "Current Inventory:" << endl;
	
	for( int i=0; i < numberOfProducts; i++ )
	{
		cout << setw(8) << products[i].getNumber() << endl;
	}
}

bool Inventory::isFull()
{
	if( numberOfProducts == 50 ) return true;
	return false;
}

bool Inventory::numberExists(int productNum)
{
	for(int i = 0; i < numberOfProducts; i++)
		if( products[i].getNumber() == productNum ) return true;
	
	return false;
}
