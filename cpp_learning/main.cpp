




#if 1


#include <string>
#include <iostream>

class base {
public:
	base *x;
	virtual void foo()
	{
		std::cout << "base::foo\n";
	}
};

class der : public base {
public:
	void foo()
	{
		std::cout << "der::foo\n";
	}
};


int main()
{

}



/*
	#include <iostream>
	#include "vcat.h"
	std::cout << "maindevam\r\n";
	std::cout << "x: " << x << "\r\n";
	std::cout << typeid(z).name() << "\r\n";

	#include <conio.h>
	_getch();
*/



#endif

