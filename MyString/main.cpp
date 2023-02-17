#include <fstream>
#include <list>

#include "MyString.h"

int main()
{
	list<MyString> strings;

	ifstream inFile("in.txt");
	if (!inFile) {
		cout << "Can't open in.txt" << endl;
		exit(1);
	}

	MyString s;
	while (inFile >> s)
		strings.push_back(s);

	inFile.close();

	strings.sort();

	ofstream outFile("out.txt");
	if (!outFile) {
		cout << "Can't open out.txt" << endl;
		exit(1);
	}

	for (const auto& s : strings)
		outFile << s << endl;
	
	strings.clear();
	outFile.close();

	cout << "See result in out.txt" << endl;

	return 0;
}