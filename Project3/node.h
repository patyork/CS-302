#ifndef NODE_H
#define NODE_H

/*
	
	Specification for the node class

	Author: Pat York

*/

class node
{
	public:
		node *next;		//pointer to next node
		char	name[21];		//name of the customer
		char holiday[21];  	//name of the holiday (also used for the name of the magician)
	
		//Constructor
		node();
		
		//Parameterized Constructor
		node( node *n, char nme[], char hol[] );
		
		//We need deconstructors

//Friend declarations
friend class waitingList;
friend class magBooking;
friend class holBooking;
};

#endif
