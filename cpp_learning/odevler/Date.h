//https://github.com/necatiergin/cpp_kursu_odevleri/blob/master/date_odevi.md

#ifndef DATE_H
#define DATE_H
#include <iosfwd>
#include <ctime>

class Date {

	friend std::ostream& operator<<(std::ostream& os, const Date& date);

private:					
	int day;		//todo: bunlarý in-class init ile 01-01-1990 yapsak faydalý olur muydu?
	int month;		
	int year;
	static constexpr int monthDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//soru: string mi kullansaydik?
	static constexpr const char* weekStr[] = { 
		"Sunday", 
		"Monday", 
		"Tuesday", 
		"Wednesday", 
		"Thursday", 
		"Friday", 
		"Saturday" 
	};
	static constexpr const char* monthStr[] = { 
		"", 
		"January", 
		"February", 
		"March", 
		"April", 
		"May", 
		"June", 
		"July", 
		"August", 
		"September", 
		"October", 
		"November", 
		"December" 
	};
public:
	static constexpr int year_base = 1900;  //1
	static constexpr int random_min_year = 1940;  //2
	static constexpr int random_max_year = 2020;  //3
	enum class WeekDay { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday }; //4

	Date(); //5 
	explicit Date(int d, int m, int y);  //6
	Date(const char* p);  //7
	explicit Date(std::time_t timer); //8

	int get_month_day()const; //9
	int get_month()const; //10
	int get_year()const; //11
	int get_year_day()const; //12
	WeekDay get_week_day()const; //13
	
	Date& set_month_day(int day); //14
	Date& set_month(int month); //15
	Date& set_year(int year); //16
	Date& set(int day, int mon, int year); //17

	Date operator-(int day)const; //18	
	Date& operator+=(int day); //19
	Date& operator-=(int day); //20
	Date& operator++(); //21
	Date operator++(int); //22
	Date& operator--(); //23
	Date operator--(int); //24

	static Date random_date(); //25
	static constexpr bool isleap(int y); //26
	static constexpr bool isValidDate(int d, int m, int y);	//sonradan eklendi.
};

bool operator<(const Date&, const Date&); //27
bool operator<=(const Date&, const Date&); //27
bool operator>(const Date&, const Date&); //27
bool operator>=(const Date&, const Date&); //27
bool operator==(const Date&, const Date&); //27
bool operator!=(const Date&, const Date&); //27

int operator-(const Date& d1, const Date& d2); //28
Date operator+(const Date& date, int n); //29
Date operator+(int n, const Date&); //29
Date::WeekDay& operator++(Date::WeekDay& r); //30
Date::WeekDay& operator++(Date::WeekDay& r, int); //30
Date::WeekDay& operator--(Date::WeekDay& r); //30
Date::WeekDay& operator--(Date::WeekDay& r, int); //30

std::ostream& operator<<(std::ostream& os, const Date& date); //31
std::istream& operator>>(std::istream& is, Date& date); //32

#endif

