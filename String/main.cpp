#include <iostream>
using namespace std;

#define delimetr "\n----------------------------------\n"
class String;
String operator+(const String& left, const String& right);
class String {
	int size;     // size string 
	char* str;  // string adress in dynamic memory

public:

	const char* get_str()const {
		return str;
	}
	char* get_str() {
		return str;
	}
	int get_size()const {
		return size;
	}
	int set_size(int size) {
		this->size = size;
	}


	//           Constructors:
	explicit String(int size = 80) {
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:" << this << endl;
	}

	String(const char* str) {
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other) {
		this->size = other.size;
		this->str = other.str;
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:" << this << endl;
	}

	String& operator=(const String& other) {
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

	String& operator=(String&& other) {
		if (this == &other)return *this;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
	}

	String(String&& other) {
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;

	}

	//           Methods:
	void print()const {
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

	char operator[] (int i)const {
		return str[i];
	}
	char& operator[] (int i) {
		return str[i];
	}

	String& operator+=(const String& other) {
		*this = *this + other;
		return *this;
	}
};

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

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
#define OPERATOR_PLUS_EQUAL_CHECK

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

 
}