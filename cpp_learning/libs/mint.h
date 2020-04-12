
#ifndef MINT_H
#define MINT_H

#include <iosfwd>
#include <iostream>

class Mint {
	int mval{};
public:
	Mint() = default;
	explicit Mint(int val) : mval{ val } {	}

	Mint& operator++() //onek
	{
		++mval;
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	Mint operator++(int)
	{
		Mint retval{ *this };
		++* this;
		return retval;
	}
	//--------------------------------------------------------------------------------------------

	Mint& operator--()  //prefix
	{
		--mval;
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	Mint operator--(int)  //postfix
	{
		Mint retval{ *this };
		--* this;
		return retval;
	}
	//--------------------------------------------------------------------------------------------

	Mint operator+()const
	{
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	Mint operator-()const
	{
		return Mint{ -mval };
	}
	//--------------------------------------------------------------------------------------------

	Mint& operator+=(Mint other)
	{
		mval += other.mval;
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	Mint& operator-=(Mint other)
	{
		mval -= other.mval;
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	Mint& operator*=(Mint other)
	{
		mval *= other.mval;
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	Mint& operator/=(Mint other)
	{
		mval /= other.mval;
		return *this;
	}
	//--------------------------------------------------------------------------------------------

	int get()const
	{
		return mval;
	}
	//--------------------------------------------------------------------------------------------

	void set(int x)
	{
		mval = x;
	}
	//--------------------------------------------------------------------------------------------

	friend  bool operator<(const Mint& x, const Mint& y)
	{
		return x.mval < y.mval;
	}
	//--------------------------------------------------------------------------------------------

	friend  bool operator==(const Mint& x, const Mint& y)
	{
		return x.mval == y.mval;
	}
	//--------------------------------------------------------------------------------------------

	friend std::ostream& operator<<(std::ostream& os, Mint val);
	friend std::istream& operator>>(std::istream& is, Mint& m);

	static Mint Random();
};

//global functions
//--------------------------------------------------------------------------------------------

inline  bool operator>(const Mint& x, const Mint& y)
{
	return y < x;
}

inline  bool operator>=(const Mint& x, const Mint& y)
{
	return !(x < y);
}

inline  bool operator<=(const Mint& x, const Mint& y)
{
	return !(y < x);
}

inline  bool operator!=(const Mint& x, const Mint& y)
{
	return !(x == y);
}


inline  Mint operator+(Mint x, Mint y)
{
	return x += y;
}

inline  Mint operator-(Mint x, Mint y)
{
	return x -= y;
}

inline  Mint operator*(Mint x, Mint y)
{
	return x *= y;
}

inline  Mint operator/(Mint x, Mint y)
{
	return x /= y;
}

#endif

