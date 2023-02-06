#include "BuildingSite.h"

void BuildingSite::setObjectType(const int object_type) {
	this->object_type = object_type;
}
void BuildingSite::setConstructionPeriod(const int construction_period){
	this->construction_period = construction_period;
}
void BuildingSite::setConstructionCost(const int construction_cost){
	this->construction_cost = construction_cost;
}

int BuildingSite::getObjectType() const{
	return object_type;
}
int BuildingSite::getConstructionPeriod() const{
	return construction_period;
}
int BuildingSite::getConstructionCost() const{
	return construction_cost;
}

void BuildingSite::recalculateTheConstructionPeriod() {
	setConstructionPeriod(getConstructionPeriod() - 1);
}
