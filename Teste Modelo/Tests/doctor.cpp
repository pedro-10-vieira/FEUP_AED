#include "doctor.h"

Doctor::Doctor(int id, string sp): idDoctor(id), specialty(sp)
{}

int Doctor::getID() const {
	return idDoctor;
}

string Doctor::getSpecialty() const {
	return specialty;
}

queue<Patient> Doctor::getPatientsToAttend() const {
	return toAttend;
}

void Doctor::setSpecialty(string sp) {
    specialty = sp;
};

void Doctor::setPatientsToAttend(queue<Patient> toAtt) {
    toAttend = toAtt;
}

void Doctor::addPatientToAttend(const Patient& p1) {
	toAttend.push(p1);
}

bool Doctor::operator==(int id) const {
    return this->idDoctor == id;
}

bool Doctor::operator<(Doctor& doctor) {
    if (this->toAttend.size() == doctor.toAttend.size()) {
        return this->idDoctor < doctor.idDoctor;
    }
    return this->toAttend.size() > doctor.toAttend.size();
}
//--------------------------------------------------------------------------

//TODO
void Doctor::moveToFront(int idP) {
    queue<Patient> temp;
    temp.emplace(idP);
    while (!(toAttend.empty())) {
        if (toAttend.front().getID() == idP) {
            toAttend.pop();
        }
        else {
            temp.emplace(toAttend.front());
            toAttend.pop();
        }
    }
    toAttend.swap(temp);
}
