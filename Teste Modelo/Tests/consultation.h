#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <string>
using namespace std;

class Consultation {
    int idPatient;
    string specialty;
    string description;
public:
    Consultation(int id, string sp="", string d="");
    int getIDPatient() const;
    string getSpecialty() const;
    string getDescription() const;
};

#endif
