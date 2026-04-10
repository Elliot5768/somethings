#include "Clinic.h"

bool Clinic::addDoctor(const Doctor& doc) {
	auto result = doctors_.insert({doc.getId(), doc});
	return result.second;
}

bool Clinic::addPatient(const Patient& pat) {
	auto result = patients_.insert({pat.getId(), pat});
	return result.second;
}

bool Clinic::bookAppointment(const Appointment& appt) {
	if (doctors_.find(appt.getDoctorId()) == doctors_.end()) {
		return false;
	}
	if (patients_.find(appt.getPatientId()) == patients_.end()) {
		return false;
	}

	TimeSlot slot{appt.getDoctorId(), appt.getDate(), appt.getTimeSlot()};
	if (occupied_.count(slot) > 0) {
		return false;
	}

	appointments_.insert({appt, true});
	occupied_.insert(slot);
	return true;
}

const Doctor* Clinic::getDoctor(int id) const {
	auto it = doctors_.find(id);
	if (it == doctors_.end()) {
		return nullptr;
	}
	return &(it->second);
}

const Patient* Clinic::getPatient(int id) const {
	auto it = patients_.find(id);
	if (it == patients_.end()) {
		return nullptr;
	}
	return &(it->second);
}

std::size_t Clinic::countAppointments() const {
	return appointments_.size();
}

void Clinic::printAllAppointments(std::ostream& os) const {
	for (const auto& entry : appointments_) {
		os << entry.first << "\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Clinic& c) {
	c.printAllAppointments(os);
	return os;
}