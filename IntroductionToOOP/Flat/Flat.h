#pragma once
class Flat
{
	float length{ float() };
	float width{ float() };
	float flat_area{ float() };
	float flat_price{ float() };

	Flat& setFlatArea(float);
	Flat& setFlatPrice(float);
	
	float getCostPerSquareMeter() const;

public:
	Flat(float, float);
	Flat();

	float getFlatArea() const;
	float getFlatPrice() const;

	static void setCostPerSquareMeter(float);

	bool operator== (const Flat&);
	bool operator!= (const Flat&);
	bool operator> (const Flat&);
	bool operator< (const Flat&);
};
	static float cost_per_square_meter { float() };

