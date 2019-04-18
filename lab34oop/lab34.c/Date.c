#include <stdio.h>
#include <stdlib.h>
#include "Date.h"


int validateDate(Date d)
{
	if (d.day <= 0 || d.month <= 0 || d.year <= 0)
		return 0;
	if (d.month > 12)
		return 0;
	switch (d.month)
	{
	case 1:if (d.day > 31) return 0;
	case 2:if (d.day > 28) return 0;
	case 3:if (d.day > 31) return 0;
	case 4:if (d.day > 30) return 0;
	case 5:if (d.day > 31) return 0;
	case 6:if (d.day > 30) return 0;
	case 7:if (d.day > 31) return 0;
	case 8:if (d.day > 31) return 0;
	case 9:if (d.day > 30) return 0;
	case 10:if (d.day > 31) return 0;
	case 11:if (d.day > 30) return 0;
	case 12:if (d.day > 31) return 0;
	}
	if (d.year > 2018 || d.year<2017)
		return 0;
	return 1;
}



int compareDates(Date d1, Date d2)
{
	if (d1.year > d2.year)return 1;
	if (d1.year < d2.year)return -1;
	if (d1.month > d2.month)return 1;
	if (d1.month < d2.month)return -1;
	if (d1.day > d2.day)return 1;
	if (d1.day < d2.day)return -1;
	return 0;
}



void copyDate(Date *dest, Date source)
{
	(*dest).day = source.day;
	(*dest).month = source.month;
	(*dest).year = source.year;

}


///////////////////////////////////////////////////////////////


void printDate(Date d)
{
	printf("%d - %d - %d", d.day, d.month, d.year);
}
