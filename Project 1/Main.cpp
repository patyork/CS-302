/*
 * 
 * AUTHOR  "THE MAN"
 * 
 * 
 * 
 * 
 */


#include<iostream>
#include "Mortgage.h"


using namespace std;



int main(){
	
	float version = 1.01f;
	long loanMoney;
	float rate;
	int payNum;
	
	Mortgage myMorg;
	
	
	while(1){
		
	cout << "Hello Welcome to the Great Mortgage Calculator  " << (version) << endl <<endl <<endl ;
	
	cout << "Please enter loan amount:  " ;
	
	cin >> loanMoney ;
	
	if(loanMoney == 0.0){
		return 0;
	}
	
	myMorg.setloan(loanMoney);
	cout << endl <<endl;
	
	//paynumber
	cout << "Please Number Of Payments:  " ;
	
	cin >> payNum ;
	
	myMorg.setPayNum(payNum);
	cout << endl <<endl;
	
	//rate
	cout << "Please enter Intrest Rate:  " ;
	
	cin >> rate ;
	
	myMorg.setRate(rate);
	
	
	cout << endl <<endl;
	
	
	cout << " Monthly Payments: " << myMorg.monthPay() << endl << "Total Amount Paid: "<< myMorg.totalAmt() << endl 
			<< "Intrest paid: " << myMorg.intPay() << endl << "Intrest rate" <<myMorg.getRate(); <<endl
			<<"Total Laon Amount" << myMorg.getAmt() <<endl << "Number of Payments: " << myMorg.getPayNum <<endl ;
			
	
	}
	
	
	
	return 0;
}

