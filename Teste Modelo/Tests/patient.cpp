#include "patient.h"

Patient::Patient(int id, int n, int lcy): idPatient(id), numConsultations(n), lastConsultationYear(lcy)
{}

int Patient::getID() const {
    return idPatient;
}

int Patient::getNumConsultations() const {
    return numConsultations;
}

int Patient::getLastConsultationYear() const {
    return lastConsultationYear;
}

bool Patient::operator==(const Patient &p2) const {
    return this->lastConsultationYear == p2.lastConsultationYear;
}

// --------------------------------------------------------------------

//TODO
bool Patient::operator<(const Patient &p2) const {
    if (*this == p2) {
        return this->idPatient < p2.idPatient;
    }
    return this->lastConsultationYear < p2.lastConsultationYear;
}