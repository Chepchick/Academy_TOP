#pragma once

class MedalRow
{
	char country[4];
	int medals[3];

public:	

	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };

	MedalRow(const char*, const int*);
	MedalRow() : MedalRow(nullptr, nullptr) {};

	MedalRow& setCountry(const char* countryP);
	const char* getCountry()const;
	std::string getTypeOfMaxValueMedals();

	int& operator[](int idx);	
	int operator[](int idx)const;


	friend std::ostream& operator<<(std::ostream& output, const MedalRow& object);	
};
static const std::string type_of_medals[]{ "GOLD","SILVER","BRONZE" };