#ifndef MAGBOOK_H
#define MAGBOOK_H

/*

	Speicifcation of the bookings for one magician

	This list is sorted according to the holiday name.

	Author: Pat York

*/

#include "node.h"


class magBooking
{
	private:
		node *first;
		char magName[21];

	public:
		magBooking();
		magBooking(char newMagName[] );
		bool addBooking( char custName[], char hol[] );
		bool cancelBooking( char hol[] );  //cancel magicians booking based on holiday



};
#endif
