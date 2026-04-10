#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <string>
#include <functional>
#include "Appointment.h"

// ── TimeSlot: represents a specific doctor's slot on a date/time ──
struct TimeSlot {
    int         doctorId;
    std::string date;
    std::string time;
};

// ── TimeSlotHash: custom hash for unordered_set<TimeSlot> ──
// No default std::hash<TimeSlot> exists — you must write this.
struct TimeSlotHash {
    std::size_t operator()(const TimeSlot& ts) const {
        std::size_t h1 = std::hash<int>{}(ts.doctorId);
        std::size_t h2 = std::hash<std::string>{}(ts.date);
        std::size_t h3 = std::hash<std::string>{}(ts.time);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

// ── TimeSlotEqual: custom equality for unordered_set<TimeSlot> ──
// Required as the 4th template parameter so the set can confirm
// that two slots in the same bucket are truly identical.
struct TimeSlotEqual {
    bool operator()(const TimeSlot& a, const TimeSlot& b) const {
        return a.doctorId == b.doctorId && a.date == b.date && a.time == b.time;
    }
};

// ── AppointmentCompare: custom comparator for map<Appointment> ──
// Strict weak ordering:
//   1. Higher urgency first  (descending)
//   2. Earlier date first    (ascending)
//   3. Earlier time first    (ascending)
//   4. Tiebreak by doctorId, then patientId
struct AppointmentCompare {
    bool operator()(const Appointment& a, const Appointment& b) const {
        int ua = static_cast<int>(a.getUrgency());
        int ub = static_cast<int>(b.getUrgency());

        if (ua != ub) {
            return ua > ub;
        }
        if (a.getDate() != b.getDate()) {
            return a.getDate() < b.getDate();
        }
        if (a.getTimeSlot() != b.getTimeSlot()) {
            return a.getTimeSlot() < b.getTimeSlot();
        }
        if (a.getDoctorId() != b.getDoctorId()) {
            return a.getDoctorId() < b.getDoctorId();
        }
        return a.getPatientId() < b.getPatientId();
    }
};

#endif
