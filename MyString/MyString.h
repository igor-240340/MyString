#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class MyString {
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	MyString(MyString&&);
	MyString& operator=(MyString&&);

	MyString& operator=(const char*);		// MyString = ""
	MyString& operator=(const MyString&);	// MyString = MyString

	bool operator<(const MyString&);			// MyString < MyString
	bool operator==(const char*);			// MyString == ""

	friend ostream& operator<<(ostream&, const MyString&);	// out << MyString
	friend istream& operator>>(istream&, MyString&);			// in >> MyString

	friend MyString operator+(const char*, const MyString&);			// "" + MyString
	friend MyString operator+(const MyString&, const MyString&);		// MyString + MyString
	friend MyString operator+(const MyString&, const char*);			// MyString + ""

private:
	char* data = nullptr;

	size_t Resize(const size_t);
};