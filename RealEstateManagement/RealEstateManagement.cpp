#include <iostream>
#include <fstream>

#include "Person.h";
#include "RealEstateOwner.h"

int main()
{
	RealEstateOwner owner1("Kaloyan Vasilev", "7709291749", "street 58, Georgi Rakovski");
	owner1.registerProperty("street 58, Georgi Rakovski");
	owner1.registerProperty("street 31, Sveta Troica");

	RealEstateOwner owner2("Petia Dobreva", "9008026435", "street 32, Svoboda");
	owner2.registerProperty("Private Property: The Green Hills");

	ofstream file("datasheet.txt");
	if (!file) {
		cerr << "Error: Data sheet could not load.\n";
		exit(1);
	}

	cout << "Registering the data to the datasheet...\n";
	file << owner1 << endl;
	file << owner2 << endl;
	file.close();
	cout << "Data saved successfully!\n\n";

	cout << "Testing hasMatchingHomeAddress Functionallity:\n";
	cout << "Result:" << owner1.hasMatchingHomeAddress() << "\n";
	cout << "Result:" << owner2.hasMatchingHomeAddress() << "\n";

	cout << "\nTesting owner's properties' access via an EGN key:\n";
	const char* testKey = "7709291749";
	owner1.accessProperties(testKey);
	owner2.accessProperties(testKey);

	return 0;
}
