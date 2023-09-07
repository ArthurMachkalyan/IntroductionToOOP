#include <iostream>
using namespace std;

#define delimetr "\n----------------------------------\n"
class String;
String operator+(const String& left, const String& right);

//////////////////////////////////////////////////////////////////////////////////
/////////////////           ќбъ€вление класса - Class Declaration       //////////
class String {
	int size;     // size string 
	char* str;  // string adress in dynamic memory

public:

	const char* get_str()const;
	char* get_str();
	int get_size()const;
	int set_size(int size);


	//           Constructors:
	explicit String(int size = 80);

	String(const char* str);

	String(const String& other);

	String& operator=(const String& other);

	String& operator=(String&& other);

	String(String&& other);

	~String();

	//           Methods:
	void print()const;

	char operator[] (int i)const;
	char& operator[] (int i);

	String& operator+=(const String& other);
};
////////////////////////////  онец объ€влени€ класса - Class Declaration End /////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------------------------------------------//

//////////////////////////////////////////////////////////////////////////////////
/////////////////           ќпределение класса - Class Definition       //////////


const char* String::get_str()const {
	return str;
}

char* String::get_str() {
	return str;
}

int String::get_size()const {
	return size;
}

int String::set_size(int size) {
	this->size = size;
}



//           Constructors:
explicit String::String(int size = 80) :size(size), str(new char[size] {}) {
	/*this->size = size;
	this->str = new char[size] {};*/
	cout << "DefaultConstructor:" << this << endl;
}

String::String(const char* str) :String(strlen(str) + 1) {
	/*this->size = strlen(str) + 1;
	this->str = new char[size] {};*/
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t" << this << endl;
}

String::String(const String& other) :String(other.str) {
	/*this->size = other.size;
	this->str = other.str;*/
	/*for (int i = 0; i < size; i++)this->str[i] = other.str[i];*/
	cout << "CopyConstructor:" << this << endl;
}

String& String::operator=(const String& other) {
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other) {
	if (this == &other)return *this;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str) {
	/*this->size = other.size;
	this->str = other.str;*/
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}

String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;

}

//           Methods:
void String::print()const {
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

char String::operator[] (int i)const {
	return str[i];
}
char& String::operator[] (int i) {
	return str[i];
}

String& String::operator+=(const String& other) {
	return *this = *this + other;
}

String operator+(const String& left, const String& right) {
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[left.get_size() - 1 + i] = right[i];
	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj) {
	return os << obj.get_str();
}

////////////////////////////  онец определени€ класса - Class Definition End /////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

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