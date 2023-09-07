#include "string.h"

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define OPERATOR_PLUS_EQUAL_CHECK

void main() {
	setlocale(LC_ALL, "");


#ifdef CONSTRUCTORS_CHECK
	String str(5);
	str.print();
	//cout << str << endl;

	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimetr;
	String str3 = str1 + str2;
	cout << delimetr;
	cout << str3 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef OPERATOR_PLUS_EQUAL_CHECK
	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_EQUAL_CHECK

	String str1; // Default tConstructor
	str1.print();

	String str2(5); // Single-Argument Constructor
	str2.print();

	String str3 = "Hello"; //Single-Argument Constructor
	str3.print();

	String str4(); // «десь не создаетс€ никакой объект, здесь объ€вл€етс€ функци€ 'str4'
	               // котора€ ничего не принимает, возвращает объект класса String
	//str4.print();

	String str5{};  // явно вызываетс€ конструктор по умолчанию
	str5.print();

	String str6("World");
	str6.print();

	String str7{ "Compile" };
	str7.print();

	String str8 = str3; //Copy Constructor
	str8.print();

	String str9;
	str9 = str6;
	str9.print();
}