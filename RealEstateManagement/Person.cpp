#define _CRT_SECURE_NO_WARNINGS

#include "Person.h"

#include <string.h>
#include <iostream>

using namespace std;

#pragma region PropertiesManagement
Person::Person(const char* argName, const char* argEgn, const char* argAddress) {
    name = new char[strlen(argName) + 1];
    strncpy(name, argName, strlen(argName) + 1);

    egn = new char[strlen(argEgn) + 1];
    strncpy(egn, argEgn, strlen(argEgn) + 1);

    address = new char[strlen(argAddress) + 1];
    strncpy(address, argAddress, strlen(argAddress) + 1);
}

Person::~Person() {
    delete[] name;
    delete[] egn;
    delete[] address;
}

void Person::setName(const char* value) {
    delete[] name;
    name = new char[strlen(value) + 1];
    strncpy(name, value, strlen(value) + 1);
}

char* Person::getName() {
    return this->name;
}

void Person::setEgn(const char* value) {
    delete[] egn;
    egn = new char[strlen(value) + 1];
    strncpy(egn, value, strlen(value) + 1);
}

char* Person::getEgn() {
    return this->egn;
}

void Person::setAddress(const char* value) {
    delete[] address;
    address = new char[strlen(value) + 1];
    strncpy(address, value, strlen(value) + 1);
}

char* Person::getAddress() {
    return this->address;
}
#pragma endregion

#pragma region Functionallity
void Person::saveDetails(ostream& writer) const {
    writer << "Name:" << this->name << "\nEGN:" << this->egn << "\nAddress:" << this->address << endl;
}

ostream& operator<<(ostream & writer, const Person& person) {
    person.saveDetails(writer);
    return writer;
}

void Person::printUserData() {
    cout << "Id:" << this->egn << ", User:" << this->name << ", Home Address:" << this->address << ";\n";
}
#pragma endregion


