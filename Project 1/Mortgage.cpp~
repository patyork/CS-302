/*
TITLE:  Implementation for Mortgage class
AUTHOR: Pat "The Myth, The Man, The Lengend" York
*/

#include <cmath>
#include "Mortgage.h"

//constructor
Mortgage::Mortgage()
{
	loanAmt = 0;
	payNum = 0;
	rate = 0.0f;
}
	  

//get loan amount
float Mortgage::getAmt() const
{
	return loanAmt;
}
	  
//get payment number
int Mortgage::getPayNum() const
{
	return payNum;
}
	  
//get intrest rate
float Mortgage::getRate() const
{
	return rate;
}
	  
//calculate monthly payment
float Mortgage::monthPay() const
{
	float monthlyRate = rate/12/100;
	return ( loanAmt * monthlyRate * pow(1 + monthlyRate, payNum) ) / ( pow(1+monthlyRate, payNum) - 1 );
}
	  
//change loan Amount
void Mortgage::setloan(float loan)
{
	loanAmt = loan;
}
	  
//change payNum
void Mortgage::setPayNum(int numPay)
{
	payNum = numPay;
}
	  
//change rate
void Mortgage::setRate(float newRate)
{
	rate = newRate;
}

//returns total intrest paid
float Mortgage::intPay()
{
	return loanAmt * rate/100;
}
	  
//return total amount paid
float Mortgage::totalAmt()
{
	return loanAmt * rate/100 + loanAmt;
}
