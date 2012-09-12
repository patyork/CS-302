#ifndef MORTGAGE_H
#define MORTGAGE_H

/*
AUTHOR: TEAM AWESOME
*/



  class Mortgage {
  private:

	  long loanAmt ;
	  int payNum ;
	  long rate;
	  

  public:
    

	  //constructor
	  Mortgage(long amt, int pay, long rate) ;

	  //get loan amount
	  long getAmt() const;
	  
	  //get payment number
	  int getPayNum() const;
	  
	  //get intrest rate
	  long getRate() const;
	  
	  //calculate monthly payment
	  
	  long monthPay() const;
	  
	  //change rate
	  void setRate();
	  
	  //change payNum
	  void setPayNum();
	  
	  //change rate
	  void setRate();
	 
	  //returns total intrest paid
	  long intPay();
	  
	  //return total amount paid
	  long totalAmt();
  };
  


#endif // MORTGAGE_H
