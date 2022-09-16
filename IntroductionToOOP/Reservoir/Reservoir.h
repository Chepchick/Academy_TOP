#pragma once
#include <iostream>

class Reservoir
{
	std::string name_of_reservoir;
	std::string type_water;
	long long length;
	long long width;
	long long depth;
	long long surface_area{ int() };
	long long approximate_amount{ int() };
	
	const Reservoir& setNameOfReservoir(std::string);
	template <typename T1> Reservoir& setNameOfReservoir(T1) = delete;
	const Reservoir& setTypeOfWater(std::string);
	template <typename T1> Reservoir& setTypeOfWater(T1) = delete;
	const Reservoir& setLength(int);
	template <typename T1> Reservoir& setLength(T1) = delete;
	const Reservoir& setWidth(int);
	template <typename T1> Reservoir& setWidth(T1) = delete;
	const Reservoir& setDepth(int);
	template <typename T1> Reservoir& setDepth(T1) = delete;

	std::string getNameOfReservoir() const;
	std::string getTypeOfWater() const;
	int getLength() const;
	int getWidth() const;
	int getDepth() const;

	const Reservoir& setSurfaceArea();
	const Reservoir& setApproximateAmount();	

public:
	Reservoir(std::string, std::string, int, int, int);
	Reservoir() : Reservoir{"no information","no information",0,0,0} {};

	bool operator == (const Reservoir&);
	bool operator != (const Reservoir&);
	bool operator < (const Reservoir&);
	bool operator > (const Reservoir&);

	const double getSurfaceArea() const;
	const double getApproximateAmount() const;
	static std::string getTypeOfReservoir(const Reservoir&);


	friend std::ostream& operator<<(std::ostream& ,	const Reservoir&);
	friend std::istream& operator>>(std::istream& , Reservoir&);
};


