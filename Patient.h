#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "Person.h"

class Patient : public Person {
private:
	int id_;
	std::vector<std::string> history_;

public:
	Patient(const std::string& name,
			const std::string& phone,
			int age,
			int id);

	int getId() const;
	const std::vector<std::string>& getHistory() const;
	void addHistory(const std::string& entry);

	PersonType getRole() const override;
	void display(std::ostream& os) const override;
};

#endif