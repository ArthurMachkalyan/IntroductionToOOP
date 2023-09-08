#include "Fraction.h"


double Fraction::get_integer()const {
	return integer;
}

double Fraction::get_numerator()const {
	return numerator;
}

double Fraction::get_denominator()const {
	return denominator;
}

void Fraction::set_integer(double integer) {
	this->integer = integer;
}

void Fraction::set_numerator(double numerator) {
	this->numerator = numerator;
}

void Fraction::set_denominator(double denominator) {
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}


//DefConstructor
Fraction::Fraction() {
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Constructor" << endl;
}

explicit Fraction::Fraction(int integer) {
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	this->integer = 0;
	this->numerator = numerator;
	this->denominator = denominator;
}

Fraction::Fraction(int integer, int numerator, int denominator) {
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
}

Fraction::Fraction(double decimal) {
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 10e+9;
	numerator = decimal * denominator;
	reduce();
}

//CopyConstructor
Fraction::Fraction(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}


Fraction::~Fraction() {};

Fraction& Fraction::to_improper() {
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper() {
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}


// Assigment operator 

Fraction& Fraction::operator=(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}



Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}

Fraction Fraction::operator--()
{
	integer--;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	integer--;
	return temp;
}

Fraction Fraction::operator+=(Fraction rvalue) {
	this->to_improper();
	rvalue.to_improper();
	this->numerator = (this->numerator * rvalue.get_denominator()) + (this->denominator * rvalue.get_numerator());
	this->denominator = this->denominator * rvalue.get_denominator();
	return *this;

}

Fraction Fraction::operator-=(Fraction rvalue) {
	this->to_improper();
	rvalue.to_improper();
	this->numerator = (this->numerator * rvalue.get_denominator()) - (this->denominator * rvalue.get_numerator());
	this->denominator = this->denominator * rvalue.get_denominator();
	return *this;
}

Fraction Fraction::operator*=(const Fraction rvalue) {
	/*this->to_improper();
	rvalue.to_improper();
	this->numerator = this->numerator * rvalue.get_numerator();
	this->denominator = this->denominator * rvalue.get_denominator();
	return *this;*/

	return *this = *this * rvalue;
}

Fraction Fraction::operator/=(Fraction rvalue) {
	/*this->to_improper();
	rvalue.to_improper();
	this->numerator = this->numerator * rvalue.get_denominator();
	this->denominator = this->denominator * rvalue.get_numerator();
	return *this;*/

	return *this = *this * rvalue;
}

Fraction Fraction::inverted()const {
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.denominator, inverted.numerator);
	return inverted;
}

Fraction& Fraction::reduce() {
	if (numerator == 0)return *this;
	int more, less, rest;
	if (numerator > denominator) more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; // GCD - Gratest Common Divisor
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

//print

void Fraction::print()const {
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

explicit Fraction::operator int() {
	return to_proper().integer;
}

explicit Fraction::operator double() {
	return integer + (double)numerator / denominator;
}

//#define CONSTRUCTORS_CHECK

//----------------------Arithmetical operators-------------------------------------------

Fraction operator+(Fraction lvalue, Fraction rvalue) {
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
	/*Fraction result;
	result.set_numerator(lvalue.get_numerator() * rvalue.get_numerator());
	result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
	result.to_proper();*/

	/*Fraction result(lvalue.get_numerator() * rvalue.get_numerator(), lvalue.get_denominator() * rvalue.get_denominator());
	result.to_proper();
	return result;*/

	return Fraction
	(
		lvalue.get_numerator() * rvalue.get_numerator(),
		lvalue.get_denominator() * rvalue.get_denominator()
	).to_proper().reduce();

}

Fraction operator/(const Fraction& lvalue, const Fraction& rvalue) {
	/*	lvalue.to_improper();
		rvalue.to_improper();
		Fraction result;
		result.set_numerator(lvalue.get_numerator() * rvalue.get_denominator());
		result.set_denominator(lvalue.get_denominator() * rvalue.get_numerator());
		return result;*/

	return lvalue * rvalue.inverted();
}

bool operator==(Fraction left, Fraction right) {
	/*left.to_improper();
	right.to_improper();
	if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
	return true;
	else return false;*/

	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right) {
	return !(left == right);
}

bool operator>(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * right.get_denominator();

}

bool operator<(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * right.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right) {
	return !(left < right);
}

bool operator<= (const Fraction& left, const Fraction& right) {
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}

std::istream& operator>>(std::istream& os, Fraction& obj) {
	int integer, numerator, denominator;
	os >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return os;

	const int SIZE = 256;
	char sz_buffer[SIZE]{};
	os >> sz_buffer;
	int number[3] = {};

	char delimeters[] = "()/";
	int n = 0;
	for (char* pch = strtok(sz_buffer, delimeters); pch; pch = strtok(NULL, delimeters))
	{
		number[n++] = std::atoi(pch);
	}

	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}
	return os;
}
