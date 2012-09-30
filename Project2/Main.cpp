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
	char more = 'Y';						// Character determining if more customers
	
	float total, subtotal;					// Floats for storing a customer's total and subtotal; tax = total - subtotal
	Inventory inventory;					// Instantiate an inventory
	
	std::ifstream inFile (inputFileName);		// Input file variable
	
	
	// Check if file opened correctly
	if( !inFile.good() )
	{
		std::cout << "Error Opening " << inputFileName << ". Program Exiting.." << std::endl;
		return 0;
	}
	
	// Read into inventory
	for(int i=0; inFile.good(); i++)
	{
		if( inventory.isFull() == false)
		{
			int tempNumber;
			char tempDesc[13];
			float tempPrice;
			char tempTaxable;
			
			inFile >> tempNumber >> tempDesc >> tempPrice >> tempTaxable;
			
			// Check for duplicate product numbers
			if( inventory.numberExists(tempNumber) )
			{
				//Write error to output file
			}
			// Add product to the inventory
			else
			{
				bool taxIt = false;
				if( tempTaxable == 'T' ) taxIt = true;
				inventory.addToInventory(tempNumber, tempDesc, tempPrice, taxIt);
			}
		}
	}

	//Loop while more customers
	do
	{


		std::cout << "Is there another customer to be processed? <Y/N>" << std::endl;
		std::cin >> more;
	}
	while( more == 'y' || more == 'Y' );

	return 0;
}
