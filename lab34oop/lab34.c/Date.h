#pragma once

typedef struct
{
	int day;
	int month;
	int year;
}Date;



/// DESCRIPTION: checks if date d is valid, meanining day, month and year values are valid
/// INPUT: d = a struct Date type
/// OUTPUT: 1 - d is valid, 0-otherwise
int validateDate(Date d);



/// DESCRIPTION: compares 2 calendaristic dates
/// INPUT: d1,d2 = Date type values
/// OUTPUT: 1:d1>d2  0:d1=d2  -1:d1<d2
int compareDates(Date d1, Date d2);


/// DESCRIPTION: copies source into destination(dest)
/// INPUT: dest, source = Date type values
/// OUTPUT: -
void copyDate(Date *dest, Date source);



/// DESCRIPTION: pretty-prints a Date type value
/// INPUT: d = Date type value
/// OUTPUT: -
void printDate(Date d);
