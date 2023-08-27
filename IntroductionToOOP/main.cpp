#include <iostream>
using namespace std;

#define tab "\t"
//#define STRUCT_POINT

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
		this -> x = x;
	}
	void set_y(double y) {
		this -> y = y;
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
	
	
	
	~Point() {
		cout << "Destructor:" tab << this << endl;
	}


	// Methods 

	void print()const {
		cout << "X = " << x << endl;
		cout << "Y = " << y << endl;
	}
	
	double distance(Point) {
		this->result = this->y - this->x;
		return this->result;
	}
};

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

	//Point A;        //Default Constructor
	////A.set_x(2);
	////A.set_y(3);
	////cout << A.get_x() << tab << A.get_y() << endl;
	//A.print();
	//
	//Point B = 5;   //Single-argument constructor 
	//Point C(2, 3);
	////C.print;

	Point Dis(20,30);
	Dis.print();
	cout << Dis.distance(Dis) << endl;	
	
}