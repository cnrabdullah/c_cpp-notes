

#if 1


#include <iostream>
#include "Date.h"


void tester_Date()
{
	Date d1;
	Date d2{ 29, 02, 2020 };
	Date d3{ "31/12/2020" };

	std::time_t timer = std::time(nullptr);
	Date d4{ timer };

	Date d5 = Date::random_date();

	std::cout << d1;
	std::cout << d2;
	std::cout << d3;
	std::cout << d4;
	std::cout << d5;
	

	Date d6{ "08/03/2020" };
	Date d7{ "05/03/2020" };

	
	auto res1 = d6 - 3;
	std::cout << "res1: " << res1 << "\r\n";

}

#endif
