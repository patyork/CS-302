/*
	
	Specifications for the bookings of one holiday

	This lsit is sorted according to the customer name

	Author: Pat York

*/

#include "node.h"

class holBooking
{
	private:
		node *first;
		char holName[21];
		
	public:
		holBooking();
		holBooking(char newHolidayName[] );
		bool addBooking( char custName[], char magName[] );
		bool cancelBooking( char custName[] );  //cancel holiday booking based on customer name

		const char* getHolidayName() const;

};
