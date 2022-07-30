#include <iostream>
using namespace std;

class Point {

private:
	int x = NULL;
	int y = NULL;

	Point& setX(int value_by_x) {
		if (value_by_x > 0) {
			x = value_by_x;
		}
		else {
			cout << "Error! X value_by_x must be greater than zero.\n";
		}
		return *this;
	}
	Point& setY(int value_by_y) {
		if (value_by_y > 0) {
			y = value_by_y;
		}
		else {
			cout << "\nError! Y value_by_x must be greater than zero.\n";
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
	Point(int x, int y) {
		setX(x).setY(y);
	}

	double getTheDistanceToThe(Point& other) {
		return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
	}

	friend double getTheDistanceBetweenThe(Point& A, Point& B);
};

double getTheDistanceBetweenThe(Point& A, Point& B) {
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}



int main() {

	Point A(1, 1);
	Point B(5, 5);
	Point C(12, 6);

	double distance_between_points = A.getTheDistanceToThe(B);
	cout << distance_between_points << endl;

	distance_between_points = getTheDistanceBetweenThe(C, B);
	cout << distance_between_points;

	return 0;
}