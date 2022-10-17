#include <iostream>
#include <cassert>
#include "MedalRow.h"
#include "MedalTable.h"

//private
int MedalsTable::findCountry(const char* country)const
{
	for (int i{ 0 }; i < size; ++i)
	{
		if (strcmp(medal_rows[i].getCountry(), country) == 0) return i;
	}
	return -1;
}

//public
MedalsTable::MedalsTable(size_t size)
{
	max_size = size > 0 ? size : 0;
	medal_rows = new MedalRow[max_size];	
}

MedalsTable::MedalsTable(const MedalsTable& other) :
	medal_rows{ new MedalRow[other.size] }, size{ other.size }
{	for (size_t i{ 0 }; i < size; ++i)
	{
		medal_rows[i] = other.medal_rows[i];
	}
}
MedalsTable& MedalsTable::operator=(MedalsTable& other)
{
	if (!(this == &other))
	{
		if (size != other.size)
		{
			delete medal_rows;
			medal_rows = new MedalRow[other.size];
		}
		size = other.size;
		MedalRow* dest{ medal_rows };
		MedalRow* src{ other.medal_rows };
		MedalRow* const end{ medal_rows + size };
		while (dest < end)
		{
			*dest++ = *src++;
		}
	}
	return *this;
}

MedalsTable::MedalsTable(MedalsTable&& other)
{
	this->medal_rows = other.medal_rows;
	this->size = other.size;
	other.medal_rows = nullptr;
	other.size = 0;
}
MedalsTable& MedalsTable::operator=(MedalsTable&& other)
{
	if (!(this == &other))
	{
		delete medal_rows;
		medal_rows = other.medal_rows;
		size = other.size;
		other.medal_rows = nullptr;
		other.size = 0;
	}
	return *this;
}

MedalsTable::~MedalsTable()
{
	delete[]medal_rows;
}

MedalRow& MedalsTable::operator[](const char* country)
{
	int idx{ findCountry(country) };
	if (idx == -1)
	{
		assert(size < MedalsTable::max_size and
			"Table is FULL!");
		idx = size++;
		medal_rows[idx].setCountry(country);
	}
	return medal_rows[idx];
}
const MedalRow& MedalsTable::operator[](const char* country)const
{
	int idx{ findCountry(country) };
	assert(idx != -1 and "Country not found on const "
		"table");
	return medal_rows[idx];
}

std::string MedalsTable::operator()(const char* country) const {
	int idx{ findCountry(country) };
	assert(idx != -1 and "Country not found on const table");
	return medal_rows[idx].getTypeOfMaxValueMedals();
}

std::ostream& operator<<(std::ostream& output, const MedalsTable& object)
{
	for (int i{ 0 }; i < object.size; ++i)
	{
		output << object.medal_rows[i];
	}
	return output;
}