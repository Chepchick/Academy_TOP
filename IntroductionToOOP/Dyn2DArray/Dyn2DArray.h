#pragma once
//#include <iostream>
using std::ostream;
using std::istream;
class Dyn2DArray
{
	int columns;
	int rows;
	int* array_ptr;

	int index2D(int, int) const;
	int index2D(int, int, int) const;

public:
	Dyn2DArray(int, int);
	Dyn2DArray() : Dyn2DArray(1, 1) {};
	Dyn2DArray(Dyn2DArray&&);
	Dyn2DArray& operator=(const Dyn2DArray&&);
	~Dyn2DArray();

	int operator()(int, int) const;
	int& operator()(int, int);

	friend bool operator == (const Dyn2DArray&, const Dyn2DArray&);
	friend bool operator != (const Dyn2DArray&, const Dyn2DArray&);
	
	const int getColumns() const;
	const int getRows() const;

	Dyn2DArray& fillRandom(int, int);
	Dyn2DArray& fillRandom();
	Dyn2DArray& clear();
	bool isEmpty() const;

	Dyn2DArray& erase(int, int);
	Dyn2DArray& insert(int, int, int);	

	Dyn2DArray& deleteColumn(int);
	Dyn2DArray& addColumn(int, int* new_column = nullptr);

	Dyn2DArray& deleteRow(int);
	Dyn2DArray& addRow(int, int* new_row = nullptr);

	friend ostream& operator<<(ostream&, const Dyn2DArray&);
	friend istream& operator>>(istream& input, Dyn2DArray&);
};

