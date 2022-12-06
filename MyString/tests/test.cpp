#include <assert.h>

#include "..\MyString.h"

const char* EMPTY_STRING = "";
const char* HELLO_STRING = "Hello world!";
const char* ONE_THOUSAND_STRING = "ceasjBoNbSK9Xco9gw5VwG8MAJYSuXQdvKof2Eh5wRVjlkRJPZgPYFB2eEJsz1rkiZq7ZJxUCaYXOhluE5nST97swouHtrVUYsKu7nGQ2HyL27MjOZ03pcgS8GuyXwAEj5lSVaQ0IAPfI2rxSMf9TAVWuBrJppimoUstItE5uhUiqgvrst63v4Zou3RRh4PnX9CwbuMTKCMqbPlj6T4rd2Wl9eedMhNOA7zqzk8b1mxXSIgpP8E6cRLUekj5mrCcosj35zwLiRgvmo9fgxNP6rIEKN9ElDIu7OoNX0VqKZlTBiWrFTtiBavjwxp5re6jpNTmt8jA6UrDcWkarenb4qDULN15BsJAqLU9yo3chUJbHYg0sKTIlosox2YR4n36ch0lIqXMKtVp3yJkLbYv5bMQIUiDYG10dv9M4dvtzHmacSSyd5K8H0fsbuvo3ML9UakuehsMqWfvwbUT9aEuAMfmqXtsbBmT0uHPuCXxPIiiWvdcRSO8iftowR1IcW2wv44qEHKJmUH8jtCNWthH65mlFClpmzyNqLqqYxb3dbpi2kMIs706hwNiREuIaU2qDylUFS2gyPwbM9ezl8zJ5Egqtkzkr2o7OVrIiBBaVeHv3fdereJotY4sATemnSC0wH5d98LICzQAbpeMQPHttOBXnDnF5CYcddXkZjsM2w9hj5ivmKgoqsKjOaFnw7jMKBfQij7aymh9poo8AccEUgje2yZk97kUAy78KY2QCcGCvKp41JeqtdO3OwpNOaAhJpr70PNXZpiSNQFudL4OFjNA0P5UIP7bLH8bYG9GDpAQ7Zn7TYamTtGfeSwijYO7MhY4JDHa6GJ5z9BZtEcY9gFg3D4iKsxBm1WSrxZYyOXkw91IksRuQWCwnMxuzxwfu9mPUUHZWGOd9jmc9OGzPJdCXXmudXN5FMxu94ZLMC6LMJ8EU0wSyoOljmGvMouF7Zt3e6q2tuUgbjtX5s6nL3MIsa6O1u0G2GcZaQ3W";

void PrintOK() {
	cout << " | OK" << endl;
}

void Declaration()
{
	cout << "DECLARATION TESTS" << endl;

	cout << "Test 1 | MyString()";
	MyString s1;
	assert(s1 == "");
	PrintOK();

	cout << "Test 2 | MyString(const char*)";
	MyString s2 = HELLO_STRING;
	assert(s2 == HELLO_STRING);
	PrintOK();

	cout << "Test 3 | MyString(const char*)";
	MyString s3 = ONE_THOUSAND_STRING;
	assert(s3 == ONE_THOUSAND_STRING);
	PrintOK();

	cout << "Test 4 | MyString(const MyString&)";
	MyString s4 = s3;
	assert(s4 == ONE_THOUSAND_STRING);
	PrintOK();

	cout << "Test 5 | MyString(MyString&&)";
	MyString s5 = "Hello";
	MyString s6 = s5 + " world!";
	assert(s6 == "Hello world!");
	PrintOK();
}

void Assignment() {
	cout << "ASSIGNMENT TESTS" << endl;

	cout << "Test 1 | self assignment";
	MyString s1 = HELLO_STRING;
	s1 = s1;
	assert(s1 == HELLO_STRING);
	PrintOK();

	cout << "Test 2 | MyString = MyString";
	MyString s2 = "foo";
	s2 = s1;
	assert(s2 == HELLO_STRING);
	PrintOK();

	cout << "Test 3 | MyString = \"\"";
	MyString s3 = "foo";
	s3 = "bar";
	assert(s3 == "bar");
	PrintOK();

	cout << "Test 4 | chain assignment";
	MyString s4;
	MyString s5;
	s5 = s4 = "bar";
	assert(s5 == "bar" && s4 == "bar");
	PrintOK();

	cout << "Test 5 | move assignment";
	MyString s6 = "Hello";
	MyString s7 = "foo";
	s7 = s6 + " world!";
	assert(s7 == "Hello world!");
	PrintOK();
}

void Concatenation() {
	cout << "CONCATENATION TESTS" << endl;

	cout << "Test 1 | MyString + MyString";
	MyString s1 = "Hello";
	MyString s2 = " world!";
	assert((s1 + s2) == "Hello world!");
	PrintOK();

	cout << "Test 2 | \"\" + MyString";
	assert(("Hello" + s2) == "Hello world!");
	PrintOK();

	cout << "Test 3 | MyString + \"\"";
	assert((s1 + " world!") == "Hello world!");
	PrintOK();
}

void Comparison() {
	cout << "COMPARISON TESTS (reverse lexicographical)" << endl;

	cout << "Test 1 | MyString < MyString";
	MyString s1 = "ABCA";
	MyString s2 = "abcb";
	assert(!(s1 < s2));
	PrintOK();

	cout << "Test 2 | MyString < MyString";
	MyString s3 = "ABCA";
	MyString s4 = "abca";
	assert(!(s3 < s4));
	PrintOK();

	cout << "Test 3 | MyString < MyString";
	MyString s5 = "ABCB";
	MyString s6 = "abca";
	assert(s5 < s6);
	PrintOK();

	cout << "Test 4 | MyString == \"\"";
	MyString s7 = "foo";
	assert(s7 == "foo");
	assert(!(s7 == "bar"));
	PrintOK();
}

void Stream() {
	cout << "STREAM TESTS" << endl;

	cout << "Test 1 | out << MyString";
	MyString s1 = HELLO_STRING;
	std::stringstream out;
	out << s1;
	assert(out.str() == HELLO_STRING);
	PrintOK();

	cout << "Test 2 | in >> MyString";
	MyString s2;
	MyString s3;
	std::stringstream in("string1\nstring2");
	in >> s2 >> s3;
	assert(s2 == "string1");
	assert(s3 == "string2");
	PrintOK();
}

void _main()
{
	Comparison();
	cout << endl;

	Declaration();
	cout << endl;

	Assignment();
	cout << endl;

	Concatenation();
	cout << endl;

	Stream();
}