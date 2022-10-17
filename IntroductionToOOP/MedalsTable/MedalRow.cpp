#include <iostream>
#include <cassert>
#include "MedalRow.h"

using namespace std;

//private
string MedalRow::getTypeOfMaxValueMedals() {
	size_t number{ 0 };
	int max{ medals[0] };

	for (size_t i{ 1 }; i < 3; i++)
	{
		if (max < medals[i]) {
			max = medals[i];
			number = i;
		}
	}
	return type_of_medals[number];
}

//public
MedalRow::MedalRow(const char* countryP, const int* medalsP)
{
	strcpy_s(country, 4, countryP ? countryP : "NON");
	for (int i{ 0 }; i < 3; ++i)
	{
		medals[i] = medalsP ? medalsP[i] : 0;
	}
}

MedalRow& MedalRow::setCountry(const char* countryP)
{
	if (countryP)
	{
		strcpy_s(country, 4, countryP);
	}
	return *this;
}
const char* MedalRow::getCountry()const { return country; }

int& MedalRow::operator[](int idx)
{
	assert((idx >= 0 and idx < 3) and "Index out "
		"of range!");
	return medals[idx];
}
int MedalRow::operator[](int idx)const
{
	assert((idx >= 0 and idx < 3) and "Index out "
		"of range!");
	return medals[idx];
}

std::ostream& operator<<(std::ostream& output, const MedalRow& object)
{
	std::cout << '[' << object.country << "]-( ";
	for (int i{ 0 }; i < 3; ++i)
	{
		std::cout << object.medals[i];
		if (i < 2) { std::cout << '\t'; }
	}
	std::cout << " )\n";

	return output;
}