/*

	Implementation of the bookings for one magician

	This list is sorted according to the holiday name.

	Author: Pat York

*/

#include "node.h"
#include "magBooking.h"
#include <cstring>
#include <iostream>

using namespace std;

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
bool magBooking::cancelBooking( char hol[], char name[] )
{
	if( first == NULL ) return false;
	
	node *tmp = first;  //temp pointer
	if( strcmp(hol, tmp->holiday) == 0  )	//if the holiday is first in list
	{
		if( strcmp(name, tmp->name) == 0 )		//if you've found the right customer
		{
			first = first->next;
			delete tmp;
			return true;
		}
	}

	//else loop through all
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		if( strcmp(hol, tmp->holiday) == 0 )
		{
			if( strcmp(name, tmp->name) == 0 )		//if you've found the right customer
			{
				node *tmp2 = first;
				while( (tmp2->next)->next != tmp->next ) tmp2=tmp2->next; //loop to node previous
				tmp2->next = tmp->next;
				delete tmp;
				return true;
			}
		}
	}
	return false;
}

bool magBooking::isAvailable( char hol[] )
{
	//Has no appointments, is avaiable
	if( first == NULL ) return true;
	
	node *tmp = first;
	if( strcmp(hol, tmp->holiday) == 0  ) return false; //not available
	
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		if( strcmp(hol, tmp->holiday) == 0 ) return false; //not available
	}
	
	return true;  //must be available

}

char* magBooking::getMagName() const
{
	char* tmp;
	tmp = new char[21];
	strcpy(tmp,magName);
	return tmp;
}

bool magBooking::setMagName(char newName[] )
{
	strcpy(magName, newName);
	return true;
}
node* magBooking::getFirst() const
{
	return first;
}
void magBooking::printMagSched()
{
	cout << magName << ":" << endl;
	
	node *tmp = first;
	
	if( first != NULL )
	{
	cout << "Holiday:" <<tmp->holiday <<"   " <<"Customer:"  << tmp->name <<endl;
	
		while( tmp->next != NULL )
		{
			tmp = tmp->next;
			cout << "Holiday:" <<tmp->holiday <<"   " <<"Customer:"  << tmp->name <<endl;
			
			
		}
		
	}
}

//dropout magician
void magBooking::dropout(){

strcpy(magName, "");
node* tmp;
tmp = first;

while(tmp !=NULL){
tmp = first->next;
delete first;
first = tmp;

}

}
//We need deconstructors
magBooking::~magBooking(){
dropout();
}

