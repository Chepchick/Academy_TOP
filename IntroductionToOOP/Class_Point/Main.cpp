#include <iostream>
using namespace std;

class Point {

private:
	double x = NULL;
	double y = NULL;

	void setX(double value_by_X) {
		if (value_by_X >= 0) {
			x = value_by_X;
		}
		else {
			cout << "Error! X value_by_X must be greater than zero.\n";
		}		
	}
	void setY(double value_by_Y) {
		if (value_by_Y >= 0) {
			y = value_by_Y;
		}
		else {
			cout << "\nError! Y value_by_X must be greater than zero.\n";
		}		
	}

	const double getX() const {
		return x;
	}
	const double getY() const {
		return y;
	}

public:
	Point() {
		setX(double());
		setY(double());
	}

	Point(double value_by_X, double value_by_Y) {
		setX(value_by_X);
		setY(value_by_Y);
	}

	Point(double value_by_X) {
		setX(value_by_X);
		setY(double());
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	Point& operator++()
	{
		x++, y++;
		return *this;
	}
	Point& operator++(int)
	{
		Point old = *this;
		x++, y++;
		return old;
	}
	

	~Point() {
		cout << "Destructor is called to the class: " << this << endl;
	}

	double getTheDistanceToThe(const Point& other) {
		return sqrt(pow(other.getX() - this->getX(), 2) + pow(other.getY() - this->getY(), 2));
	}

	void printX_Y() {
		cout << getX() << " " << getY() << endl;
	}	

	friend double getTheDistanceBetweenThe(const Point& A, const Point& B);
	friend Point& operator+(const Point& left, const Point& right);
};

double getTheDistanceBetweenThe(const Point& A,const Point& B) {
	return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
}

Point& operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.setX(left.getX() + right.getX());
	buffer.setY(left.getY() + right.getY());
	return buffer;
}

#define CONSTRUCTOR_CHECK
#define delimiter "\n-----------------------------------------------\n"

int main() {
	setlocale(LC_ALL, "ru");


	Point A, B, C;

	A = B = C = Point(2, 3);
	C = A + B;
	C.printX_Y();
	C++;
	C.printX_Y();
	++C;
	C.printX_Y();
	







	return 0;
}