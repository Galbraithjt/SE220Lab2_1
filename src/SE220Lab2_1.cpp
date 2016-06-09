//============================================================================
// Name        : SE220Lab2_1.cpp
// Author      : Joshua Galbraith
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
	/*Extending the Case Study Date Class

	Create a new project called DateTest. Copy the code that is found in your book on pages
	446 – 449 (Chapter 10.8called Date Class Case Study).

	Make sure you add the Date Class to your project first. Leave the Destructor in your copy.
	Don’t forget to copy the comments as well.

	Now, add 3 new overloaded methods: &operator--, operator--, and &operator-=

	Add additional lines in the main function to test your new operators. Be sure to comment
	all your added code!!

	Upload to github the entire Solution and retain them for future labs and exams!
	*/
#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date d1(12, 27, 2010);
	Date d2;

	cout << "d1 is " << d1 << "\nd2 is " << d2;
	cout << "\n\nd1 += 7 is " << (d1 += 7);

	d2.setDate (2, 28, 2008);
	cout << "\n\n d2 is " << d2;
	cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

	Date d3 (7, 13, 2010);

	cout << "\n\nTesting the prefix increment operator: \n"
			<< "d3 is " << d3 << endl;
	cout << "++d3 is " << ++d3 << endl;
	cout << "d3 is " << d3;

	cout << "\n\nTesting the postfix increment operator: \n"
			<< "d3 is " << d3 << endl;
	cout << "d3++ is " << d3++ << endl;
	cout << "d3 is " << d3 << endl;

	Date d4(1, 3, 2011);
	Date d5;

	cout << "\n\nd4 is " << d4 << "\nd5 is " << d2;
	cout << "\n\nd4 -= 7 is " << (d4 -= 7);

	d5.setDate (3, 1, 2008);
	cout << "\n\n d5 is " << d5;
	cout << "\n--d5 is " << --d5 << " (leap year allows 29th)";

	Date d6 (7, 13, 2010);

	cout << "\n\nTesting the prefix decrement operator: \n"
			<< "d6 is " << d6 << endl;
	cout << "--d6 is " << --d6 << endl;
	cout << "d6 is " << d6;

	cout << "\n\nTesting the postfix decrement operator: \n"
			<< "d6 is " << d6 << endl;
	cout << "d6-- is " << d6-- << endl;
	cout << "d6 is " << d6 << endl;
} // end main
