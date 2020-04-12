
/* https://github.com/necatiergin/cpp_kursu_odevleri/blob/master/basic_concepts/basic_01.md */

#if 0

#include <iostream>
#include "pvcat.h"

using namespace std;


struct Nec {
	int a, b;
};

Nec   f1();
Nec& f2();
Nec&& f3();

int main()
{
	int x = 10;
	const int y = 20;
	int& r = x;
	int&& rr = x + 5;
	Nec nec;
	Nec* ptr = &nec;
	Nec& nr{ nec };
	int a[10];

	pvcat(x, y);	//sa� operand l oldu�u i�in l
	pvcat((x, y));	//bu neden pr value oluyor?
	pvcat(f3());	//bunu i�ledik mi?
	pvcat(int());	//pr	bunu i�ledik mi?	bunlar temporaro objectmi�
	pvcat(int{});	//pr	bunu i�ledik mi?	bunlar temporaro objectmi�
	pvcat(Nec());	//pr	bunu i�ledik mi?	bunlar temporaro objectmi�
	pvcat(Nec{});	//pr	bunu i�ledik mi?	bunlar temporaro objectmi�
}




#endif

