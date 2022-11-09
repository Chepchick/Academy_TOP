#include <iostream>
using namespace std;

struct Ring{
	Ring* ptr_lower_ring{nullptr};
	unsigned short ring_number{short()};
};
struct Pin {	
	Ring* upper_ring{nullptr};
	size_t size{ size_t() };
};

void putOnTop(Pin* pin, Ring* ring); //надеть кольцо на верх колышка
Ring* takeOutTheTop(Pin* pin);//снять верхнее кольцо с колышка
void shiftTheUpperRing(Pin* from, Pin* to);// переложить верхнее кольцо с одного колышка на другой
size_t getSizeTower(Pin*);// полуить размер башни

Pin* getNewTower(size_t size);//собрать башню указанного размера
void playHanoyTower(int number, Pin*, Pin*, Pin*);


int main() {
	setlocale(LC_ALL, "ru");
	Pin *from, *to, *temp;
	from = getNewTower(4);
	to = getNewTower(0);
	temp = getNewTower(0);

	cout << "Столбик from - " << from << " размером "<< from->size << " диска" << endl;
	cout << "Столбик to - " << to << " размером " << to->size << " диска" << endl;
	cout << "Столбик temp - " << temp << " размером " << temp->size << " диска" << endl << endl;

	playHanoyTower(4, from, to, temp);

	cout << "\nСтолбик from - " << from << " размером " << from->size << " диска" << endl;
	cout << "Столбик to - " << to << " размером " << to->size << " диска" << endl;
	cout << "Столбик temp - " << temp << " размером " << temp->size << " диска" << endl << endl;

	system("pause");
	return 0;
}

void putOnTop(Pin* pin, Ring* ring) {
	if (pin->upper_ring == nullptr)
	{
		pin->upper_ring = ring;
	}
	else {
		ring->ptr_lower_ring = pin->upper_ring;
		pin->upper_ring = ring;
	}
	pin->size++;
}
Ring* takeOutTheTop(Pin* pin) {
	if (pin->upper_ring != nullptr)
	{
		Ring* temp = pin->upper_ring;
		pin->upper_ring = pin->upper_ring->ptr_lower_ring;
		pin->size--;
		return temp;
	}
	else {
		cout << "Башня пустая" << endl;
	}
}
void shiftTheUpperRing(Pin* from, Pin* to) {
	cout << "Переместить диск №" << from->upper_ring->ring_number << " со столбика " << from << " на столбик " << to << endl;
	putOnTop(to, takeOutTheTop(from));
}
size_t getSizeTower(Pin* pin) { return pin->size; }

Pin* getNewTower(size_t size) {
	Pin* buf = new Pin;
	for (size_t i = size; i > 0; i--)
	{
		Ring* temp = new Ring;
		temp->ring_number = i;
		putOnTop(buf, temp);
	}
	return buf;
}
void playHanoyTower(int number, Pin* from, Pin* to, Pin* temp)
{
	if (number == 1)
	{
		shiftTheUpperRing(from, to);		
	}
	else {		
		playHanoyTower(number - 1, from, temp , to);
		shiftTheUpperRing(from, to);		
		playHanoyTower(number - 1, temp, to, from);
	}
}