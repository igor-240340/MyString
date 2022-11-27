#include "MyString.h"

MyString Concat(const char*, const char*);

MyString::MyString() {
	Resize(1);
	*data = '\0';
}

MyString::MyString(const char* s) {
	size_t size = Resize(strlen(s) + 1);
	strcpy_s(data, size, s);
}

MyString::MyString(const MyString& s) {
	size_t size = Resize(strlen(s.data) + 1);
	strcpy_s(data, size, s.data);
}

MyString::MyString(MyString&& s) {
	data = s.data;
	s.data = nullptr;
}

MyString::~MyString() {
	delete[] data;
}

MyString& MyString::operator=(MyString&& right) {
	data = right.data;
	right.data = nullptr;

	return *this;
}

MyString& MyString::operator=(const char* right) {
	size_t size = Resize(strlen(right) + 1);
	strcpy_s(data, size, right);

	return *this;
}

MyString& MyString::operator=(const MyString& right) {
	if (this == &right)
		return *this;

	size_t size = Resize(strlen(right.data) + 1);
	strcpy_s(data, size, right.data);

	return *this;
}

// For sorting in reverse lexicographical order
bool MyString::operator<(const MyString& right) {
	size_t leftLen = strlen(data) + 1;
	size_t rightLen = strlen(right.data) + 1;

	char* leftLowercase = new char[leftLen];
	char* rightLowercase = new char[rightLen];

	for (auto i = 0; i < leftLen; i++)
		leftLowercase[i] = tolower(data[i]);

	for (auto i = 0; i < rightLen; i++)
		rightLowercase[i] = tolower(right.data[i]);

	bool res = strcmp(leftLowercase, rightLowercase) > 0; // left > right

	delete[] leftLowercase;
	delete[] rightLowercase;

	return res;
}

bool MyString::operator==(const char* right) {
	return strcmp(data, right) == 0;
}

ostream& operator<<(ostream& out, const MyString& s) {
	return out << s.data;
}

// Reads line from stream to MyString
istream& operator>>(istream& in, MyString& s) {
	int bufferSize = 5 + 1;
	int nullPos = bufferSize - 1;

	char* buffer = new char[bufferSize];
	memset(buffer, 0, bufferSize);

	char c = ' ';
	int charPos = 0;
	while (in.get(c) && c != '\n') {
		if (charPos == nullPos) {
			// Preserve
			char* tmp = new char[bufferSize];
			strcpy_s(tmp, bufferSize, buffer);

			// Expand
			delete[] buffer;
			bufferSize = bufferSize + bufferSize - 1;
			nullPos = bufferSize - 1;
			buffer = new char[bufferSize];
			memset(buffer, 0, bufferSize);
			strcpy_s(buffer, strlen(tmp) + 1, tmp); // To preserve null characters

			delete[] tmp;
		}

		buffer[charPos++] = c;
	}

	s = buffer;
	delete[] buffer;

	return in;
}

MyString operator+(const char* left, const MyString& right) {
	return Concat(left, right.data);
}

MyString operator+(const MyString& left, const MyString& right) {
	return Concat(left.data, right.data);
}

MyString operator+(const MyString& left, const char* right) {
	return Concat(left.data, right);
}

MyString Concat(const char* left, const char* right) {
	size_t size = strlen(left) + strlen(right) + 1;
	char* res = new char[size];

	strcpy_s(res, size, left);
	strcat_s(res, size, right);

	MyString s = res;
	delete[] res;
	return s;
}

size_t MyString::Resize(const size_t size) {
	delete[] data;

	data = new char[size];
	return size;
}