#define _CRT_SECURE_NO_WARNINGS

#include "RealEstateOwner.h"

#pragma region PropertiesManagement
RealEstateOwner::RealEstateOwner(const char* argName, const char* argEgn, const char* argAddress) : Person(argName, argEgn, argAddress) {
	this->propertiesCount = 0;
	this->properties = new char*[5];
	for (int i = 0; i < 5; i++) {
		this->properties[i] = nullptr;
	}
}

RealEstateOwner::~RealEstateOwner() {
	if (this->properties != nullptr) {
		for (int i = 0; i < 5; i++) {
			if (this->properties[i] != nullptr) {
				delete[] this->properties[i];
			}
		}
		delete[] this->properties;
	}
}

char** RealEstateOwner::getProperties() {
	return this->properties;
}
#pragma endregion

#pragma region Functionallity
void RealEstateOwner::registerProperty(const char* propertyAddress) {
	if (this->propertiesCount < 5) {
		this->properties[this->propertiesCount] = new char[strlen(propertyAddress)+1];
		strcpy(this->properties[this->propertiesCount], propertyAddress);
		this->propertiesCount++;
	}
	else {
		cout << "Invalid: This client has reached the maximum capacity of their registered properties.\n" << endl;
	}
}

void RealEstateOwner::saveDetails(ostream& writer) const {
	Person::saveDetails(writer);
	writer << "Properties in possession:\n";
	for (int i = 0; i < this->propertiesCount; i++) {
		writer << "- " << this->properties[i] << endl;
	}
}

bool RealEstateOwner::hasMatchingHomeAddress(){
	for (int i = 0; i < this->propertiesCount; i++) {
		if (strcmp(this->address, this->properties[i]) == 0) {
			this->printUserData();
			return true;
		}
	}

	return false;
}

void RealEstateOwner::printProperties() {
	cout << "Properties in possession:\n";
	for (int i = 0; i < this->propertiesCount; i++) {
		cout << "- " << this->properties[i] << "\n";
	}
}

void RealEstateOwner::accessProperties(const char* key) {
	// In order to access the properties of the given user, a key must be provided that matches the target's EGN
	if (strcmp(key, this->egn) == 0) {
		this->printProperties();
		return;
	}
	cout << "Access denied. You have provided an invalid key.\n";
}
#pragma endregion

