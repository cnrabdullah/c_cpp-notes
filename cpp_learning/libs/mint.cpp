#include "mint.h"
#include <ostream>
#include <istream>
#include "nutility.h"

std::ostream& operator<<(std::ostream& os, Mint val)
{
	return os << "[" << val.mval << "]";
}


std::istream& operator>>(std::istream& is, Mint& m)
{
	return is >> m.mval;
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

Mint Mint::Random()
{
	return Mint{ Irand{1, 1000}() };
}

