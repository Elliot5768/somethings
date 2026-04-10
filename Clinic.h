#ifndef CLINIC_H
#define CLINIC_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "Functors.h"

class Clinic {
private:
	std::unordered_map<int, Doctor> doctors_;
	std::unordered_map<int, Patient> patients_;
	std::map<Appointment, bool, AppointmentCompare> appointments_;
	std::unordered_set<TimeSlot, TimeSlotHash, TimeSlotEqual> occupied_;

public:
	bool addDoctor(const Doctor& doc);
	bool addPatient(const Patient& pat);
	bool bookAppointment(const Appointment& appt);

	const Doctor* getDoctor(int id) const;
	const Patient* getPatient(int id) const;

	std::size_t countAppointments() const;
	void printAllAppointments(std::ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os, const Clinic& c);
};

#endif
