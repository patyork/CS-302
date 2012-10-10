/*
	
	Specifications for the bookings of one holiday

	This lsit is sorted according to the customer name

	Author: Pat York

*/

#include "node.h"
#include <fstream>


class holBooking
{
	private:
		node *first;
		char holName[21];
		
	public:
		//Constructor
		holBooking();
		
		//Parameterized Constructor
		holBooking(char newHolidayName[] );
		
		//Function to add a booking; does not find/check for magician availability
		bool addBooking( char custName[], char magName[] );
		
		//Function to cancel a booking for this holiday based on the customer name
		bool cancelBooking( char custName[] );

		//Function to return the holiday name
		const char* getHolidayName() const;
		
		//Function to change the holiday name
		void setHolidayName( char hol[] );
		
		//Function to print holiday schedule to file
		void	printToFile( std::ofstream& out );
		
		//We need a deconstructor

};
