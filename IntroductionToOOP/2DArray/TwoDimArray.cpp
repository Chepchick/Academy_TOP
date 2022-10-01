#include "TwoDimArray.h"

TwoDimArray& TwoDimArray::setColumns(int cols){
	columns = cols > 0 ? cols : 0;
	return *this;
}
TwoDimArray& TwoDimArray::setRows(int rows){
	this->rows = rows > 0 ? rows : 0;
	return *this;
}

const int TwoDimArray::getColumns() const{
	return columns;
}
const int TwoDimArray::getRows() const{
	return rows;
}

TwoDimArray::TwoDimArray(int columns, int rows) {
	setColumns(columns);
	setRows(rows);
	array_ptr = new int* [getRows()];
	for (size_t i = 0; i < getRows(); i++){
		array_ptr[i] = new int[getColumns()]{};
	}	
}
TwoDimArray::~TwoDimArray() {


}





