#ifndef PRODUCT_H
#define PRODUCT_H
/*

	\Specification for the Product class

	\Author: Pat York
	
*/

class Product
{
	private:
		int number;
		char description[13];
		float price;
		bool taxable;
		
	public:
		Product();
		Product(int num, char* desc, float cost, bool tax);
		int getNumber();
		char* getDescription();
		float getPrice();
		bool getTax();
		void addProduct(int num, char* desc, float cost, bool tax);
		
		/* Probably don't need these
		void setNumber(int num);
		void setDescription(char[] desc);
		void setPrice(float cost);
		void setTaxable(bool tax);*/
};

#endif
