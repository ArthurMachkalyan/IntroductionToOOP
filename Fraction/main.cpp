#include "Fraction.h"


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