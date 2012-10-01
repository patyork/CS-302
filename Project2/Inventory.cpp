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
	for( int i=0; i<numberOfProducts; i++ )
		if( products[i].getNumber() == productNum )
			return products[i];
			
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
		cout << left << setw(8) << products[i].getNumber() << setw(18) << products[i].getDescription()
			<< setw(5) << products[i].getPrice();
		if( products[i].getTax() == true ) cout << left << setw(2) << "T" << endl;
		else cout << left << setw(2) << "N" << endl;
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
