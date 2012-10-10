/*

	Main Driver for Assignment 3

	Author: Pat York

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "waitingList.h"
#include "magBooking.h"
#include "holBooking.h"

const char* outputFileName = "Schedule.dat";

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
	
	//adds a new booking if a magician is available and supplied
	bool add(char holidayName[], char customer[], char availableMagician[])
	{
		for( int i=0; i<10; i++ )
		{
			//find holiday list
			if( strcmp( (holidayList[i]).getHolidayName(), holidayName) == 0 )
			{
				//attempt to add booking
				if( holidayList[i].addBooking( customer, availableMagician ) )
				{
					//Booking was added successfully
					return true;
				}
				
				//booking failed
				return false;
			}
		}
		return false;
	}
	
	// Output schedule to Schedule.dat
	void saveData()
	{
		using namespace std;
		
		ofstream out (outputFileName);
		
	
	}
};

struct MagiciansSched
{
	magBooking magicianList[10];

	const char* findAvailableMag( char hol[] )
	{
		for( int i=0; i<10; i++ )
		{
			if( magicianList[i].isAvailable( hol ) ) return (magicianList[i]).getMagName();
		}
		
		return "NONE";
	}
	
	//add a booking to the magician's schedule, assumes available magician already found
	bool add(char holidayName[], char customer[], char availableMagician[])
	{
		for( int i=0; i<10; i++ )
		{
			//find the specified magician's booking list
			if( strcmp(magicianList[i].getMagName(), availableMagician) == 0 )
			{
				if( magicianList[i].addBooking( customer, holidayName ) )
				{
					//booking successful
					return true;
				}
				
				//booking not successfull
				return false;
			}
		}
		//couldn't find magician
		return false;
	}
};
	
void menu();

int main()
{
     
    
    HolidaySched holiday;
    MagiciansSched sched;
    
    
	int menuOne;
        char custName[10];
        char hol[10];
        
        bool added = false;
        
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
            cout << "Name Of Customer: " ;
            cin >> custName;
            cout <<endl << "Name Of Holiday: "  ;
            cin >> hol;
            cout << endl;
            char* available = sched.findAvailableMag(hol);
            if(strcmp("NONE",available) == 0){
                //WAITING LIST FUNCTIONALITY
            }
            else{
               added = sched.add(hol,custName,available); 
            }
            
              
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
