#include "string.h"

//////////////////////////////////////////////////////////////////////////////////
/////////////////           Определение класса - Class Definition       //////////


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
explicit String::String(int size) :size(size), str(new char[size] {}) {
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

//////////////////////////// Конец определения класса - Class Definition End /////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////