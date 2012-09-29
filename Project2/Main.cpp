/*

	\Project 2 Main Driver

	\Author:

*/

#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <fstream>

int main()
{
	char more = 'Y';	// Character determining if more customers
	
	float total, subtotal;		// Floats for storing a customer's total and subtotal; tax = total - subtotal
	Inventory inventory;		// Instantiate an inventory
	
	//Read into inventory, check for duplicate product numbers

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
