#include "gtest/gtest.h"

#include "Mortgage.h"


TEST(PatsProj1Test, Correct1) {

	Mortgage m(250000, 120, 4.5f);
	

  	EXPECT_FLOAT_EQ(m.monthPay(), 2590.9785f);
  	EXPECT_FLOAT_EQ(m.intPay(), 60917.438f);
  	EXPECT_FLOAT_EQ(m.totalAmt(), 310917.44f);
}
