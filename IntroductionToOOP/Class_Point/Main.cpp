#include <iostream>
using namespace std;

class Point {

private:
	int x = NULL;
	int y = NULL;

	Point& setX(int value_by_X) {
		if (value_by_X > 0) {
			x = value_by_X;
		}
		else {
			cout << "Error! X value_by_X must be greater than zero.\n";
		}
		return *this;
	}
	Point& setY(int value_by_Y) {
		if (value_by_Y > 0) {
			y = value_by_Y;
		}
		else {
			cout << "\nError! Y value_by_X must be greater than zero.\n";
		}
		return *this;
	}

	const int getX() {
		return x;
	}
	const int getY() {
		return y;
	}

public:
	Point(int value_by_X, int value_by_Y) {
		setX(value_by_X).setY(value_by_Y);
	}

	double getTheDistanceToThe(Point& other) {
		return sqrt(pow(other.getX() - this->getX(), 2) + pow(other.getY() - this->getY(), 2));
	}

	friend double getTheDistanceBetweenThe(Point& A, Point& B);
};

double getTheDistanceBetweenThe(Point& A, Point& B) {
	return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
}



int main() {

	Point A(2, 3);
	Point B(7, 8);
	Point C(12, 6);

	double distance_between_points = A.getTheDistanceToThe(B);
	cout << distance_between_points << endl;

	distance_between_points = getTheDistanceBetweenThe(C, B);
	cout << distance_between_points;

	return 0;
}