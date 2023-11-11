#include "hospital.h"

Hospital::Hospital() { }

void Hospital::addDoctor(const Doctor& d) {
	doctors.push_back(d);
}

void Hospital::addPatient(const Patient& p) {
    patients.push_back(p);
}

void Hospital::addOldPatient(const Patient& p) {
    oldPatients.insert(p);
}

void Hospital::addStackConsultations(const stack<Consultation>& s) {
    consultations.push_back(s);
}

vector<Doctor> Hospital::getDoctors() const {
	return doctors;
}

list<Patient> Hospital::getPatients() const {
    return patients;
}

set<Patient> Hospital::getOldPatients() const {
    return oldPatients;
}

list<stack<Consultation>> Hospital::getConsultations() const {
    return consultations;
}

void Hospital::setConsultations(const list<stack<Consultation>>& consults) {
    consultations = consults;
}


// --------------------------------------------------------------------

//TODO
void Hospital::sortDoctors() {
    sort(doctors.begin(), doctors.end());
}


// TODO
float Hospital::averageNPatients(string sp) const {
    float p_count = 0.0;
    float d_count = 0.0;
    for (const Doctor& d : doctors) {
        if (d.getSpecialty() == sp) {
            p_count += d.getPatientsToAttend().size();
            d_count++;
        }
    }
    if (d_count == 0.0) {
        return 0.0;
    }
    return p_count / d_count;
}


// TODO
int Hospital::removePatients(int minC) {
    int res = 0;
    auto it = patients.begin();
    for (;it != patients.end(); it++) {
        if (it->getNumConsultations() < minC) {
            it = patients.erase(it);
            it--;
            res++;
        }
    }
    return res;
}


// TODO
vector<Patient> Hospital::getOldPatients(int y) const {
    vector<Patient> res;
    for (Patient p : oldPatients) {
        if (p.getLastConsultationYear() < y) {
            res.push_back(p);
        }
    }
    return res;
}


// TODO
void Hospital::processConsultation(Consultation c) {
    bool found = false;
    auto it = consultations.begin();
    for (;it != consultations.end(); it++) {
        if (it->top().getSpecialty() == c.getSpecialty()) {
            it->push(c);
            found = true;
            break;
        }
    }
    if (!found) {
        stack<Consultation> new_specialty;
        new_specialty.push(c);
        consultations.push_back(new_specialty);
    }
}


// TODO
bool Hospital::addDoctor(int id2, string sp2, int id1) {
    Doctor new_doctor = Doctor(id2, sp2);
    doctors.push_back(new_doctor);
    auto it1 = doctors.end() - 1;
    auto it2 = find(doctors.begin(), doctors.end(), id1);
    if (it2 == doctors.end() || it2->getSpecialty() != sp2) {
        return false;
    }
    queue<Patient> even;
    queue<Patient> odd;
    queue<Patient> actual = it2->getPatientsToAttend();
    size_t range = actual.size();
    for (int i = 1; i <= range; i++) {
        if (i % 2 != 0) {
            odd.push(actual.front());
            actual.pop();
        }
        else {
            even.push(actual.front());
            actual.pop();
        }
    }
    it1->setPatientsToAttend(even);
    it2->setPatientsToAttend(odd);
    return true;
}
