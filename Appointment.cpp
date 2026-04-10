#include "Appointment.h"

// ── Urgency operator<< ──
std::ostream& operator<<(std::ostream& os, Urgency u) {
    switch (u) {
        case Urgency::Routine:  os << "Routine(1)";  break;
        case Urgency::Low:      os << "Low(2)";      break;
        case Urgency::Medium:   os << "Medium(3)";   break;
        case Urgency::High:     os << "High(4)";     break;
        case Urgency::Critical: os << "Critical(5)"; break;
    }
    return os;
}

Appointment::Appointment(int doctorId,
                         int patientId,
                         const std::string& date,
                         const std::string& timeSlot,
                         Urgency urgency)
    : doctorId_(doctorId),
      patientId_(patientId),
      date_(date),
      timeSlot_(timeSlot),
      urgency_(urgency) {}

int Appointment::getDoctorId() const {
    return doctorId_;
}

int Appointment::getPatientId() const {
    return patientId_;
}

std::string Appointment::getDate() const {
    return date_;
}

std::string Appointment::getTimeSlot() const {
    return timeSlot_;
}

Urgency Appointment::getUrgency() const {
    return urgency_;
}

bool Appointment::operator==(const Appointment& other) const {
    return doctorId_ == other.doctorId_ &&
           patientId_ == other.patientId_ &&
           date_ == other.date_ &&
           timeSlot_ == other.timeSlot_;
}

std::ostream& operator<<(std::ostream& os, const Appointment& a) {
    os << "[Appt] Doctor:" << a.doctorId_
       << " Patient:" << a.patientId_
       << " | " << a.date_ << " " << a.timeSlot_
       << " | " << a.urgency_;
    return os;
}

