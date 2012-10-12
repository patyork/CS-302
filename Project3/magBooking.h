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
		//Constructor
		magBooking();
		
		//Parameterized Constructor
		magBooking(char newMagName[] );
		
		//Function to add a booking for this magician on this holiday
		bool addBooking( char custName[], char hol[] );
		
		//Function to cancel this magician's booking on inputted holiday
		bool cancelBooking( char hol[],char name[]  );
		
		//Returns true if magician is available for this holiday
		bool isAvailable( char hol[] );
		
		char* getMagName() const;
		bool setMagName(char newName[] );
		node* getFirst() const;
		
		//prints Schedule
		void printMagSched();
		
		//We need deconstructors



};
#endif
