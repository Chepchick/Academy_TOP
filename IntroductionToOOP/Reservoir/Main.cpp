#include <iostream>
#include "Reservoir.h"

using namespace std;

void addNewReservoir(Reservoir*&, int&);

int main() {
	setlocale(LC_ALL, "");
	int number_of_reservoirs_in_cube = 5;
	Reservoir* cube_reservoirs = new Reservoir[number_of_reservoirs_in_cube];
	cube_reservoirs[0] = { "asdfel","fresh",26777,1135,35 };
	cube_reservoirs[1] = { "oqtga","fresh",4545,982,14 };
	cube_reservoirs[2] = { "kifogn","salt",4626,5345,69 };
	cube_reservoirs[3] = { "mevacav","salt",567,5345,692 };
	cube_reservoirs[4] = { "asgaha","salt",462724,5541516,57754 };

	addNewReservoir(cube_reservoirs, number_of_reservoirs_in_cube);

	for (size_t i = 0; i < number_of_reservoirs_in_cube; i++) {
		cout << cube_reservoirs[i] << endl;
	}
	cout << endl;
	cout << cube_reservoirs[5].getSurfaceArea() << endl;
	cout << cube_reservoirs[5].getApproximateAmount() << endl;

	return 0;
}

void addNewReservoir(Reservoir*& array_of_reservoirs, int& number_of_reservoirs) {
	Reservoir* temp_array = new Reservoir[number_of_reservoirs + 1];
	for (size_t i {0}; i < number_of_reservoirs; i++) {
		temp_array[i] = array_of_reservoirs[i];
	}
	cin >> temp_array[number_of_reservoirs];
	delete[]array_of_reservoirs;
	array_of_reservoirs = temp_array;
	number_of_reservoirs++;
}