#pragma once
class TwoDimArray
{
	int** array_ptr{ nullptr };
	int columns{ int() };
	int rows{ int() };

	TwoDimArray& setColumns(int);
	TwoDimArray& setRows(int);

	const int getColumns() const;
	const int getRows() const;

public:

	TwoDimArray(int, int);
	TwoDimArray() : TwoDimArray { 1, 1 } {};
	~TwoDimArray();

	TwoDimArray(const TwoDimArray&&);
	TwoDimArray& operator=(const TwoDimArray&&);













};

