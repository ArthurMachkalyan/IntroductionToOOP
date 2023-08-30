#include <iostream>
using namespace std;
#define tab "\t"

class Fraction {
	int integer;
	int numerator;
	int denominator;
public:
	double get_integer()const {
		return integer;
	}

	double get_numerator()const {
		return numerator;
	}
	
	double get_denominator()const {
		return denominator;
	}

	void set_integer(double integer) {
		this->integer = integer;
	}

	void set_numerator(double numerator) {
		this->numerator = numerator;
	}

	void set_denominator(double denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}


	//DefConstructor
	Fraction() {
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor" << endl;
	}

	Fraction(int integer) {
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	
	Fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
	}

	Fraction(int integer, int numerator, int denominator) {
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}

	//CopyConstructor
	Fraction(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}


	~Fraction() {};

	void to_improper() {
		numerator += integer * denominator;
		integer = 0;
	}

	void to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
	}


	// Assigment operator 

	Fraction& operator=(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	Fraction operator++()		
	{
		integer++;
		numerator++;
		denominator++;
		return *this;
	}

	Fraction operator++(int)	
	{
		Fraction old = *this;
		integer++;
		numerator++;
		denominator++;
		return old;
	}

	Fraction operator--()		
	{
		integer--;
		numerator--;
		denominator--;
		return *this;
	}

	Fraction operator--(int)	
	{
		Fraction temp = *this;
		integer--;
		numerator--;
		denominator--;
		return temp;
	}
	
	Fraction operator+=(Fraction rvalue) {
		this->to_improper();
		rvalue.to_improper();
		this->numerator = (this->numerator * rvalue.get_denominator()) + (this->denominator * rvalue.get_numerator());
		this->denominator = this->denominator * rvalue.get_denominator();
		return *this;
		
	}

	Fraction operator-=(Fraction rvalue) {
		this->to_improper();
		rvalue.to_improper();
		this->numerator = (this->numerator * rvalue.get_denominator()) - (this->denominator * rvalue.get_numerator());
		this->denominator = this->denominator * rvalue.get_denominator();
		return *this;
	}

	Fraction operator*=(Fraction rvalue) {
		this->to_improper();
		rvalue.to_improper();
		this->numerator = this->numerator * rvalue.get_numerator();
		this->denominator = this->denominator * rvalue.get_denominator();
		return *this;
	}

	Fraction operator/=(Fraction rvalue) {
		this->to_improper();
		rvalue.to_improper();
		this->numerator = this->numerator * rvalue.get_denominator();
		this->denominator = this->denominator * rvalue.get_numerator();
		return *this;
	}


	//print

	void print()const {
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

//#define CONSTRUCTORS_CHECK

//----------------------Arithmetical operators-------------------------------------------

	Fraction operator+(Fraction lvalue,  Fraction rvalue) {
		lvalue.to_improper();
		rvalue.to_improper();
		Fraction result;
		result.set_numerator(lvalue.get_numerator() * rvalue.get_denominator() + lvalue.get_denominator() * rvalue.get_numerator());
		result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
		return result;
	}
	
	Fraction operator-(Fraction lvalue, Fraction rvalue) {
		lvalue.to_improper();
		rvalue.to_improper();
		Fraction result;
		result.set_numerator((lvalue.get_numerator() * rvalue.get_denominator()) - (lvalue.get_denominator() * rvalue.get_numerator()));
		result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
		return result;
	}

	Fraction operator*(Fraction lvalue, Fraction rvalue) {
		lvalue.to_improper();
		rvalue.to_improper();
		Fraction result;
		result.set_numerator(lvalue.get_numerator() * rvalue.get_numerator());
		result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
		return result;
	}

	Fraction operator/(Fraction lvalue, Fraction rvalue) {
		lvalue.to_improper();
		rvalue.to_improper();
		Fraction result;
		result.set_numerator(lvalue.get_numerator() * rvalue.get_denominator());
		result.set_denominator(lvalue.get_denominator() * rvalue.get_numerator());
		return result;
	}

void main() {
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction a;
	a.print();

	Fraction b(2, 3, 5);
	b.print();

	Fraction c(2, 5);
	c.print();


#endif // CONSTRUCTORS_CHECK

	Fraction A(1, 3);
	A.print();

	Fraction B(2, 5);
	B.print();

	Fraction C(1,2);
	C /= B;
	C.print();
}