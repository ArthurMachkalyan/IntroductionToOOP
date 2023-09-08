#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#define tab "\t"

//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER

class Fraction;
Fraction operator*(Fraction lvalue, Fraction rvalue);
Fraction operator/(const Fraction& lvalue, const Fraction& rvalue);

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

	explicit Fraction(int integer) {
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

	Fraction(double decimal) {
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 10e+9;
		numerator = decimal * denominator;
		reduce();
	}

	//CopyConstructor
	Fraction(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}


	~Fraction() {};

	Fraction& to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}


	// Assigment operator 

	Fraction& operator=(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}



	Fraction& operator++()
	{
		integer++;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction operator--()
	{
		integer--;
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction temp = *this;
		integer--;
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

	Fraction operator*=(const Fraction rvalue) {
		/*this->to_improper();
		rvalue.to_improper();
		this->numerator = this->numerator * rvalue.get_numerator();
		this->denominator = this->denominator * rvalue.get_denominator();
		return *this;*/

		return *this = *this * rvalue;
	}

	Fraction operator/=(Fraction rvalue) {
		/*this->to_improper();
		rvalue.to_improper();
		this->numerator = this->numerator * rvalue.get_denominator();
		this->denominator = this->denominator * rvalue.get_numerator();
		return *this;*/

		return *this = *this * rvalue;
	}

	Fraction inverted()const {
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.denominator, inverted.numerator);
		return inverted;
	}

	Fraction& reduce() {
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

	explicit operator int() {
		return to_proper().integer;
	}

	explicit operator double() {
		return integer + (double)numerator / denominator;
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

	Fraction operator/(const Fraction& lvalue,const Fraction& rvalue) {
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
	
	bool operator<= (const Fraction & left, const Fraction & right) {
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

#define CONVERSIONS_HOME_WORK

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

#ifdef ARITHMETICAL_OPERATORS_CHECK
		Fraction A(2, 3, 4);
		A.print();

		Fraction B(3, 4, 5);
		B.print();

		Fraction C = A * B;
		C.print();

		C = A / B;
		C.print();

		A *= B;
		A.print();

		A /= B;
		A.print();

		A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
		for (Fraction i(1, 4); i.get_integer() < 10; i++)
		{
			i.print();
		}
#endif // INCREMENT_CHECK

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
		Fraction A = (Fraction)5;
		cout << A << endl;

		Fraction B;
		B = Fraction(8);
		cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
		
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
		Fraction A(52, 10);
		int a = (int)A;
		cout << a << endl;

		Fraction B(2, 3, 4);
		cout << B << endl;
		
		double b = (double)B;
		cout << b << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER


#ifdef CONVERSIONS_HOME_WORK
		Fraction A = 2.76;
		cout << A << endl;
#endif // CONVERSIONS_HOME_WORK

	}