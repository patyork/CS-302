/*

	\Project 2 Main Driver

	\Author:

*/

#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <fstream>
#include <iomanip>

const char* inputFileName = "Invent.in";
const char* outputFileName = "Receipts.out";

int main(int argc, char** argv)
{
	char more = 'Y';						// Character determining if more customers
	
	float total=0, subtotal=0;					// Floats for storing a customer's total and subtotal; tax = total - subtotal
	Inventory inventory;					// Instantiate an inventory
	
	std::ifstream inFile (inputFileName);		// Input file variable
	std::ofstream outFile (outputFileName);		// Output file variable
	
	// Check if output file opened correctly
	if( !outFile.good() )
	{
		std::cout << "Error Opening " << outputFileName << ". Program Exiting.." << std::endl;
		return 0;
	}
	
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
			int tempNumber=-1;
			char tempDesc[13];
			float tempPrice;
			char tempTaxable;
			
			inFile >> tempNumber >> tempDesc >> tempPrice >> tempTaxable;
			
			// Check for duplicate product numbers
			if( inventory.numberExists(tempNumber) )
			{
				outFile << "INVENT.IN ERROR: Duplicate Product Number " << tempNumber << std::endl;
			}
			// Add product to the inventory
			else if( tempNumber > 0 )
			{
				bool taxIt = false;
				if( tempTaxable == 'T' ) taxIt = true;
				inventory.addToInventory(tempNumber, tempDesc, tempPrice, taxIt);
			}
		}
	}
	inFile.close();
	
	// Print out the working inventory
	inventory.printInventory();
	

	//Loop while more customers
	int j = 1;
	do
	{
		using namespace std;
		int inNum=0;
		int inCount=0;
		
		outFile << "Customer " << j << endl;
		
		cout << endl << "Please enter purchase information in the format '<product number> <quantity>'" << endl
			<< "When done, please enter '0 0'" << endl;
		
		std::cin >> inNum >> inCount;
		while( inNum != 0 )
		{
			// Check for count in range
			if( inCount <= 100 && inCount > 0 )
			{
				// Check for product number existence
				if( inventory.numberExists(inNum) )
				{
					Product in = inventory.findProduct(inNum);
					if( in.getTax() )
					{
						subtotal += in.getPrice() * inCount;
						total += in.getPrice() * inCount * 1.075f;
						outFile << left << setw(14) << in.getDescription() << setw(3) << inCount << setw(3) << "@"
							<< setw(5) << in.getPrice() << setw(5) << in.getPrice() * inCount
							<< "TX" << endl;
					}
					else
					{
						subtotal += in.getPrice() * inCount;
						total += in.getPrice() * inCount;
						outFile << left << setw(14) << in.getDescription() << setw(3) << inCount << setw(3) << "@"
							<< setw(5) << in.getPrice() << setw(5) << in.getPrice() * inCount << endl;
					}
				}
				else
				{
					outFile << "*** Item " << inNum << " Not In Inventory ***" << endl;
				}
			}
			else
			{
				outFile << "*** Product Quantity Not In Range ***" << endl;
			}
			cin >> inNum >> inCount;
		}
		outFile << "     " << left << setw(10) << "Subtotal" << subtotal << endl
			<< "     " << setw(10) << "Tax" << total-subtotal << endl << endl;
			outFile << "     " << setw(10) << "Total" << total << endl << endl;


		cout << "Is there another customer to be processed? <Y/N>" << endl;
		cin >> more;
		total = 0;
		subtotal = 0;
		j++;
	}
	while( more == 'y' || more == 'Y' );
	outFile.close();

	return 0;
}
