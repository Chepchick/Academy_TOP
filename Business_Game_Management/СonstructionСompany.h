#pragma once
#include "BuildingSite.h"

static class СonstructionСompany
{
public:
	static BuildingSite* beginConstructionOfPlant(int);

	
};
static const enum TypesOfObjects {
	usual_factory,
	automated_factory,
	factory_renovation
};
static const enum ConstructionTime {
	the_time_it_takes_to_build_a_usual_factory = 5,
	the_time_it_takes_to_build_a_autoamted_factory = 7,
	renovation_time= 9
};
static const enum ConstructionCost {
	usual_factory_cost = 5000,
	automated_factory_cost = 10000,
	renovation_cost = 7000
};