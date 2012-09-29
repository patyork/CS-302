#ifndef INVENTORY_H
#define INVENTORY_H
/*

	\Specification for the Product class

	\Author: Pat York
	
*/

#include "Product.h"

class Inventory
{
	private:
		int numberOfProducts;
		Product products[50];
		
	public:
		Inventory();
		Product findProduct(int productNum);
		void addToInventory(int num, char* desc, float cost, bool tax);
		void printInventory();
};

#endif
