/*

	Implementation of the bookings for one magician

	This list is sorted according to the holiday name.

	Author: Pat York

*/

#include "node.h"
#include "magBooking.h"
#include <cstring>

magBooking::magBooking()
{
	first = NULL;
	strcpy(magName, "");
}

magBooking::magBooking(char newMagName[] )
{
	first = NULL;
	strcpy(magName, newMagName);
}

bool magBooking::addBooking( char custName[], char hol[] )
{
	//if list is empty, just add it
	if( first == NULL )
	{
		first = new node(NULL, custName, hol);
		return true;
	}
	else
	{
		node *tmp = first;

		// if it belongs just before the current one
		if( strcmp(hol, tmp->holiday) < 0 )
		{
			node *tmp2 = new node(tmp->next, tmp->name, tmp->holiday);
			tmp->next = tmp2;
			strcpy(tmp->name, custName);
			strcpy(tmp->holiday, hol);
			return true;
		}
		
		while( tmp->next != NULL )
		{
			tmp = tmp->next;

			// if it belongs just before the current one
			if( strcmp(hol, tmp->holiday) < 0 )
			{
				node *tmp2 = new node(tmp->next, tmp->name, tmp->holiday);
				tmp->next = tmp2;
				strcpy(tmp->name, custName);
				strcpy(tmp->holiday, hol);
				return true;
			}
		}
	}
	return false;

}
bool magBooking::cancelBooking( char hol[] )
{
	if( first == NULL ) return false;
	
	node *tmp = first;  //temp pointer
	if( strcmp(hol, tmp->holiday) == 0  )	//if the booking is first in list
	{
		first = first->next;
		delete tmp;
		return true;
	}

	//else loop through all
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		if( strcmp(hol, tmp->holiday) == 0 )
		{
			node *tmp2 = first;
			while( (tmp2->next)->next != tmp->next ) tmp2=tmp2->next; //loop to node previous
			tmp2->next = tmp->next;
			delete tmp;
			return true;
		}
	}
	return false;
}


