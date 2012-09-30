#ifndef PRODUCT_H
#define PRODUCT_H
/*

	\Specification for the Product class

	\Author: Pat York
	
*/

class Product
{
	private:
		int number;			// Hold the Product Number
		char description[13];	// Holds the Product Description
		float price;			// Holds the Product Price
		bool taxable;			// Holds whether the product is Taxable
		
	public:
		// Default Constructor
		Product();
		
		// Parameterized Constructor
		Product(int num, char* desc, float cost, bool tax);
		
		// Return the Product Number
		int getNumber();
		
		// Return the Product Description
		char* getDescription();
		
		// Return the Product Price
		float getPrice();
		
		// Return whether the item is Taxable
		bool getTax();
		
		// Sets the producs Number, Description, Price, and Taxable boolean
		void addProduct(int num, char* desc, float cost, bool tax);
		
		/* Probably don't need these
		void setNumber(int num);
		void setDescription(char[] desc);
		void setPrice(float cost);
		void setTaxable(bool tax);*/
};

#endif
