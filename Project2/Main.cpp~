/*

	\Project 2 Main Driver

	\Author:

*/

#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <fstream>

const char* inputFileName = "Invent.in";

int main(int argc, char** argv)
{
	char more = 'Y';	// Character determining if more customers
	
	float total, subtotal;		// Floats for storing a customer's total and subtotal; tax = total - subtotal
	Inventory inventory;		// Instantiate an inventory
	
	std::ifstream inFile (inputFileName);		// Input file variable
	
	//Read into inventory, check for duplicate product numbers
	if( !inFile.good() )
	{
		std::cout << "Error Opening " << inputFileName << ". Program Exiting.." << std::endl;
		return 0;
	}
	
	for(int i=0; inFile.good(); i++)
	{
		std::cout << "safas";
		if( inventory.isFull() == false)
		{
			int tempNumber;
			char tempDesc[13];
			float tempPrice;
			char tempTaxable;
			
			inFile >> tempNumber >> tempDesc >> tempPrice >> tempTaxable;
			
			std::cout << tempNumber << "-" << tempDesc << "-" << tempPrice << "-" << tempTaxable << std::endl;
			/*if( inventory.numberExists(tempNumber) )
			{
				//Write error to output file
			}
			else
			{
				inventory.addToInventory*/
		}
	}

	//Loop while more customers
	do
	{
		using namespace std;	//namespace


		cout << "Is there another customer to be processed? <Y/N>" << endl;
		cin >> more;
	}
	while( more == 'y' || more == 'Y' );

	return 0;
}
