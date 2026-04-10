#include "Patient.h"

Patient::Patient(const std::string& name,
				 const std::string& phone,
				 int age,
				 int id)
	: Person(name, phone, age), id_(id) {}

int Patient::getId() const {
	return id_;
}

const std::vector<std::string>& Patient::getHistory() const {
	return history_;
}

void Patient::addHistory(const std::string& entry) {
	history_.push_back(entry);
}

PersonType Patient::getRole() const {
	return PersonType::PATIENT;
}

void Patient::display(std::ostream& os) const {
	os << "[Patient] ";
	Person::display(os);
	os << " | ID: " << id_ << " | ";
	if (history_.empty()) {
		os << "History: (none)";
	} else {
		os << "History: ";
		for (int i = 0; i < static_cast<int>(history_.size()); i++) {
			if (i > 0) {
				os << ", ";
			}
			os << history_[i];
		}
	}
}