#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include "Person.h"

class Doctor : public Person {
private:
	int id_;
	std::string specialization_;
	double fee_;

public:
	Doctor(const std::string& name,
		   const std::string& phone,
		   int age,
		   int id,
		   const std::string& specialization,
		   double fee);

	int getId() const;
	std::string getSpecialization() const;
	double getFee() const;

	PersonType getRole() const override;
	void display(std::ostream& os) const override;
};

#endif
