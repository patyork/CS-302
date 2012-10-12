/*

	Implementation of the holBooking class

	Author: Pat York

*/

#include "node.h"
#include "adt3_1.h"  //holbooking
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

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
		if( strcmp(custName, tmp->name) < 0 )
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
			if( strcmp(custName, tmp->name) < 0 )
			{
				node *tmp2 = new node(tmp->next, tmp->name, tmp->holiday);
				tmp->next = tmp2;
				strcpy(tmp->name, custName);
				strcpy(tmp->holiday, magName);
				return true;
			}
		}
		tmp->next = new node(NULL, custName, magName);
	
		return true;
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

char* holBooking::getHolidayName() const
{
	char* tmp;
	tmp = new char[21];
	strcpy(tmp, holName);
	return tmp;
}

void holBooking::setHolidayName( char hol[] )
{
	strcpy(holName, hol);
}

void	holBooking::printToFile( std::ofstream& out )
{
	if( out.good() )
	{
		out << holName << std::endl;
		node *tmp = first;
		if( first != NULL )
		{
			out << tmp->name << "  " << tmp->holiday << std::endl;
			
			while(tmp->next != NULL )
			{
				tmp = tmp->next;
				out << tmp->name << "  " << tmp->holiday << std::endl;
			}
				
		}
		out << "BREAK BREAK" << std::endl;
	}
}

//return the name of the magician working this holiday for this customer
char* holBooking::getMagName(char cust[] )
{
	char* magname;
	magname = new char[21];
	
	if( first == NULL ) return "NONE";
	
	node *tmp = first;  //temp pointer
	if( strcmp(cust, tmp->name) == 0  )	//if the booking is first in list
	{
		strcpy(magname, tmp->holiday);
		return magname;
	}

	//else loop through all
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		if( strcmp(cust, tmp->name) == 0 )
		{
			strcpy(magname, tmp->holiday);
			return magname;
		}
	}
	return "NONE";
}

void holBooking::printHolidaySched()
{
	cout << holName << ":" << endl;
	
	node *tmp = first;
	
	if( first != NULL )
	{
	cout << "Magician:" <<tmp->holiday <<"   " <<"Customer:"  << tmp->name <<endl;
	
		while( tmp->next != NULL )
		{
			tmp = tmp->next;
			cout << "Magician:" <<tmp->holiday <<"   " <<"Customer:"  << tmp->name <<endl;
			
			
		}
		
	}
}
