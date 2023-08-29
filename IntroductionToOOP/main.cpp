﻿#include <iostream>
using namespace std;

#define tab "\t"
//#define DISTANCE
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

//Struct Discription 
class Point {
	double x;
	double y;
	double result;
public:
	double get_x()const {
		return x;
	}
	double get_y()const {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}

	// Constructors

	Point() {
		x = y = double();
		cout << "DefaultConstructor:" tab << this << endl;
	}



	Point(double x) {
		this->x = x;
		this->y = double();
		cout << "1ArgConstructor:" tab << this << endl;
	}

	Point(double x, double y) {
		this->x = x;
		this->y = y;
		cout << "Constructor:" tab << this << endl;
	}

	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}

	~Point() {
		cout << "Destructor:" tab << this << endl;
	}

	// Assigment operator

	Point operator=(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:" tab << this << endl;
		return *this;
	}

	Point operator+=(const Point& other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	//Increment/Decrement:

	Point operator++() {  // Prefix increment
		x++;
		y++;
		return *this;
	}

	Point operator++(int) {
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point operator()(double x, double y) {
		set_x(x);
		set_y(y);
		return *this;
	}

	// Methods 

	void print()const {
		cout << "X = " << x << tab << "Y = " << y << endl;
	}

	double distance(Point) {
		this->result = this->y - this->x;
		return this->result;
	}


};

bool operator==(const Point& left, const Point& right) {
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	/*{
		return true;
	}
	else
	{
		return false;
	}*/
}

std::ostream& operator<<(std::ostream & os, const Point & obj) {
	return os << "X= " << obj.get_x() << tab"Y = " << obj.get_y();
}

Point operator+(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}


void main() {
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;   // Объявление переменной 'a' типа int 
	Point A; // Создание переменной 'A' типа Point (Создание объекта А структуры Point)
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;
	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE
	Point Dis(20,30);
	Dis.print();
	cout << Dis.distance(Dis) << endl;	
#endif // DISTANCE
#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();
	
	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();
	
	Point D = C;
	D.print();

	Point E;
	E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	A = B = C = Point(4, 4);
#endif // ASSIGNMENT_CHECK

	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	Point C = A + B;
	C.print();

	A += B;
	A.print();
	
	B = A++;
	A.print();
	B.print();

	cout << (A == B) << endl;

	cout << A << endl;

	/*A.set_x(33);
	A.set_y(44);*/
	A(33, 44);
	A.print();




}