/*

	Main Driver for Assignment 3

	Author: Pat York & Roger Przybyla

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "waitingList.h"
#include "magBooking.h"
#include "holBooking.h"
#include "node.h"

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
		
		if( !out.good() ) cout << "Error Opening Schedule.dat for writing!";
		
		//loop over holidays
		for( int i=0; i<10; i++ )
		{
			//check for empty holiday list
			if( strcmp(holidayList[i].getHolidayName(), "") == 0 )break;
			
			holidayList[i].printToFile(out);
			
		}
		out.close();
	}
	
	void loadHolidays()
	{
		using namespace std;
		
		ifstream in ("Holidays.dat");
		
		if( in.good() )
		{
			
			for(int i=0; !in.eof() && i<10; i++)
			{
				char temp[21];
				in >> temp;
				
				holidayList[i].setHolidayName(temp);
			}
			in.close();
		}
	}
	
	//Function to load from Schedule.dat
	void loadSchedule()
	{
		using namespace std;
		
		ifstream in ("Schedule.dat");
		
		if( in.good() )
		{
			for( int i=0; !in.eof() && i<10; i++ )
			{
				char temp[21];
				char temp2[21];
				in >> temp;
				
				holidayList[i].setHolidayName(temp);
				
				in >> temp >> temp2;
				while( strcmp(temp, "BREAK") != 0 && strcmp(temp2, "BREAK") ) //check for holiday break
				{
					holidayList[i].addBooking(temp, temp2);
					in >> temp >> temp2;
				}
			}
		}
	
	}
};

struct MagiciansSched
{
	magBooking magicianList[10];
	
	//Return the name of an available Magician, or NONE
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
	
	//Signup new magician
	void signupMagician(char magname[] )
	{
		for( int i=0; i<10; i++ )
		{
			//find an empty list slot
			if( strcmp(magicianList[i].getMagName(), "") == 0 )
			{
				//set new name and return
				magicianList[i].setMagName(magname);
				return;
			}
		}
		return;
	}
	
	// Load in magicians from Magician.dat
	void loadMagicians()
	{
		using namespace std;
		
		ifstream in ("Magician.dat");
		
		if( in.good() )
		{
			for(int i=0; in.good() && i<10; i++)
			{
				char temp[21];
				in >> temp;
				
				magicianList[i].setMagName(temp);
			}
			in.close();
		}
	}
	
	// Get schedule from Holiday Schedule (which read from Schedule.dat)
	void loadSchedule()
	{
		
	}
};


void menu();

int main()
{
     
    
    HolidaySched holiday;
    MagiciansSched sched;
    waitingList wList;
    
	int menuOne;
        char* name;
        char custName[21];
        char hol[21];
        char mage[21];
        node * ptr;
        bool add = false;
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
    
    ifstream in ("Schedule.dat");
    
    if( !in.good() )
    {
    		sched.loadMagicians();
    		holiday.loadHolidays();
    }
    else
    {
    		holiday.loadSchedule();
    		sched.loadSchedule();
    }
    
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
          
            char* available ;
            available= new char [21];
            strcpy(available, sched.findAvailableMag(hol));
            
            if(strcmp("NONE",available) == 0){
                wList.enqueue(custName,hol);
                cout<< "No magicians Available for that Holdiay, You are on the waiting list" <<endl;
            }
            else{
               added = sched.add(hol,custName,available);
               if(added){
               cout <<endl<<endl<< "Reservations Confirmed: " <<endl<<endl<<endl;
               
               cout << "Magician: " << available << endl;
               
               cout << "Holiday: " << hol <<endl;
               
               cout << "Name Of Customer: " <<custName <<endl;
               added = false;
               }
               else{
                   cout << "Reservation Error" <<endl;
               }
            }
            
              
            break;
                
        case 2:
                cout <<endl <<endl <<endl ; 
                
              
            break;
               
        case 3:
                 cout <<endl <<endl <<endl ;
                 cout<<"New Magicians Name: "<<endl;
                 cin >>mage;
                 sched.signupMagician(mage);
                                      
                 char* available2 ;          
                 
                 available2= new char [10];
                 
                 for(int i = 0;i <10;i++){
                     
                              
                     char* available2 ;          
                     available2= new char [10];
                     strcpy(available2, sched.findAvailableMag(holiday.holidayList[i].getHolidayName()));
                     if(strcmp("NONE",available2) == 0){
                
                     }
                     if(wList.findDequeue(holiday.holidayList[i].getHolidayName(), name))
                     {
               
                         added = sched.add(holiday.holidayList[i].getHolidayName(),name,available2);
               
                         if(added){              
                             cout <<endl<<endl<< "Reservations Confirmed: " <<endl<<endl<<endl;             
                             cout << "Magician: " << available2 << endl; 
                             cout << "Holiday: " << holiday.holidayList[i].getHolidayName() <<endl;
                             cout << "Name Of Customer: " <<name <<endl;              
                             added = false;               
                         }
               
                         else{
                   
                             cout << "Reservation Error" <<endl;
               
                         }
                     
                     } 
                 }
              
            break;
               
        case 4:
               
                cout <<endl <<endl <<endl ;         
                           
                cout<<"Magicians Name To Drop: "<<endl;
                cin >>mage;
                
                                   
                char* available3 ;          
                
                available3= new char [10];             
                node * tmpp ;
                for(int i = 0;i <10;i++){

                    if(strcmp(mage,sched.magicianList[i].getMagName())==0)
                    { 
                        tmpp = sched.magicianList[i].getFirst();
                        
                        while(tmpp != NULL){
          
           
                            strcpy(available3, sched.findAvailableMag(tmpp->holiday));
                           
                        if(strcmp("NONE",available3) == 0){
                                wList.priorityEnqueue(tmpp->name,tmpp->holiday);
               
                                cout<< "No magicians Available for that Holiday, You are on the waiting list" <<endl;
                     }
                        else{
               
                         added = sched.add(tmpp->holiday,tmpp->name,available3);
               
                         if(added){              
                             cout <<endl<<endl<< "Reservations Confirmed: " <<endl<<endl<<endl;             
                             cout << "Magician: " << available3 << endl; 
                             cout << "Holiday: " << tmpp->holiday <<endl;
                             cout << "Name Of Customer: " <<tmpp->name <<endl;              
                             added = false;               
                         }
               
                         else{
                   
                             cout << "Reservation Error" <<endl;
               
                         }
                     
                     } 
                            tmpp = tmpp->next;
                 }
                    }
                }
            break;
               
        case 5:
                
            cout << endl <<"Status: "<<endl <<endl;
            cout <<"By (H)oliday or (M)agician :" <<endl <<endl;
            cin >>menuOne;
            
            switch(menuOne)
                    
        case 'H' :
        case 'h' :
            cin >> hol;
             cout <<endl <<endl <<endl ; 
            
            break;
            
        case 'M':
        case'm':
            
            cin >> mage;
                cout <<endl <<endl <<endl ; 
               
            break;
                
        case 6:
                
                
            cout <<endl <<endl <<endl ;
            holiday.saveData();
            return 0;
            break;
            
         
        default:
                cout << "Please Enter A Number 1-6" <<endl;
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

