#include "Flat.h"

//privat:
Flat& Flat::setFlatArea(float flat_area) {
	this->flat_area = flat_area > 0 ? flat_area : 0;
	return *this;
}
Flat& Flat::setFlatPrice(float flat_price) {
	this->flat_price = flat_price > 0 ? flat_price : 0;
	return *this;
}

float Flat::getFlatArea() const {
	return flat_area;
}

//public:

Flat::Flat(float length, float width)
	 :length{ length }, width{ width }
{
	setFlatArea(length* width);
	setFlatPrice(getCostPerSquareMeter()* getFlatArea());
}
Flat::Flat() {};

float Flat::getFlatPrice() const {
	return flat_price;
}
float Flat::getCostPerSquareMeter() const {
	return cost_per_square_meter;
}

void Flat::setCostPerSquareMeter(float cost) {
	cost_per_square_meter = cost > 0 ? cost : 0;
	
}

bool Flat::operator== (const Flat& other) {
	return this->getFlatArea() == other.getFlatArea();
}
bool Flat::operator!= (const Flat& other) {
	return !(this->operator==(other));
}
bool Flat::operator> (const Flat& other) {
	return this->getFlatPrice() > other.getFlatPrice();
}
bool Flat::operator< (const Flat& other) {
	return !(this->operator<(other));
}