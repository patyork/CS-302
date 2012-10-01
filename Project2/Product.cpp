/*

	\Implementation for class Product

	\Author: Roger Przybyla

*/

#include "Product.h"
#include <string.h>

Product::Product()
{
    number=0;			// Hold the Product Number
    description[0]='\0';	// Holds the Product Description
    price=0.0f;			// Holds the Product Price
    taxable=false;	
}

Product::Product(int num, char* desc, float cost, bool tax)
{
    number=num;			// Hold the Product Number
    strcpy(description,desc);	// Holds the Product Description
    price=cost;			// Holds the Product Price
    taxable=tax;
}

int Product::getNumber()
{
	return number;
}

char* Product::getDescription()
{
	return description;
}

float Product::getPrice()
{
	return price;
}

bool Product::getTax()
{
	return taxable;
}

void Product::addProduct(int num, char* desc, float cost, bool tax)
{
	number = num;
	strcpy(description, desc);
	price = cost;
	taxable = tax;
}
