#ifndef WAITING_H
#define WAITING_H
/*

	Specification for the Waiting List

	Author: Pat York

*/

#include "node.h"

class waitingList
{

	private:
		int length;
		node *first;
		node *last;

	public:
		waitingList();
		void enqueue( char Name[], char Holiday[] );
		void priorityEnqueue( char Name[], char Holiday[] );
		
		// Function for finding the first person on the wait list for a certain holiday
		bool findDequeue( char Holiday[],char *custname );
          int getLength();
          node* getFirst();
                

	
};
#endif
