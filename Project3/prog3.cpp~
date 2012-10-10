/*

	Main Driver for Assignment 3

	Author: Pat York

*/

#include <iostream>
#include "waitingList.h"
#include "magBooking.h"

int main()
{
	waitingList waitList;

	magBooking magician1("Pat");

	if( magician1.addBooking("cust", "newyears") ) std::cout << "added" << std::endl;
	if( magician1.addBooking("cust", "christmas") ) std::cout << "added" << std::endl;
	if( magician1.addBooking("cust", "easter") ) std::cout << "added" << std::endl;

	if( magician1.cancelBooking( "easter" ) ) std::cout << "removed" << std::endl;
	if( magician1.cancelBooking( "easter" ) ) std::cout << "removed" << std::endl;  //shouldn't return anything



	return 0;
}
