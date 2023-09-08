#pragma once
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
	double get_integer()const;

	double get_numerator()const;

	double get_denominator()const;

	void set_integer(double integer);

	void set_numerator(double numerator);

	void set_denominator(double denominator);


	//DefConstructor
	Fraction();

	explicit Fraction(int integer);

	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);

	Fraction(double decimal);

	//CopyConstructor
	Fraction(const Fraction& other);

	~Fraction() {};

	Fraction& to_improper();

	Fraction& to_proper();


	// Assigment operator 

	Fraction& operator=(const Fraction& other);


	Fraction& operator++();

	Fraction operator++(int);

	Fraction operator--();

	Fraction operator--(int);

	Fraction operator+=(Fraction rvalue);

	Fraction operator-=(Fraction rvalue);

	Fraction operator*=(const Fraction rvalue);

	Fraction operator/=(Fraction rvalue);

	Fraction inverted()const;

	Fraction& reduce();
	//print

	void print()const;

	explicit operator int();

	explicit operator double();
};
