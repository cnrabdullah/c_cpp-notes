#define		_CRT_SECURE_NO_WARNINGS


#include <iostream>


class String {

private:
	size_t	mlen;
	char* mp;
public:

	/* Default Constructor */
	String() : mlen{ 0 }, mp{ nullptr }
	{

	}

	/* Parameter Constructor */
	String(const char* m) : mlen{ std::strlen(m) }
	{
		mp = static_cast<char*>(malloc(mlen + 1));
		if (!mp)
		{
			std::cerr << "bellek yetersiz\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "parameter constructor this = " << this << "\n";
		std::cout << "the address of allocated block : " << (void*)mp << "\n";
		std::strcpy(mp, m);
	}

	/* Copy Constructor */
	String(const String& other) : mlen{ other.mlen }
	{
		mp = static_cast<char*>(malloc(mlen + 1));
		if (!mp)
		{
			std::cerr << "bellek yetersiz\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "copy constructor this = " << this << "\n";
		std::cout << "the address of allocated block : " << (void*)mp << "\n";
		std::strcpy(mp, other.mp);
	}

	/* Copy Assignment Function */
	String& operator=(const String& other)
	{
		std::cout << "copy assignment function this = " << this << "\n";

		if (mp) {
			std::free(mp);
		}
		mlen = other.mlen;
		mp = static_cast<char*>(malloc(mlen + 1));
		if (!mp)
		{
			std::cerr << "bellek yetersiz\n";
			std::exit(EXIT_FAILURE);
		}

		std::strcpy(mp, other.mp);

		return *this;
	}

	/* Move Constructor */
	String(String&& other) : mlen{ other.mlen }, mp{ other.mp }
	{
		std::cout << "move constructor this = " << this << "\n";
		other.mp = nullptr;
	}

	/* Move Assignment Function */
	String& operator=(String&& other)
	{
		std::cout << "move assignment function this = " << this << "\n";

		mlen = other.mlen;
		mp = other.mp;
		other.mp = nullptr;

		return *this;
	}

	/* Destructor */
	~String()
	{
		std::cout << "destructor this = " << this << "\n";

		if (mp) {
			std::free(mp);
		}
		std::cout << "the address of freed block : " << (void*)mp << "\n";
	}

	size_t length()const
	{
		return mlen;
	}
	void print()const
	{
		if (mp) {
			std::cout << "[" << mp << "]\n";
		}
	}

};

