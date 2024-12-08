#include <iostream>
#include <fstream>

#include "Person.h";
#include "RealEstateOwner.h"

/*
Александър Ганчев, фак. 121222032, група 45б

Да се дефинира базов клас за лице зададен с име, единен граждански номер и адрес. 
Да се дефинира производен клас, зададен с масив от указатели към адресите на недвижимите имоти за всяко лице (char *adr[n], n<=5). 
Класовете да включват конструктори, деструктори и член функции за извеждане. Да се реализира: 
1) извеждане на информацията за лицата, чиито адрес съвпада с някой от адресите на притежаваните имоти; 
2) извеждане на притежаваните имоти от лице, зададено с единния си граждански номер. 
3) Да се предефинира операцията <<, която да се използва за извеждане на данните. Данните да се съхраняват във файл.
*/

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
