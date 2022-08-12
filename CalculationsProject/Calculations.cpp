#include "Calculations.h"
#include <stdexcept>
#include <algorithm>

int Calculations::add(int a, int b)
{
	return a + b;
}

int Calculations::compareGreater(int a, int b) 
{
    if ( a < 0 || b < 0 ) {
        throw std::invalid_argument( "received negative value" );
    }

    return a > b ? a : b;
}

void Calculations::setVect(double a, double b, double c)
{
    m_vect.push_back(a);
    m_vect.push_back(b);
    m_vect.push_back(c);
}

std::vector<double> Calculations::getVect()
{
    return m_vect;
}

void Calculations::sortVectorAscending(std::vector<double>& vect)
{
    std::ranges::sort(vect);
}

void Calculations::sortVectorDescending(std::vector<double>& vect)
{
    std::ranges::sort(vect, std::ranges::greater());
}

bool Calculations::allOfAreEven(std::vector<int> vect)
{
    return std::ranges::all_of(vect, [](int x){ return x % 2 == 0; });
}

bool Calculations::anyOfAreEven(std::vector<int> vect)
{
    return std::ranges::any_of(vect, [](int x){ return x % 2 == 0; });
}

bool Calculations::checkIfContainsKeyAndGetValue(std::map<int, std::string> m, int key, std::string& value)
{
    if (m.contains(key)) // contains C++ 20
    {
        value = m.at(key);
        return true;
    }
    else
    {
        value = "not found";
        return false;
    }
}

std::vector<char> Calculations::findPlaceWhereElementsDiffer(std::string_view str1, std::string_view str2)
{
    auto result = std::ranges::mismatch(str1, str2);
    auto iter1 = static_cast<std::string_view::const_iterator>(result.in1);
    auto iter2 = static_cast<std::string_view::const_iterator>(result.in2);
    if (iter1 != str1.end() && iter2 != str2.end())
    {
        return {*iter1, *iter2};
    }
    
    return {};
}

//void findTwoEqualConsecutiveElements(std::vector<>)