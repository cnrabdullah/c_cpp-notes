//Bir ifadenin deger kategorisini ekrana yazdirmak

#include <iostream>

template <typename T>
struct ValCat {
    constexpr static const char* pstr{ "PR value" };
};

template <typename T>
struct ValCat <T&> {
    constexpr static const char* pstr{ "L value" };
};

template <typename T>
struct ValCat <T&&> {
    constexpr static const char* pstr{ "X value" };
};

#define vcat(exp)   (std::cout << "value category of \"" #exp "\" is : " << ValCat<decltype((exp))>::pstr << "\n");


