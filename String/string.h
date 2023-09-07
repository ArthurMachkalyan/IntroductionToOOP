#pragma once

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
