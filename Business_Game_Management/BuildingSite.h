#pragma once
class BuildingSite
{
private:
	int object_type{ int() };
	int construction_period{ int() };
	int construction_cost{ int() };

public:
	BuildingSite() {};	

	void setObjectType(const int);
	void setConstructionPeriod(const int);
	void setConstructionCost(const int);

	int getObjectType() const;
	int getConstructionPeriod() const;
	int getConstructionCost() const;

	void recalculateTheConstructionPeriod();
};

