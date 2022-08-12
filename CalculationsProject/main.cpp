#include <iostream>
#include "Calculations.h"

int main()
{
    std::vector<double> vect {0.5, -1, 13, 56, 18};
    Calculations calc;
    calc.sortVectorAscending(vect);
    calc.sortVectorDescending(vect);

    std::vector<int> vectOfInts {2, 4, 3, 8, 18};

    auto result = calc.allOfAreEven(vectOfInts);

    std::string str1 = "anapacar";
    std::string str2 = "anapacar";

    auto resultVect = calc.findPlaceWhereElementsDiffer(str1, str2);

    try 
    {
        std::cout << "first char: " << resultVect.at(0) << "\nsecond char: " << resultVect.at(1);
    }
    catch(std::exception ex)
    {
        std::cout << "caught exception: " << ex.what();
    }
    

    return 0;
}