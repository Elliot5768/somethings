#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

enum class PersonType { DOCTOR, PATIENT };

class Person {
protected:
	std::string name_;
	std::string phone_;
	int age_;

public:
	Person(const std::string& name, const std::string& phone, int age);
	virtual ~Person() = default;

	std::string getName() const;
	std::string getPhone() const;
	int getAge() const;

	bool operator==(const Person& other) const;

	virtual PersonType getRole() const = 0;
	virtual void display(std::ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif
