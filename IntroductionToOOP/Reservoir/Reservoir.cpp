#include "Reservoir.h"
#include <iomanip>

using namespace std;

//private
const Reservoir& Reservoir::setNameOfReservoir(std::string name) {
    if(name.length() > 0 && name.length() < 20) {
        name_of_reservoir = name;
    }
    else  cout << "Длина строки превышает максимальный размер в 20 символов!");
    return *this;
}
const Reservoir& Reservoir::setTypeOfWater(std::string type) {
	type_water = (type == "salt" || type == "fresh") ? type : "no information";
	return *this;
}
const Reservoir& Reservoir::setLength(int value) {
	length = value < 0 ? 0 : value;
	return *this;
}
const Reservoir& Reservoir::setWidth(int value) {
	width = value < 0 ? 0 : value;
	return *this;
}
const Reservoir& Reservoir::setDepth(int value) {
	depth = value < 0 ? 0 : value;
	return *this;
}

std::string Reservoir::getNameOfReservoir() const {
	return name_of_reservoir;
}
std::string Reservoir::getTypeOfWater() const {
	return type_water;
}
int Reservoir::getLength() const {
	return length;
}
int Reservoir::getWidth() const {
	return width;
}
int Reservoir::getDepth() const {
	return depth;
}

const Reservoir& Reservoir::setSurfaceArea() {
	surface_area = getLength() * getWidth();
	return *this;
}
const Reservoir& Reservoir::setApproximateAmount() {
	approximate_amount = getLength() * getWidth() * getDepth();
	return *this;
}

//public
Reservoir::Reservoir(std::string name, std::string type_water, int length, int width, int depth) {
	setNameOfReservoir(name);
	setTypeOfWater(type_water);
	setLength(length);
	setWidth(width);
	setDepth(depth);
	setSurfaceArea();
	setApproximateAmount();
}

bool Reservoir::operator==(const Reservoir& other) {
	return Reservoir::getTypeOfReservoir(*this) == Reservoir::getTypeOfReservoir(other);
}
bool Reservoir::operator!=(const Reservoir& other) {
	return !(this->operator==(other));
}
bool Reservoir::operator<(const Reservoir& other) {
	if (this->getTypeOfWater() == other.getTypeOfWater()) {
		return this->getSurfaceArea() < other.getSurfaceArea();
	} 
	else return false;	
}
bool Reservoir::operator>(const Reservoir& other) {
	return !(this->operator<(other));
}

const double Reservoir::getSurfaceArea() const {
	return surface_area / 1000000;
}
const double Reservoir::getApproximateAmount() const {
	return approximate_amount / 1000000000;
}
string Reservoir::getTypeOfReservoir(const Reservoir& object)  {
	if (object.type_water == "fresh")
	{
		if (object.getSurfaceArea() < 10 || object.getApproximateAmount() < 0.5) {
			return "POND";
		}
		else return "LAKE";
	}else{
		if (object.getSurfaceArea() < 1500000 || object.getApproximateAmount() < 1000000) {
			return "SEA";
		}
		else return "OCEAN";
	}
}

ostream& operator<<(ostream& output, const Reservoir& object) {
	output << "Тип водоема " << object.getNameOfReservoir() << " - " << Reservoir::getTypeOfReservoir(object);
	return output;
}
istream& operator>>(istream& input, Reservoir& object) {
	cout << "Введите значения в формате: название, тип воды, длина, ширина, глубина" << endl;
	input >> setw(5) >> object.name_of_reservoir;
	input.ignore(1);
	input >> setw(1) >> object.type_water;
	input.ignore(1);
	input >> setw(1) >> object.length;
	input.ignore(1);
	input >> setw(1) >> object.width;
	input.ignore(1);
	input >> setw(1) >> object.depth;
	return input;
}