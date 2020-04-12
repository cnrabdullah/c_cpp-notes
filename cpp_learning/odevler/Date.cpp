#include "Date.h"

#include <stdio.h>
#include <string.h>
#include <ostream>	//soru: bunları eklemezsek >> ve << fonksiyonları çalışmıyor?
#include <istream>	//soru: bunları eklemezsek >> ve << fonksiyonları çalışmıyor?

Date::Date() : day{ 1 }, month{ 1 }, year{ year_base }
{
}

Date::Date(int d, int m, int y) : day{ d } , month{ m }, year{ y }
{
	//soru:bu kontrolü bir şekilde ctor init listten önce yapabilir miyiz? atamayı hiç yapmasak yanlış ise?
	if (false == isValidDate(day, month, year))
		exit(EXIT_FAILURE);
}

//Format:	gg/aa/yyyy
Date::Date(const char* p)	
{
	const char *dlm = strchr(p,'/');
	if( dlm == nullptr)
		exit(EXIT_FAILURE);		//no delimitter found...

	day = atoi(p);
	month = atoi(dlm+1);
	
	dlm = strchr(dlm + 1, '/');
	if (dlm == nullptr)
		exit(EXIT_FAILURE);		//no delimitter found...

	year = atoi(dlm+1);

	if (false == isValidDate(day, month, year))
		exit(EXIT_FAILURE);
}


Date::Date(std::time_t timer)
{
	struct tm extracted;	
	gmtime_s(&extracted, &timer);

	day = extracted.tm_mday;
	month = extracted.tm_mon + 1;
	year = extracted.tm_year + 1900;	

	if (false == isValidDate(day, month, year))
		exit(EXIT_FAILURE);
}

int Date::get_month_day()const
{
	return day;
}

int Date::get_month()const
{
	return month;
}

int Date::get_year()const
{
	return year;
}

int Date::get_year_day()const
{
	return 5;
}

Date::WeekDay Date::get_week_day()const
{
	int tmpMonth = (month + 9) % 12;
	int tmpYear = year - tmpMonth / 10;

	unsigned dn = ((365 * tmpYear + tmpYear / 4 - tmpYear / 100 + tmpYear / 400 + (tmpMonth * 306 + 5) / 10 + (day - 1)) + 3) % 7;

	return static_cast<Date::WeekDay>(dn);
}

Date& Date::set_month_day(int day)
{
	this->day = day;	
	return *this;
}

Date& Date::set_month(int month)
{
	this->month = month;
	return *this;
}

Date& Date::set_year(int year)
{
	this->year = year;
	return *this;
}

Date& Date::set(int day, int mon, int year)
{
	this->day = day;
	month = mon;
	this->year = year;
	return *this;
}

Date  Date::operator-(int d)const
{
	return Date{};
}

/*
Date& operator+=(int day); //19
Date& operator-=(int day); //20
Date& operator++(); //21
Date operator++(int); //22
Date& operator--(); //23
Date operator--(int); //24
*/









std::ostream& operator<<(std::ostream& os, const Date& date)
{
	return os << date.day << " " << Date::monthStr[date.month] << " " << date.year 
							<< " " << Date::weekStr[static_cast<int>(date.get_week_day())] << "\n";
}


Date Date::random_date()
{
	int y, m, d;

	//random generation formula:	int randNum = rand()%(max-min + 1) + min;
	srand(static_cast<unsigned>(time(NULL)));
	y = rand() % (random_max_year - random_min_year + 1) + random_min_year;
	m = rand() % (12 - 1 + 1) + 1;

	//if leap year and february...
	if (isleap(y) && (m == 2))
		d = rand() % (29 - 1 + 1) + 1;
	else
		d = rand() % (monthDays[m] - 1 + 1) + 1;

	return Date{ d,m,y };
}

constexpr bool Date::isleap(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

constexpr bool Date::isValidDate(int d, int m, int y)
{
	if (y < year_base)
		return false;
	if ((m > 12) || (m < 1))
		return false;
	if (d < 1)
		return false;

	/* if leap year, february29 is also valid... */
	if ( isleap(y) && (m == 2))
	{
		if (d > monthDays[m] + 1)
			return false;
	}
	else
	{
		if (d > monthDays[m])
			return false;
	}

	return true;
}

