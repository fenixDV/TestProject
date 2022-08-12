#pragma once
#include <vector>
#include <map>
#include <string>

class Calculations
{
public:
	int add(int a, int b);

	int compareGreater(int a, int b);

	void setVect(double a, double b, double c);

	std::vector<double> getVect();

	void sortVectorAscending(std::vector<double>& vect);
	void sortVectorDescending(std::vector<double>& vect);

	bool allOfAreEven(std::vector<int> vect);
	bool anyOfAreEven(std::vector<int> vect);

	bool checkIfContainsKeyAndGetValue(std::map<int, std::string> m, int key, std::string& value);

	std::vector<char> findPlaceWhereElementsDiffer(std::string_view str1, std::string_view str2);

private:
	std::vector<double> m_vect;
};