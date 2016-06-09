/*
 * Date.cpp
 *
 *  Created on: Jun 7, 2016
 *      Author: soaler
 */

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

//initialize static member; one classwide copy
const array< unsigned int, 13 > Date::days =
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Date constructor
Date::Date( int month, int day, int year )
{
	setDate(month, day, year);
}

void Date::setDate (int mm, int dd, int yy )
{
	if (mm >= 1 && mm <=12 )
	{
		month = mm;
	}
	else
	{
		throw invalid_argument( " Month must be 1 - 12");
	}

	if (yy >= 1900 && yy <= 2100)
	{
		year = yy;
	}
	else
	{
		throw invalid_argument( " Year must be 1900 - 2100");
	}

	// test for leap year
	if ((month  == 2 && leapYear(year) && dd >=1 && dd <= 29) || (dd >=1 && dd <= days [month]))
	{
		day = dd;
	}
	else
	{
		throw invalid_argument( " Day is out of range for current month and year");
	}
}//end function setDate

//overloaded prefix increment operator
Date &Date::operator++()
{
	helpIncrement(); //increment date
	return *this;// reference return to create value
}// end function operator ++

//overloaded postfix increment operator; note that dummy int parameter does not have a peremeter
Date Date::operator++ (int)
{
	Date temp = *this; // hold current state of object
	helpIncrement();

	//return unincremented, saved, saved temp object
	return temp; //value return; not a refrence return
}//end function operator++

//add specified number of days to date
Date &Date::operator +=(unsigned int additionalDays)
{
	for ( int i = 0; i < additionalDays; ++i)
	{
		helpIncrement();
	}
	return *this; //enables cascading
}//end function operator+=

//overloaded prefix decrement operator
Date &Date::operator--()
{
	helpDecrement(); //decrement date
	return *this;// reference return to create value
}// end function operator --

//overloaded postfix decrement operator; note that dummy int parameter does not have a peremeter
Date Date::operator-- (int)
{
	Date temp = *this; // hold current state of object
	helpDecrement();

	//return undecremented, saved, saved temp object
	return temp; //value return; not a refrence return
}//end function operator--

//remove specified number of days to date
Date &Date::operator -=(unsigned int removeDays)
{
	for ( int i = 0; i < removeDays + 1; ++i)
	{
		helpDecrement();
	}
	return *this; //enables cascading
}//end function operator-=

// if the year is a leap year, return true; otherwise return false
bool Date::leapYear( int testYear)
{
	if ( testYear %400 == 0 || ( testYear % 100 != 0 && testYear % 4 == 0))
	{
		return true;//a leap year
	}
	else
	{
		return false; // not a leap year
	}
}//end function leapYear

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const
{
	if (month == 2 && leapYear(year) )
	{
		return testDay == 29;
	}
	else
	{
		return testDay == days[month];
	}
}// end function endOfMonth

bool Date::begOfMonth(int testDay) const
{
	if (month-1 == 2 && leapYear(year) )
	{
		return testDay == 29;
	}
	else
	{
		return testDay == days[month];
	}
}// end function endOfMonth

//function to help increment the date
void Date::helpIncrement()
{
	// day is not end of month
	if (!endOfMonth(day))
	{
		++day; // increment day
	}
	else
		if (month < 12) //days is end of month and month < 12
		{
			++month; //increment month
			day = 1; //set to 1st day of month
		}
		else // last day of year
		{
			++year; // increment year
			month = 1; //set to 1st month of year
			day = 1; //sets to 1st day of the month
		}//end else
}//end function helpIncrement

void Date::helpDecrement()
{
	// day is not end of month
	if (day > 1)
	{
		--day; // increment day
	}
	else
		if ((month <= 12) && (month >= 1) ) //days is end of month and month < 12
		{
			-- month; //increment month
			if (month == 2 && leapYear(year) )
			{
				day = 29;
			}
			else
			{
				day = days[month]; //set to last day of month
			}
		}
		else // last day of year
		{
			--year; // increment year
			month = 12; //set to last month of year
			day = 31; //sets to last day of the month
		}//end else
}//end function helpDecrement

//overload output output operator
ostream &operator<<(ostream &output, const Date &d)
{
	static string monthName[13] = {"", "January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December" };
	output << monthName[d.month] << ' ' << d.day << ' ' << d.year;
	return output;//enables cascading
}// end function operator <<
