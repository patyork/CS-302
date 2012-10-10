/*

	Implementation of the holBooking class

	Author: Pat York

*/

#include "node.h"
#include "holBooking.h"
#include <cstring>


		node *first;
		char holName[21];
		

holBooking::holBooking()
{
	first = NULL;
	strcpy(holName, "");
}

holBooking::holBooking(char newHolidayName[] )
{
	first = NULL;
	strcpy(holName, newHolidayName);
}

bool holBooking::addBooking( char custName[], char magName[] )
{
	//if list is empty, just add it
	if( first == NULL )
	{
		first = new node(NULL, custName, magName);
		return true;
	}
	else
	{
		node *tmp = first;

		// if it belongs just before the current one
		if( strcmp(magName, tmp->holiday) < 0 )
		{
			node *tmp2 = new node(tmp->next, tmp->name, tmp->holiday);
			tmp->next = tmp2;
			strcpy(tmp->name, custName);
			strcpy(tmp->holiday, magName);
			return true;
		}
		
		while( tmp->next != NULL )
		{
			tmp = tmp->next;

			// if it belongs just before the current one
			if( strcmp(magName, tmp->holiday) < 0 )
			{
				node *tmp2 = new node(tmp->next, tmp->name, tmp->holiday);
				tmp->next = tmp2;
				strcpy(tmp->name, custName);
				strcpy(tmp->holiday, magName);
				return true;
			}
		}
	}
	return false;
}

bool holBooking::cancelBooking( char custName[] )  //cancel holiday booking based on customer name
{
	if( first == NULL ) return false;
	
	node *tmp = first;  //temp pointer
	if( strcmp(custName, tmp->name) == 0  )	//if the booking is first in list
	{
		first = first->next;
		delete tmp;
		return true;
	}

	//else loop through all
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		if( strcmp(custName, tmp->name) == 0 )
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

const char* holBooking::getHolidayName() const
{
	return holName;
}
