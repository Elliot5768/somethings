#include <iomanip>

#include "Doctor.h"


Doctor::Doctor(const std::string& name,
			   const std::string& phone,
			   int age,
			   int id,
			   const std::string& specialization,
			   double fee)
	: Person(name, phone, age), id_(id), specialization_(specialization), fee_(fee) {}

int Doctor::getId() const {
	return id_;
}

std::string Doctor::getSpecialization() const {
	return specialization_;
}

double Doctor::getFee() const {
	return fee_;
}

PersonType Doctor::getRole() const {
	return PersonType::DOCTOR;
}

void Doctor::display(std::ostream& os) const {
	os << "[Doctor] ";
	Person::display(os);
	os << " | ID: " << id_
	   << " | " << specialization_
	   << " | Fee: Rs. " << std::fixed << std::setprecision(2) << fee_;
}