#include "consultation.h"

Consultation::Consultation(int id, string sp, string d): idPatient(id), specialty(sp), description(d)
{}

int Consultation::getIDPatient() const {
    return idPatient;
}

string Consultation::getSpecialty() const {
    return specialty;
}

string Consultation::getDescription() const {
    return description;
}
