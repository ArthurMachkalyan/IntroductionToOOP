#include <iostream>
using namespace std;

#define tab "\t"
#define delimetr "\n-------------------------------------\n"
//#define DISTANCE_CHECK
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK
//#define OPERATORS_CHECK

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

	Point& operator=(const Point& other) {
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

	double distance(const Point& other) {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(const Point& A, const Point& B) {
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
}

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

#ifdef DISTANCE_CHECK
	Point a(2, 3);
	Point b(7, 8);
	cout << delimetr << endl;
	cout << "Расстояние от точки 'A'до точки 'B': " tab << a.distance(b) << endl;
	cout << delimetr << endl;
	cout << "Расстояние от точки 'A'до точки 'B': " tab << b.distance(a) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между точками 'A' и 'B': " tab << distance(a,b) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между точками 'B' и 'A': " tab << distance(b,a) << endl;
	cout << delimetr << endl;

	

#endif // DISTANCE_CHECK

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
	cout << delimetr << endl;
	A = B = C = Point(4, 4);
	cout << delimetr << endl;

#endif // ASSIGNMENT_CHECK

#ifdef OPERATORS_CHECK
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

#endif //  OPERATORS_CHECK





}