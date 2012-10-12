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

using namespace std;

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
		return false; //false
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
		
		ifstream in ("Holiday.dat");
		
		if( in.good() )
		{
			char temp[21];
			in >> temp;

			for(int i=0; !in.eof() && i<10; i++)
			{

				
				holidayList[i].setHolidayName(temp);
				in >>temp;
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
	char* findAvailableMag( char hol[] )
	{
		for( int i=0; i<10; i++ )
		{
		  if( strcmp( magicianList[i].getMagName(), "") == 0 )
		    return "NONE";
			if( magicianList[i].isAvailable( hol ) ){
				
				return (magicianList[i]).getMagName();
				}
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
	
	bool cancel(char holidayName[], char customer[])
	{
		
		for( int i=0; i<10; i++ )
		{
			if( magicianList[i].cancelBooking( holidayName, customer ) )
			{
				
				return true;
			}
		}
		
		
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
		     char temp[21];
      		in >> temp;
			for(int i=0; in.good() && i<10; i++)
			{
				
				
				
				magicianList[i].setMagName(temp);
				in >> temp;
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

void load(MagiciansSched &magsch ,HolidaySched &holsch, waitingList &waiter, ifstream &fin);
void save(MagiciansSched &magsch ,HolidaySched &holsch, waitingList &waiter);

int main()
{
     
    
    HolidaySched holiday;
    MagiciansSched sched;
    waitingList wList;
    
	int menuOne;
        char* name;
        name = new char[21];
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
    		holiday.loadHolidays();
    		load(sched,holiday,wList,in);
    }
    

     while(1){  
    cout << endl <<endl << "Welcome To Harry Potter Time Scheduler" << endl <<endl ;
 
    menu();
    
    cin>>menuOne;
     

    switch(menuOne){
        
   
           
        case 1:
            cout << "Create Reservation:" << endl << endl;
            cout << "Name Of Customer: ";
            cin >> custName;
            cout <<endl << "Name Of Holiday: ";
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
               	if( holiday.add(hol, custName, available) )
               	{
               		cout <<endl<<endl<< "Reservation Confirmed: " <<endl;
               
               		cout << "Magician: " << available << endl;
               
               		cout << "Holiday: " << hol <<endl;
               
               		cout << "Name Of Customer: " <<custName <<endl;
               		added = false;
               	}
               	else
               	{
               		cout << "Reservation error.." << endl;
               	}
               }
               else{
                   cout << "Reservation Error" <<endl;
               }
            }
            
              delete available;
            break;
                
        case 2:
        		cout << "Cancel Reservation:" << endl << endl;
               cout << "Name Of Customer: " ;
            	cin >> custName;
            	cout <<endl << "Name Of Holiday: "  ;
            	cin >> hol;
            	
            	sched.cancel( hol, custName );
            	holiday.cancel( hol, custName );
            	
            	
                
              
            break;
               
        case 3:
                 cout <<endl <<endl <<endl ;
                 cout<<"New Magicians Name: "<<endl;
                 cin >>mage;
                 sched.signupMagician(mage);
                 
               
                 for(int i = 0;i <10;i++){
                     
                              
                     char* available2 ;          
                     available2 = new char [21];
                     strcpy(available2, sched.findAvailableMag(holiday.holidayList[i].getHolidayName()));
                    

                     if(strcmp("NONE",available2) == 0){
                
                     }
                     if(wList.findDequeue(holiday.holidayList[i].getHolidayName(), name))
                     
                    
                     
                     {
             
                         added = sched.add(holiday.holidayList[i].getHolidayName(),name,available2);
             	
                         if(added){  
                         	added = holiday.add(holiday.holidayList[i].getHolidayName(), name, available2);             
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
                
                available3= new char [21];             
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
                         
                         added = holiday.add(tmpp->holiday,tmpp->name,available3)     ;
                               
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
			//delete magician from hilday list.
			holiday.cancel(tmpp->holiday, tmpp->name);
                            tmpp = tmpp->next;
                 }
//delete magician fro sched.magicianList
sched.magicianList[i].dropout();

                    }
                }
            break;
               
        case 5:
                char menuOneChar;
            cout << endl <<"Status: "<<endl <<endl;
            cout <<"By (H)oliday or (M)agician :" <<endl <<endl;
            cin >>menuOneChar;
            
            switch(menuOneChar)
            {
                    
       		 case 'H' :
	         case 'h' :
	        	 
	        	cout << "Please Enter Holiday:" <<endl;
	        	 	
     			cin >> hol;
      		        cout <<endl <<endl <<endl ; 
            
            	for( int i=0; i<10; i++ )
            	{
            		if( strcmp( holiday.holidayList[i].getHolidayName(), hol ) == 0 )
            		{
            			holiday.holidayList[i].printHolidaySched();
            			i=11;
            		}
            		if(i==9){
            		cout << "That holiday is not celebrated." <<endl;
            		
            		}
            	}
     		       break;
            
     	   case 'M':
     	   case'm':
            

               	    cout << "Please Enter Magician:" <<endl;
	        	 	
     			   cin >> mage;
      		        cout <<endl <<endl <<endl ; 
            
            			for( int i=0; i<10; i++ )
            			{
            				if( strcmp( sched.magicianList[i].getMagName(), mage ) == 0 )
            				{
            					sched.magicianList[i].printMagSched();
            					i=11;
            				}
            				if(i==9){
            				cout << "That magician is no longer with us." <<endl;
            		
            				}
            			}
      		      	break;
      		}
                break;
       case 6:
                
                
           //save the data
            save(sched, holiday, wList);
            return 0;
            break;
            
         
        default:
                cout << "Please Enter A Number 1-6" <<endl;
                break;
                
    }
    }
	//return 0;
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

void load(MagiciansSched &magsch ,HolidaySched &holsch, waitingList &waiter, ifstream &fin)
{

	char magname[21];
	char holname[21];
	char custname[21];
	int run = 0;
	int found = 0;
	
	fin >>magname;
	
	while(fin.good() && strcmp(holname,"WAITLIST")!=0 && strcmp(magname,"WAITLIST")!=0  )
	{
		//read in mage flage, mage name, 1st holiday
	
		fin >>magname;

		fin>>holname;
		if( strcmp(holname,"Mage")==0 )
		{
			magsch.signupMagician(magname);		
		} 
		
		if( (strcmp(holname,"WAITLIST")==0)){
			magsch.signupMagician(magname);
			break;
		}
		
		//check for next mage flag
		while( (strcmp(holname, "Mage")!=0) && (strcmp(holname, "WAITLIST") !=0) ){
		
			cout << "Looper2" <<endl;
		
			fin>>custname;
			//if schedule read in
			holsch.add(holname, custname, magname);
			if(run ==0){
				magsch.signupMagician(magname);
				run++;
					cout << "Looper3" <<endl;
			}
		
			magsch.add(holname, custname, magname);
			fin >> holname;
		
		}
		run=0;
		
	
	
	
	}	
	fin >> magname; //Second waitlist flag
	fin >> custname >> holname;
	
	while(fin.good()){
	waiter.enqueue( custname, holname);
	fin >> custname >> holname;
	}

}

void save(MagiciansSched &magsch ,HolidaySched &holsch, waitingList &waiter)
{
	ofstream fout("Schedule.dat");

	if(fout.good()){

cout << magsch.magicianList[0].getMagName() <<endl;
cout << magsch.magicianList[1].getMagName()<<endl;
cout << magsch.magicianList[2].getMagName()<<endl;
cout << magsch.magicianList[3].getMagName()<<endl;
cout << magsch.magicianList[4].getMagName()<<endl;
cout << magsch.magicianList[5].getMagName()<<endl;
cout << magsch.magicianList[6].getMagName()<<endl;
cout << magsch.magicianList[7].getMagName()<<endl;
cout << magsch.magicianList[8].getMagName()<<endl;
cout << magsch.magicianList[9].getMagName()<<endl;


		for(int i =0; i <10;i++)
		{
		
			
			if( strcmp(magsch.magicianList[i].getMagName(), "") != 0 )
			{
				fout << "Mage" << endl
					<< magsch.magicianList[i].getMagName() << endl;
				
				node *tmp = magsch.magicianList[i].getFirst();
				while( tmp != NULL )
				{
					fout << tmp->holiday << endl
						<< tmp->name << endl;
					tmp = tmp->next;
				}
			}
	
		}
		
		node *tmp;
		tmp = waiter.getFirst();
		
		fout << "WAITLIST" << endl
			<< "WAITLIST" << endl;
		
		//Loop over wait list
		while( tmp != NULL )
		{
			fout << tmp->name << endl
				<< tmp->holiday << endl;
			
			//head to next node
			tmp = tmp->next;
		}
		
		//close output file
		fout.close();
	}
}

