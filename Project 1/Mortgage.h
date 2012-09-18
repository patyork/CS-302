#ifndef MORTGAGE_H
#define MORTGAGE_H

/*
AUTHOR: TEAM AWESOME
*/



  class Mortgage {
  private:

	  float loanAmt ;
	  int payNum ;
	  float rate;
	  

  public:
    

	  //constructor
	  Mortgage();
	  
	  //constructor
	  Mortgage(float loan, int numPay, float newRate);

	  //get loan amount
	  float getAmt() const;
	  
	  //get payment number
	  int getPayNum() const;
	  
	  //get intrest rate
	  float getRate() const;
	  
	  //calculate monthly payment
	  float monthPay() const;
	  
	  //change loan Amount
	  void setloan(float loan);
	  
	  //change payNum
	  void setPayNum(int numPay);
	  
	  //change rate
	  void setRate(float newRate);
	 
	  //returns total intrest paid
	  float intPay();
	  
	  //return total amount paid
	  float totalAmt();
  };
  


#endif // MORTGAGE_H
