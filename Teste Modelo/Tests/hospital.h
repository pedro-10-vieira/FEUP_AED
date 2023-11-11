#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include <list>
#include <stack>
#include <set>
#include <algorithm>
#include "doctor.h"
#include "patient.h"
#include "consultation.h"
using namespace std;

class Hospital {
    vector<Doctor> doctors;
    list<Patient> patients;
    set<Patient> oldPatients;
    list<stack<Consultation>> consultations;
public:
  Hospital();
  void addDoctor(const Doctor& d);
  void addPatient(const Patient& p);
  void addOldPatient(const Patient& p);
  void addStackConsultations (const stack<Consultation>& s);
  void setConsultations(const list<stack<Consultation>>& consults);
  vector<Doctor> getDoctors() const;
  list<Patient> getPatients() const;
  set<Patient> getOldPatients() const;
  list<stack<Consultation>> getConsultations() const;
  void sortDoctors();
  float averageNPatients(string sp) const;
  int removePatients(int minC);
  vector<Patient> getOldPatients(int y) const;
  void processConsultation(Consultation c);
  bool addDoctor(int id2, string sp2, int id1);
};

#endif
