/*

	Main Driver for Assignment 3

	Author: Pat York

*/

#include <iostream>
#include <cstring>
#include "waitingList.h"
#include "magBooking.h"
#include "holBooking.h"

struct HolidaySched
{
	holBooking holidayList[10];
	
	bool cancel(char holidayName[], char customer[])
	{
		for( int i=0; i<10; i++ )
		{
			if( strcmp( (holidayList[i]).getHolidayName(), holidayName) == 0 )
			{
				if( holidayList[i].cancelBooking( customer ) )  //cancel booking
				{
					//check wait list
				
					return true;
				}
				return false;
			}
		}
		return false;
	}
	
	bool add(char holidayName[], char customer[])
	{
		for( int i=0; i<10; i++ )
		{
			if( strcmp( (holidayList[i]).getHolidayName(), holidayName) == 0 )
			{
				
			}
		}
		return false;
	}
};

struct MagiciansSched
{
	magBooking magicianList[10];

};
	
void menu();


int main()
{
    int menuOne;
	/*waitingList waitList;

         * 
         * 
	magBooking magician1("Pat");

	if( magician1.addBooking("cust", "newyears") ) std::cout << "added" << std::endl;
	if( magician1.addBooking("cust", "christmas") ) std::cout << "added" << std::endl;
	if( magician1.addBooking("cust", "easter") ) std::cout << "added" << std::endl;

	if( magician1.cancelBooking( "easter" ) ) std::cout << "removed" << std::endl;
	if( magician1.cancelBooking( "easter" ) ) std::cout << "removed" << std::endl;  //shouldn't return anything*/


    using namespace std;
    
     while(1){  
    cout << endl <<endl << "Welcome To Harry Potter Time Scheduler" << endl <<endl ;
 
    menu();
    
    cin>>menuOne;
    
    switch(menuOne){
        
    
           
        case 1:
            cout <<endl <<endl <<endl ;
                
              
            break;
                
        case 2:
                cout <<endl <<endl <<endl ; 
                
              
            break;
               
        case 3:
                 cout <<endl <<endl <<endl ;
                
              
            break;
               
        case 4:
               
                cout <<endl <<endl <<endl ;         
                
             
            break;
               
        case 5:
                
                cout <<endl <<endl <<endl ; 
               
            break;
                
        case 6:
                
                
            cout <<endl <<endl <<endl ;
            return 0;
            break;
                
    }
    }
	return 0;
}


void menu(){
    
    using namespace std; 
    cout << "1) Schedule" << endl;
    cout << "2) Cancel" << endl;
    cout << "3) SignUp" << endl;
    cout << "4) DropOut" << endl;
    cout << "5) Status" << endl;
    cout << "6) Quit" << endl;
    
}