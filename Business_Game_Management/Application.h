#pragma once
#include <iostream>

class Application {
private:

	std::string applicant = "not available";
	int number_of_units{ int() };
	int unit_cost{ int() };
	void setApplicant(std::string);
	void setNumberOfUnitsRequested(const int);
	void setPricePerUnit(const int);

public:
	Application() {};
	Application(int, int, std::string);
	std::string getApplicant() const;
	int getNumberOfUnitsRequested()const;
	int getPricePerUnit()const;
};

