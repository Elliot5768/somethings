#include "Person.h"

Person::Person(const std::string& name, const std::string& phone, int age)
	: name_(name), phone_(phone), age_(age) {}

std::string Person::getName() const {
	return name_;
}

std::string Person::getPhone() const {
	return phone_;
}

int Person::getAge() const {
	return age_;
}

bool Person::operator==(const Person& other) const {
	return name_ == other.name_ && phone_ == other.phone_;
}

void Person::display(std::ostream& os) const {
	os << name_ << " | Phone: " << phone_ << " | Age: " << age_;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
	p.display(os);
	return os;
}