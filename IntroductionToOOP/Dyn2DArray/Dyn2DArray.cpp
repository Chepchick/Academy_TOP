#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include "Dyn2DArray.h"
//private:
int Dyn2DArray::index2D(int r, int c) const {	
	return r * columns + c;
}
int Dyn2DArray::index2D(int r, int c, int  columns) const {
	return r * columns + c;
}

//public:
Dyn2DArray::Dyn2DArray(int rows, int columns)
	:rows{ rows > 0 ? rows : 1 }, columns{ columns > 0 ? columns : 1 }, array_ptr{ new int[columns * rows] }{}

Dyn2DArray::Dyn2DArray(Dyn2DArray&& other)
	:array_ptr{ other.array_ptr }, rows{ other.rows }, columns{ other.columns } {
	other.array_ptr = nullptr;
	other.columns = float();
	other.rows = float();
}
Dyn2DArray& Dyn2DArray::operator=(const Dyn2DArray&& other) {
	if (!(this == &other))
	{
		if (rows * columns!= other.rows * other.columns)
		{
			delete[]array_ptr;
			array_ptr = new int[other.rows * other.columns ];
		}
		rows = other.rows;
		columns = other.columns;

		int* dest{ array_ptr };
		int* src{ other.array_ptr };
		int* const end_of_array{ array_ptr + columns * rows };

		while (dest < end_of_array) *dest++ = *src++;
	}
	return *this;
}
Dyn2DArray::~Dyn2DArray() { delete[] array_ptr; }

int Dyn2DArray::operator()(int r, int c) const {
	assert(r >= 0 && r < rows && "Rows index is out of range!");
	assert(c >= 0 && c < columns && "Columns index is out of range!");
	return *(array_ptr + index2D(r,c));
}
int& Dyn2DArray::operator()(int r, int c) {
	assert(r >= 0 && r < rows && "Rows index is out of range!");
	assert(c >= 0 && c < columns && "Columns index is out of range!");
	return *(array_ptr + index2D(r,c));
}

bool operator == (const Dyn2DArray& left, const Dyn2DArray& right) {
	if (!(left == right))
	{
		if (left.rows == right.rows && left.columns == right.columns) {
			for (size_t i = 0; i < left.columns * left.rows; i++)
				if (left.array_ptr[i] != right.array_ptr[i]) return false;		
		}
		else return false;
	}
	return true;
}
bool operator != (const Dyn2DArray& left, const Dyn2DArray& right) {
	return !(left == right);
}

const int  Dyn2DArray::getColumns() const {
	return columns;
}
const int  Dyn2DArray::getRows() const {
	return rows;
}

Dyn2DArray& Dyn2DArray::fillRandom(int min, int max) {
	srand(time(NULL));
	for (size_t i{0}; i < rows * columns; i++){
		array_ptr[i] = min + rand() % (max - min + 1);
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::fillRandom() {
	srand(time(NULL));
	for (size_t i{ 0 }; i < rows * columns; i++) {
		array_ptr[i] = 1 + rand() % 100;
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::clear() {
	for (size_t i{ 0 }; i < rows * columns; i++) {
		array_ptr[i] = NULL;
	}
	return *this;
}
bool Dyn2DArray::isEmpty() const{	
	for (size_t i = 0; i < rows * columns; i++) if (array_ptr[i]) return 0;

	return 1;
}

Dyn2DArray& Dyn2DArray::erase(int r, int c){
	assert(r >= 0 && r < rows && "Rows index is out of range!");
	assert(c >= 0 && c < columns && "Columns index is out of range!");

	*(array_ptr + index2D(r, c)) = NULL;

	return *this;
}
Dyn2DArray& Dyn2DArray::insert(int r, int c, int value) {
	assert(r >= 0 && r < rows && "Rows index is out of range!");
	assert(c >= 0 && c < columns && "Columns index is out of range!");

	*(array_ptr + index2D(r, c)) = value;

	return *this;
}

Dyn2DArray& Dyn2DArray::deleteColumn(int column_position) {
	assert(column_position >= 0 && column_position < columns && "Columns index is out of range!");

	--columns;
	int* new_array_ptr{ new int[rows * columns] };
	for (size_t r{ 0 }; r < rows; ++r)
	{
		for (size_t c{ 0 }; c < columns; ++c)
		{
			*(new_array_ptr + index2D(r,c)) = *(array_ptr + index2D(r, c + (c >= column_position), columns + 1));
		}
	}
	delete[] array_ptr;
	array_ptr = new_array_ptr;
	return *this;
}
Dyn2DArray& Dyn2DArray::addColumn(int column_position, int* new_column) {
	assert(column_position >= 0 && column_position < columns && "Columns index is out of range!");

	int* new_array_ptr{ new int[rows * (columns + 1)] };
	for (size_t r{ 0 }; r < rows; ++r)
	{
		for (size_t c{ 0 }; c < columns; ++c)
		{
			*(new_array_ptr + index2D(r, c + (c >= column_position), columns + 1)) = *(array_ptr + index2D(r, c));
		}
		*(new_array_ptr + index2D(r, column_position, columns + 1)) = new_column ? *(new_column + r) : 0;
	}
	delete[] array_ptr;
	array_ptr = new_array_ptr;
	++columns;
	return *this;
}

Dyn2DArray& Dyn2DArray::deleteRow(int row_position) {
	assert(row_position >= 0 && row_position < rows && "Rows index is out of range!");

	--rows;
	int* new_array_ptr{ new int[rows * columns] };
	for (int r{ 0 }; r < rows; ++r)
	{
		for (int c{ 0 }; c < columns; ++c)
		{
			*(new_array_ptr + index2D(r,c)) = *(array_ptr + index2D(r + (r >= row_position), c));
		}
	}
	delete[] array_ptr;
	array_ptr = new_array_ptr;
	return *this;
}
Dyn2DArray& Dyn2DArray::addRow(int row_position, int* new_row) {
	assert(row_position >= 0 && row_position < rows && "Rows index is out of range!");

	int* new_array_ptr{ new int[(rows + 1) * columns] };
	for (int r{ 0 }; r < rows; ++r) {
		for (int c{ 0 }; c < columns; ++c) {
			*(new_array_ptr + index2D(r + (r >= row_position), c)) = *(array_ptr + index2D(r,c));
		}
	}
	for (int c{ 0 }; c < columns; ++c) {
		*(new_array_ptr + index2D(row_position, c)) = new_row ? *(new_row + c) : 0;
	}
	delete[] array_ptr;
	array_ptr = new_array_ptr;
	++rows;
	return *this;
}

ostream& operator<<(ostream& output, const Dyn2DArray& arr) {
	for (size_t r{ 0 }; r < arr.rows; ++r)
	{
		for (size_t c{ 0 }; c < arr.columns; ++c)
		{
			output << (arr)(r,c) << '\t';
		}
		output << '\n';
	}
	output << '\n';
	return output;
}
istream& operator>>(istream& input, Dyn2DArray& object) {
	std::cout << "Введите значения эелементов массива в колличестве: " << object.rows * object.columns << " шт." << std::endl;
	for (size_t i{ 0 }; i < object.rows * object.columns; i++) {
		std::cout << "Значение " << i + 1 << "-го элемента: ";
		input >> object.array_ptr[i];
	}
	return input;
}
