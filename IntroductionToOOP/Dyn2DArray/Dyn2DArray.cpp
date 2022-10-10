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
Dyn2DArray& Dyn2DArray::transferNullToTheEndOfArray(Dyn2DArray& object) {
	for (size_t current_element{ 1 }; current_element < object.columns * object.rows; current_element++)
	{
		int temp{ object.array_ptr[current_element] };
		size_t iterating_element{ current_element };

		for (; iterating_element != NULL; iterating_element--) {
			object.array_ptr[iterating_element] = object.array_ptr[iterating_element - 1];
		}
		object.array_ptr[iterating_element] = temp;
	}
	return object;
}

//public:
Dyn2DArray::Dyn2DArray(int rows, int columns)
{
	this->rows = rows > 0 ? rows : 1;
	this->columns = columns > 0 ? columns : 1;
	array_ptr = new int[this->columns * this->rows];
}
Dyn2DArray::Dyn2DArray(Dyn2DArray&& other) {
	this->array_ptr = other.array_ptr;
	this->rows = other.rows;
	this->columns = other.columns;
	other.array_ptr = nullptr;
	other.columns = int();
	other.rows = int();
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
	if (!(&left == &right))
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
Dyn2DArray& Dyn2DArray::removeDuplicateValues() {
	for (size_t current_element{ 0 }; current_element < (rows * columns) - 1; current_element++)
	{
		if (array_ptr[current_element]) {
			for (size_t iterating_element{ current_element + 1 }; iterating_element < rows * columns; iterating_element++) {
				if (array_ptr[current_element] == array_ptr[iterating_element]) array_ptr[iterating_element] = NULL;
			}
		}
	}
	return *this;
}

Dyn2DArray& Dyn2DArray::wholeSortAscending() {

	for (size_t current_element{1}; current_element < columns * rows; current_element++)
	{
		int temp{ array_ptr[current_element] };
		size_t iterating_elements{ current_element };

		for (; iterating_elements > 0 && array_ptr[iterating_elements - 1] > temp; iterating_elements--) {
			array_ptr[iterating_elements] = array_ptr[iterating_elements - 1];
		}
		array_ptr[iterating_elements] = temp;
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::wholeSortDescending() {
	for (size_t current_element{ 1 }; current_element < columns * rows; current_element++)
	{
		int temp{ array_ptr[current_element] };
		size_t iterating_elements{ current_element };

		for (; iterating_elements > 0 && array_ptr[iterating_elements - 1] < temp; iterating_elements--) {
			array_ptr[iterating_elements] = array_ptr[iterating_elements - 1];
		}
		array_ptr[iterating_elements] = temp;
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::sortRowsAscending() {

	for (size_t current_row {0}; current_row < rows; current_row ++)
	{
		for (size_t current_element{ 1 }; current_element < columns; current_element++)
		{
			int temp{ (*this)(current_row, current_element) };
			size_t iterating_elements{ current_element };

			for (; iterating_elements > 0 && (*this)(current_row, iterating_elements - 1) > temp; iterating_elements--) {
				(*this)(current_row, iterating_elements) = (*this)(current_row, iterating_elements - 1);
			}
			(*this)(current_row, iterating_elements) = temp;
		}
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::sortRowsDescending() {

	for (size_t current_row{ 0 }; current_row < rows; current_row++)
	{
		for (size_t current_element{ 1 }; current_element < columns; current_element++)
		{
			int temp{ (*this)(current_row, current_element) };
			size_t iterating_elements{ current_element };

			for (; iterating_elements > 0 && (*this)(current_row, iterating_elements - 1) < temp; iterating_elements--) {
				(*this)(current_row, iterating_elements) = (*this)(current_row, iterating_elements - 1);
			}
			(*this)(current_row, iterating_elements) = temp;
		}
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::sortColumnsAscending() {

	for (size_t current_column{ 0 }; current_column < columns; current_column++)
	{
		for (size_t current_element{ 1 }; current_element < rows; current_element++)
		{
			int temp{ (*this)(current_element, current_column) };
			size_t iterating_elements{ current_element };

			for (; iterating_elements > 0 && (*this)(iterating_elements - 1, current_column) > temp; iterating_elements--) {
				(*this)(iterating_elements, current_column) = (*this)(iterating_elements - 1, current_column);
			}
			(*this)(iterating_elements, current_column) = temp;
		}
	}
	return *this;
}
Dyn2DArray& Dyn2DArray::sortColumnsDescending() {

	for (size_t current_column{ 0 }; current_column < columns; current_column++)
	{
		for (size_t current_element{ 1 }; current_element < rows; current_element++)
		{
			int temp{ (*this)(current_element, current_column) };
			size_t iterating_elements{ current_element };

			for (; iterating_elements > 0 && (*this)(iterating_elements - 1, current_column) < temp; iterating_elements--) {
				(*this)(iterating_elements, current_column) = (*this)(iterating_elements - 1, current_column);
			}
			(*this)(iterating_elements, current_column) = temp;
		}
	}
	return *this;
}

int Dyn2DArray::getSum() const{
	int result{ int() };

	for (size_t i{0}; i < rows * columns; i++) result += array_ptr[i];

	return result;
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
	assert(column_position >= 0 && column_position <= columns && "Columns index is out of range!");

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
	assert(row_position >= 0 && row_position <= rows && "Rows index is out of range!");

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
