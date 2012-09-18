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
	float loanMoney;
	float rate;
	int payNum;
	
	Mortgage myMorg;
	
	while(1){
		
	cout << endl << "Hello, and Welcome to the Great Mortgage Calculator  v" << version << endl <<endl <<endl ;
	
	cout << "Please enter loan amount:  " ;
	
	cin >> loanMoney ;
	
	if(loanMoney == 0.0){
		return 0;
	}
	
	myMorg.setloan(loanMoney);
	cout << endl;
	
	//paynumber
	cout << "Please Number Of Payments:  " ;
	
	cin >> payNum ;
	
	myMorg.setPayNum(payNum);
	cout << endl;
	
	//rate
	cout << "Please enter Intrest Rate:  " ;
	
	cin >> rate ;
	
	myMorg.setRate(rate);
	
	
	cout << endl <<endl;
	
	
	cout << "  Monthly Payments: $" << myMorg.monthPay() << endl << " Total Amount Paid: $"<< myMorg.totalAmt() << endl
			<< "     Interest paid: $" << myMorg.intPay() << endl << "     Interest rate: " <<myMorg.getRate() << "%" <<endl
			<<" Total Loan Amount: $" << myMorg.getAmt() <<endl << "Number of Payments: " << myMorg.getPayNum() <<endl<<endl<<endl;
			
	
	}
	
	
	
	return 0;
}

