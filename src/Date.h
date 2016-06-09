/*
 * Date.h
 *
 *  Created on: Jun 7, 2016
 *      Author: soaler
 */

#ifndef DATE_H_
#define DATE_H_

#include <array>
#include <iostream>

class Date
{
	friend std :: ostream &operator<<(std::ostream &, const Date &);
public:
	Date( int m=1, int d=1, int y=1900); //default constructor
	void setDate( int, int, int );//set month, day, year
	Date & operator++();//prefix increment
	Date operator++( int );//postfix increment
	Date &operator+=( unsigned int );//add days, modify object
	Date & operator--();//prefix decrement
	Date operator--( int );//postfix decrement
	Date &operator-=( unsigned int );//remove days, modify object
	static bool leapYear(int); // is date in a leap year?
	bool endOfMonth(int) const; //is date at the end of the month
	bool begOfMonth(int) const; //is date at the beginning of the month
private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
	static const std:: array < unsigned int, 13 > days; // days per month
	void helpIncrement(); // utility function for incrementing date
	void helpDecrement(); //utility function for decreasing date
};


#endif /* DATE_H_ */
