#ifndef PATIENT_H
#define PATIENT_H

class Patient {
    int idPatient;
    int numConsultations;
    int lastConsultationYear;
public:
    Patient(int id, int n=0, int lcy=1900);
    int getID() const;
    int getNumConsultations() const;
    int getLastConsultationYear() const;
    bool operator==(const Patient& p2) const;
    bool operator<(const Patient &p2) const;
};

#endif
