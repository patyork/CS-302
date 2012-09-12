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
	
	Mortgage myMorg ;
	
	cout << "Hello Welcome to the Great Mortgage Calculator  " << (version) << endl <<endl <<endl ;
	
	cout << "Please enter loan amount:  " ;
	
	cin >> loanMoney ;
	
	myMorg.loanAmt(loanMoney);
	
	
	cout << endl <<endl;
	
	
	
	
	
	
	
	
	
	return 0;
}

