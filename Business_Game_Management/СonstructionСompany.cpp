#include "СonstructionСompany.h"

BuildingSite* СonstructionСompany::beginConstructionOfPlant(int object_type) {
	BuildingSite* temp = new BuildingSite;
	switch (object_type)
	{
	case 1:
		temp->setObjectType(TypesOfObjects::usual_factory);
		temp->setConstructionPeriod(ConstructionTime::the_time_it_takes_to_build_a_usual_factory);
		temp->setConstructionCost(ConstructionCost::usual_factory_cost);
			break;
	case 2:
		temp->setObjectType(TypesOfObjects::automated_factory);
		temp->setConstructionPeriod(ConstructionTime::the_time_it_takes_to_build_a_autoamted_factory);
		temp->setConstructionCost(ConstructionCost::automated_factory_cost);
		break;
	case 3:
		temp->setObjectType(TypesOfObjects::factory_renovation);
		temp->setConstructionPeriod(ConstructionTime::renovation_time);
		temp->setConstructionCost(ConstructionCost::renovation_cost);
		break;
	default:
		break;
	}
	return temp;
}