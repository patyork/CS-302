#include "gtest/gtest.h"

#include "Mortgage.h"


TEST(PatsProj1Test, Correct_Calculation1) {

	Mortgage m(250000, 120, 4.5f);
	

	EXPECT_FLOAT_EQ(m.monthPay(), 2590.9785f);
  	EXPECT_FLOAT_EQ(m.intPay(), 60917.438f);
  	EXPECT_FLOAT_EQ(m.totalAmt(), 310917.44f);
}

TEST(PatsProj1Test, Correct_Calculation2) {

	Mortgage m(1000000, 360, 8.125f);
	
  	EXPECT_FLOAT_EQ(m.monthPay(), 7424.9673f);
  	EXPECT_FLOAT_EQ(m.intPay(), 1672988.20f);
  	EXPECT_FLOAT_EQ(m.totalAmt(), 2672988.20f);
}

TEST(PatsProj1Test, Setters_Work) {

	Mortgage m(250000, 120, 4.5f);
	m.setloan(1000000);
	m.setPayNum(360);
	m.setRate(8.125f);
	
  	EXPECT_FLOAT_EQ(m.monthPay(), 7424.9673f);
  	EXPECT_FLOAT_EQ(m.intPay(), 1672988.20f);
  	EXPECT_FLOAT_EQ(m.totalAmt(), 2672988.20f);
}

TEST(PatsProj1Test, Getters_Work) {

	Mortgage m(1000000, 360, 8.125f);
	
  	EXPECT_EQ(m.getAmt(), 1000000);
  	EXPECT_EQ(m.getPayNum(), 360);
  	EXPECT_FLOAT_EQ(m.getRate(), 8.125f);
}
