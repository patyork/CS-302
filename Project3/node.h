#ifndef NODE_H
#define NODE_H

/*
	
	Specification for the node class

	Author: Pat York

*/

class node
{
	private:
		node *next;
		char	name[21];
		char holiday[21];
	public:
		node();
		node( node *n);
		node( node *n, char nme[], char hol[] );

friend class waitingList;
friend class magBooking;
};

#endif
