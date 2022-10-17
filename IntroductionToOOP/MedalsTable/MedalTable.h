#pragma once
#include "MedalRow.h"

class MedalsTable
{
private:	
	size_t size{ size_t() };
	size_t max_size{ size_t () };
	MedalRow* medal_rows {nullptr};
	int findCountry(const char* country)const;

public:

	MedalsTable(size_t);

	MedalsTable(const MedalsTable&);
	MedalsTable& operator=(MedalsTable& other);

	MedalsTable(MedalsTable&&);
	MedalsTable& operator=(MedalsTable&& other);

	~MedalsTable();

	MedalRow& operator[](const char* country);	
	const MedalRow& operator[](const char* country)const;

	std::string operator()(const char* country) const;

	friend std::ostream& operator<<(std::ostream& output, const MedalsTable& object);
	
};
