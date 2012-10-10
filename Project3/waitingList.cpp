/*

	Implementation for the Waiting List class

	Author: Pat York

*/

#include "node.h"
#include "waitingList.h"
#include <cstring>

using namespace std;

waitingList::waitingList()
{
	length = 0;
	first = NULL;
	last = NULL;
}

void waitingList::enqueue( char Name[], char Holiday[] )
{
	if( length==0 )
	{
		first = new node( NULL, Name, Holiday);
		last = first;
		length++;
	}
	else
	{
		last->next = new node( NULL, Name, Holiday);
		last = last->next;
		length++;
	}
}

void waitingList::priorityEnqueue( char Name[], char Holiday[] )
{
	if( length==0 )
	{
		first = new node( NULL, Name, Holiday);
		last = first;
		length++;
	}
	else
	{
		first = new node( first, Name, Holiday);
		length++;
	}
}
		
// Function for finding the first person on the wait list for a certain holiday
bool waitingList::findDequeue( char Holiday[] )
{
	node *tmp = first;
	if( first != NULL )
	{
		if( strcmp(Holiday, tmp->holiday) == 0 ) // if you've found a customer waiting in that holiday
		{
			//Do something with the person on the waitlist
			return true;
		}
		
		while( tmp->next != NULL )
		{
			tmp = tmp->next;
			if( strcmp(Holiday, tmp->holiday) == 0 ) // if you've found a customer waiting in that holiday
			{
				//Do something with the person on the waitlist
				return true;
			}
			
		}
		
	}
	return false;
}
