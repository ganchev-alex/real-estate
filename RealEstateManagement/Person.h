#include <iostream>
using namespace std;

#pragma once
class Person
{
	protected:
		char *name;
		char *egn;
		char *address;
		virtual void saveDetails(ostream& writer) const;
	public:
		Person(const char* argName, const char* argEgn, const char* argAddress);
		virtual ~Person();
		void setName(const char* value);
		char* getName();
		void setEgn(const char* value);
		char* getEgn();
		void setAddress(const char* value);
		char* getAddress();
		friend ostream& operator<<(ostream& writer, const Person& person);
		void printUserData();
};

