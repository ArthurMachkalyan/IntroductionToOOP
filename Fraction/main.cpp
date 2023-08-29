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

	// Assigment operator 

	Fraction operator=(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
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
		Fraction old = *this;
		integer--;
		numerator--;
		denominator--;
		return old;
	}
	
	Fraction operator+=(const Fraction& rvalue) {
		this->integer = this->integer + rvalue.integer;
		this->numerator = ((this->denominator * this->integer + this->numerator) + (rvalue.denominator * rvalue.integer + rvalue.numerator));
		this->denominator = this->denominator * rvalue.denominator;
		return *this;
	}

	Fraction operator-=(const Fraction& rvalue) {
		this->integer = this->integer - rvalue.integer;
		this->numerator = (this->get_numerator() * rvalue.get_denominator()) - (this->get_denominator() * rvalue.get_numerator());
		this->denominator = (this->get_denominator() * rvalue.get_denominator());
		return *this;
	}


	//print

	void print()const {
		cout << integer << " " << numerator << "/" << denominator;
	
	}
};

	Fraction operator+(const Fraction& lvalue, const Fraction& rvalue) {
		Fraction result;
		result.set_integer(lvalue.get_integer() + rvalue.get_integer());
		result.set_numerator(lvalue.get_numerator() * rvalue.get_denominator() + lvalue.get_denominator() * rvalue.get_numerator());
		result.set_denominator(lvalue.get_denominator() + rvalue.get_denominator());
		return result;
	}
	
	Fraction operator-(const Fraction& lvalue, const Fraction& rvalue) {
		Fraction result;
		result.set_integer(lvalue.get_integer() - rvalue.get_integer());
		result.set_numerator((lvalue.get_numerator() * rvalue.get_denominator() - (lvalue.get_denominator() * rvalue.get_numerator())));
		result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
		return result;
	}

	Fraction operator*(const Fraction& lvalue, const Fraction& rvalue) {
		Fraction result;
		result.set_numerator((lvalue.get_denominator() * lvalue.get_integer() + lvalue.get_numerator()) * (rvalue.get_denominator()
			* rvalue.get_integer() + rvalue.get_numerator()));
		result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
		return result;
	}

	Fraction operator/(const Fraction& lvalue, const Fraction& rvalue) {
		Fraction result;
		result.set_integer(0);
		result.set_numerator(lvalue.get_numerator() * rvalue.get_denominator());
		result.set_denominator(lvalue.get_denominator() * rvalue.get_numerator());
		return result;
	}


void main() {
	setlocale(LC_ALL, "");

	Fraction a(2, 4);
	Fraction b(5, 7);
	a -= b;
	b += a;
	a.print();
	b.print();

}