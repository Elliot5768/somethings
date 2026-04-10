#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <iostream>

// ── Urgency: scoped enum for appointment priority ──
// Using enum class (not plain enum) so values are type-safe:
//   Urgency u = Urgency::Critical;   // OK
//   Urgency u = 5;                   // COMPILE ERROR — can't mix int and Urgency
//   int n = Urgency::Critical;       // COMPILE ERROR — need static_cast<int>(...)
enum class Urgency {
    Routine  = 1,
    Low      = 2,
    Medium   = 3,
    High     = 4,
    Critical = 5
};

// Helper: print urgency as a human-readable string
std::ostream& operator<<(std::ostream& os, Urgency u);

class Appointment {
private:
    int doctorId_;
    int patientId_;
    std::string date_;
    std::string timeSlot_;
    Urgency urgency_;

public:
    Appointment(int doctorId,
                int patientId,
                const std::string& date,
                const std::string& timeSlot,
                Urgency urgency);

    int getDoctorId() const;
    int getPatientId() const;
    std::string getDate() const;
    std::string getTimeSlot() const;
    Urgency getUrgency() const;

    bool operator==(const Appointment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Appointment& a);
};

#endif
