#include "Person.h"

#pragma once
class RealEstateOwner : public Person
{
	private:
		int propertiesCount;
		char** properties;
		void saveDetails(ostream& writer) const override;
	public:
		RealEstateOwner(const char* argName, const char* argEgn, const char* argAddress);
		~RealEstateOwner();
		char** getProperties();
		void printProperties();
		void registerProperty(const char* propertyAddress);
		bool hasMatchingHomeAddress();
		void accessProperties(const char* key);
};

