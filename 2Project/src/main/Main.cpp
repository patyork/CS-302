/*****************************************/
/*
/*  Project 2 Main Driver
/*
/*  Author:
/*
/*****************************************/

//#include "Register.h"
#include <iostream>
#include <fstream>

int main()
{
	char more = 'Y';	// Character determining if more customers

	do
	{
		using namespace std;	//namespace


		cout << "Is there another customer to be processed? <Y/N>" << endl;
		cin >> more;
	}
	while( more == 'y' || more == 'Y' );

	return 0;
}
