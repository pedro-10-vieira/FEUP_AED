#include <gtest/gtest.h>
#include "hospital.h"

using testing::Eq;

TEST(aed2223_ci1, alinea_a) {
    Hospital h;
    h.sortDoctors();
    vector<Doctor> d = h.getDoctors();

    // teste de vetor vazio
    EXPECT_EQ(0, d.size());
    d.clear();


    Doctor d1(4, "pediatria");
    d1.addPatientToAttend(Patient(14));
    d1.addPatientToAttend(Patient(24));
    Doctor d2(7, "pediatria");
    d2.addPatientToAttend(Patient(17));
    d2.addPatientToAttend(Patient(27));
    d2.addPatientToAttend(Patient(37));
    Doctor d3(1, "pediatria");
    d3.addPatientToAttend(Patient(11));
    Doctor d4(2, "pediatria");
    d4.addPatientToAttend(Patient(22));
    d4.addPatientToAttend(Patient(32));
    d4.addPatientToAttend(Patient(12));
    d4.addPatientToAttend(Patient(42));
    h.addDoctor(d1);
    h.addDoctor(d2);
    h.addDoctor(d3);
    h.addDoctor(d4);

    // teste 1.criterio ordenacao (ocupacao decrescente)
    h.sortDoctors();
    d = h.getDoctors();
    EXPECT_EQ(4, d.size());
    if (d.size() == 4)
        for (int i=0;i<d.size()-1;i++)
            EXPECT_GE(d[i].getPatientsToAttend().size(), d[i + 1].getPatientsToAttend().size());


    Hospital h2;
    Doctor d12(4, "pediatria");
    d12.addPatientToAttend(Patient(14));
    d12.addPatientToAttend(Patient(24));
    Doctor d22(7, "pediatria");
    d22.addPatientToAttend(Patient(17));
    d22.addPatientToAttend(Patient(27));
    d22.addPatientToAttend(Patient(37));
    Doctor d32(1, "pediatria");
    d32.addPatientToAttend(Patient(11));
    d32.addPatientToAttend(Patient(31));
    d32.addPatientToAttend(Patient(21));
    Doctor d42(2, "pediatria");
    d42.addPatientToAttend(Patient(22));
    d42.addPatientToAttend(Patient(32));
    d42.addPatientToAttend(Patient(12));
    d42.addPatientToAttend(Patient(42));
    Doctor d52(4,"pediatria");
    h2.addDoctor(d12);
    h2.addDoctor(d22);
    h2.addDoctor(d32);
    h2.addDoctor(d42);
    h2.addDoctor(d52);


    // teste dois criterios de ordenacao (ocupacao decrescente + id crescente)
    h2.sortDoctors();
    d = h2.getDoctors();
    EXPECT_EQ(5, d.size());
    if (d.size() == 5)
        for (int i=0;i<d.size()-1;i++) {
            EXPECT_GE(d[i].getPatientsToAttend().size(), d[i + 1].getPatientsToAttend().size());
            if (d[i].getPatientsToAttend().size() == d[i + 1].getPatientsToAttend().size())
                EXPECT_LT(d[i].getID(),d[i+1].getID());
        }

}


TEST(aed2223_ci1, alinea_b) {
    Hospital h;
    Doctor d0(4, "pediatria");
    d0.addPatientToAttend(Patient(14));

    // teste especialidade nao existente
    EXPECT_NEAR(0, h.averageNPatients("dermatologia"),0.01);

    Hospital h2;
    Doctor d1(4, "pediatria");
    d1.addPatientToAttend(Patient(14));
    d1.addPatientToAttend(Patient(24));
    Doctor d2(7, "oftalmologia");
    d2.addPatientToAttend(Patient(17));
    d2.addPatientToAttend(Patient(27));
    d2.addPatientToAttend(Patient(37));
    Doctor d3(1, "dermatologia");
    d3.addPatientToAttend(Patient(11));
    Doctor d4(2, "pediatria");
    d4.addPatientToAttend(Patient(22));
    d4.addPatientToAttend(Patient(32));
    Doctor d5(8,"pediatria");
    d5.addPatientToAttend(Patient(38));
    d5.addPatientToAttend(Patient(48));
    Doctor d6(9, "reumatologia");
    Doctor d7(3, "dermatologia");
    d7.addPatientToAttend(Patient(33));
    h2.addDoctor(d1);
    h2.addDoctor(d2);
    h2.addDoctor(d3);
    h2.addDoctor(d4);
    h2.addDoctor(d5);
    h2.addDoctor(d6);
    h2.addDoctor(d7);

    // teste 1 medico
    EXPECT_NEAR(3, h2.averageNPatients("oftalmologia"),0.01);


   // teste varios medicos
    EXPECT_NEAR(2, h2.averageNPatients("pediatria"),0.01);


    // teste varios medicos
    EXPECT_NEAR(1,h2.averageNPatients("dermatologia"),0.01);


    // teste especialidade sem pacientes
    EXPECT_NEAR(0,h2.averageNPatients("reumatologia"),0.01);


}


TEST(aed2223_ci1, alinea_c) {
    Hospital h;
    h.addPatient(Patient(2,4));
    int res = h.removePatients(5);
    list<Patient> patients = h.getPatients();

    // teste remocao unico paciente: teste numero removidos
    EXPECT_EQ(1, res);

    // teste remocao unico paciente: teste patientes que permanecem
    EXPECT_EQ(0, patients.size());


    Hospital h2;
    h2.addPatient(Patient(1,6));
    h2.addPatient(Patient(2,2));
    h2.addPatient(Patient(3,5));
    h2.addPatient(Patient(4,1));
    h2.addPatient(Patient(5,7));
    res = h2.removePatients(4);
    patients = h2.getPatients();

    // teste remocao pacientes nao consecutivos: teste numero removidos
    EXPECT_EQ(2, res);

    // teste remocao pacientes nao consecutivos: teste pacientes que permanecem
    EXPECT_EQ(3, patients.size());
    if (patients.size()==3) {
        EXPECT_EQ(1, patients.front().getID());
        patients.pop_front();
        EXPECT_EQ(3, patients.front().getID());
        patients.pop_front();
        EXPECT_EQ(5, patients.front().getID());
    }


    Hospital h3;
    h3.addPatient(Patient(1,6));
    h3.addPatient(Patient(2,2));
    h3.addPatient(Patient(3,4));
    h3.addPatient(Patient(4,7));
    h3.addPatient(Patient(5,8));
    h3.addPatient(Patient(6,1));
    h3.addPatient(Patient(7,7));
    res = h3.removePatients(5);
    patients = h3.getPatients();

    // teste remocao pacientes consecutivos: teste numero de removidos
    EXPECT_EQ(3, res);

    // teste remocao pacientes consecutivos: teste pacientes que permanecem
    EXPECT_EQ(4, patients.size());
    if (patients.size()==4) {
        EXPECT_EQ(1, patients.front().getID());
        patients.pop_front();
        EXPECT_EQ(4, patients.front().getID());
        patients.pop_front();
        EXPECT_EQ(5, patients.front().getID());
        patients.pop_front();
        EXPECT_EQ(7, patients.front().getID());
    }


    Hospital h4;
    h4.addPatient(Patient(1,6));
    h4.addPatient(Patient(2,7));
    res = h4.removePatients(4);
    patients = h4.getPatients();

    //teste nao remocao: teste numero de removidos
    EXPECT_EQ(0, res);

    //teste nao remocao: teste pacientes que permanecem
    EXPECT_EQ(2, patients.size());
    if (patients.size()==2) {
        EXPECT_EQ(1, patients.front().getID());
        patients.pop_front();
        EXPECT_EQ(2, patients.front().getID());
    }


}


TEST(aed2223_ci1, alinea_d) {
    Doctor d1(1,"pediatria");
    d1.addPatientToAttend(Patient(7));
    d1.addPatientToAttend(Patient(5));
    d1.addPatientToAttend(Patient(3));
    d1.addPatientToAttend(Patient(8));

    d1.moveToFront(5);
    queue<Patient> q = d1.getPatientsToAttend();

    //teste mover paciente do meio: teste numero pacientes
    EXPECT_EQ(4,q.size());


    //teste mover paciente do meio: teste frente fila
    if (!q.empty())
        EXPECT_EQ(5, q.front().getID());


    //teste mover paciente do meio: teste ordem restantes
    if (q.size()==4) {
        q.pop();
        EXPECT_EQ(7, q.front().getID());
        q.pop();
        EXPECT_EQ(3, q.front().getID());
        q.pop();
        EXPECT_EQ(8, q.front().getID());
    }


    Doctor d2(2,"pediatria");
    d2.addPatientToAttend(Patient(7));
    d2.addPatientToAttend(Patient(5));
    d2.addPatientToAttend(Patient(3));
    d2.addPatientToAttend(Patient(4));
    d2.addPatientToAttend(Patient(8));

    d2.moveToFront(8);
    q = d2.getPatientsToAttend();

    //teste mover ultimo paciente: teste numero pacientes
    EXPECT_EQ(5,q.size());


    //teste mover ultimo paciente: teste frente fila
    if (!q.empty())
        EXPECT_EQ(8, q.front().getID());


    //teste mover ultimo paciente: teste ordem restantes
    if (q.size()==5) {
        q.pop();
        EXPECT_EQ(7, q.front().getID());
        q.pop();
        EXPECT_EQ(5, q.front().getID());
        q.pop();
        EXPECT_EQ(3, q.front().getID());
        q.pop();
        EXPECT_EQ(4, q.front().getID());
    }


}


TEST(aed2223_ci1, alinea_e) {
    Hospital h;
    h.addOldPatient(Patient(4,2,2021));
    h.addOldPatient(Patient(9,2,2018));
    h.addOldPatient(Patient(7,2,2019));
    set<Patient> s = h.getOldPatients();

    // teste construcao set: 1 criterio
    EXPECT_EQ(3, s.size());
    if (s.size() == 3) {
        Patient p = *s.begin();
        EXPECT_EQ(2018, p.getLastConsultationYear());
        p = *s.rbegin();
        EXPECT_EQ(2021, p.getLastConsultationYear());
    }

    Hospital h2;
    h2.addOldPatient(Patient(4,2,2021));
    h2.addOldPatient(Patient(9,2,2019));
    h2.addOldPatient(Patient(7,2,2019));
    s = h2.getOldPatients();

    // teste construcao set: 2 criterios
    EXPECT_EQ(3, s.size());
    if (s.size() == 3) {
        Patient p = *s.begin();
        EXPECT_EQ(2019, p.getLastConsultationYear());
        EXPECT_EQ(7, p.getID());
        p = *s.rbegin();
        EXPECT_EQ(2021, p.getLastConsultationYear());
    }


    vector<Patient> res = h.getOldPatients(2010);

    // teste resultado vector vazio
    EXPECT_EQ(0, res.size());

    // teste resultado vector vazio: test se set mantem
    EXPECT_EQ(3,h.getOldPatients().size());


    Hospital h3;
    h3.addOldPatient(Patient(4,2,2021));
    h3.addOldPatient(Patient(9,2,2018));
    h3.addOldPatient(Patient(7,2,2019));
    h3.addOldPatient(Patient(11,2,2017));
    res = h3.getOldPatients(2020);

    // teste resultado com 1 criterio (ultimo ano consulta diferentes)
    if (res.size() == 3) {
        EXPECT_EQ(2017, res[0].getLastConsultationYear());
        EXPECT_EQ(11, res[0].getID());
        EXPECT_EQ(2018, res[1].getLastConsultationYear());
        EXPECT_EQ(9, res[1].getID());
        EXPECT_EQ(2019, res[2].getLastConsultationYear());
        EXPECT_EQ(7, res[2].getID());
    }

    // teste resultado com 1 criterio (ultimo ano consulta diferentes): teste se set mantem
    EXPECT_EQ(4,h3.getOldPatients().size());


    Hospital h4;
    h4.addOldPatient(Patient(4,2,2022));
    h4.addOldPatient(Patient(9,2,2018));
    h4.addOldPatient(Patient(7,2,2019));
    h4.addOldPatient(Patient(5,2,2018));
    h4.addOldPatient(Patient(3,2,2018));
    h4.addOldPatient(Patient(5,2,2021));
    res = h4.getOldPatients(2020);

    // teste resultado com 2 criterios (ultimo ano consulta iguais)
    if (res.size() == 4) {
        EXPECT_EQ(2018, res[0].getLastConsultationYear());
        EXPECT_EQ(3, res[0].getID());
        EXPECT_EQ(2018, res[1].getLastConsultationYear());
        EXPECT_EQ(5, res[1].getID());
        EXPECT_EQ(2018, res[2].getLastConsultationYear());
        EXPECT_EQ(9, res[2].getID());
        EXPECT_EQ(2019, res[3].getLastConsultationYear());
        EXPECT_EQ(7, res[3].getID());
    }

    // teste resultado com 2 criterios (ultimo ano consulta iguais): teste se set mantem
    EXPECT_EQ(6,h4.getOldPatients().size());


}


TEST(aed2223_ci1, alinea_f) {
    Hospital h;
    h.processConsultation(Consultation(14,"reumatologia","description_1"));

    // teste adicao de consulta a lista vazia
    list<stack<Consultation>> consults = h.getConsultations();
    EXPECT_EQ(1,consults.size());
    if (1==consults.size()) {
        EXPECT_EQ(1,consults.front().size());
        if (1==consults.front().size())
            EXPECT_EQ(14,consults.front().top().getIDPatient());
    }


    Hospital h2;
    stack<Consultation> s1;
    s1.push(Consultation(3,"pediatria","description_3"));
    s1.push(Consultation(7,"pediatria","description_7"));
    s1.push(Consultation(5,"pediatria","description_5"));
    stack<Consultation> s2;
    s2.push(Consultation(21,"oftalmologia","description_21"));
    stack<Consultation> s3;
    s3.push(Consultation(18,"dermatologia","description_18"));
    h2.addStackConsultations(s1);
    h2.addStackConsultations(s2);
    h2.addStackConsultations(s3);
    h2.processConsultation(Consultation(16,"oftalmologia","description_16"));

    // teste adicao a pilha ja existente
    consults = h2.getConsultations();
    EXPECT_EQ(3,consults.size());
    if (3==consults.size()) {
        EXPECT_EQ(3,consults.front().size());
        if (!consults.front().empty())
            EXPECT_EQ("pediatria",consults.front().top().getSpecialty());
        consults.pop_front();
        EXPECT_EQ(2,consults.front().size());
        if (!consults.front().empty()) {
            EXPECT_EQ("oftalmologia", consults.front().top().getSpecialty());
            EXPECT_EQ(16, consults.front().top().getIDPatient());
        }
        consults.pop_front();
        EXPECT_EQ(1,consults.front().size());
        if (!consults.front().empty()) {
            EXPECT_EQ("dermatologia", consults.front().top().getSpecialty());
        }
    }


    Hospital h3;
    stack<Consultation> s13;
    s13.push(Consultation(3,"pediatria","description_3"));
    s13.push(Consultation(7,"pediatria","description_7"));
    s13.push(Consultation(5,"pediatria","description_5"));
    stack<Consultation> s23;
    s23.push(Consultation(21,"oftalmologia","description_21"));
    s23.push(Consultation(33,"oftalmologia","description_33"));
    stack<Consultation> s33;
    s33.push(Consultation(11,"reumatologia","description_11"));
    h3.addStackConsultations(s13);
    h3.addStackConsultations(s23);
    h3.addStackConsultations(s33);
    h3.processConsultation(Consultation(16,"dermatologia","description_16"));

    // teste adicao a nova pilha
    consults = h3.getConsultations();
    EXPECT_EQ(4,consults.size());
    if (4==consults.size()) {
        EXPECT_EQ(3,consults.front().size());
        if (!consults.front().empty())
            EXPECT_EQ("pediatria",consults.front().top().getSpecialty());
        consults.pop_front();
        EXPECT_EQ(2,consults.front().size());
        if (!consults.front().empty())
            EXPECT_EQ("oftalmologia", consults.front().top().getSpecialty());
        consults.pop_front();
        EXPECT_EQ(1,consults.front().size());
        if (!consults.front().empty())
            EXPECT_EQ("reumatologia", consults.front().top().getSpecialty());
        consults.pop_front();
        EXPECT_EQ(1,consults.front().size());
        if (!consults.front().empty()) {
            EXPECT_EQ("dermatologia", consults.front().top().getSpecialty());
            EXPECT_EQ(16, consults.front().top().getIDPatient());
        }
    }


}


TEST(aed2223_ci1, alinea_g) {
    Hospital h;
    Doctor d1(4, "pediatria");
    d1.addPatientToAttend(Patient(14));
    Doctor d2(7, "pediatria");
    d2.addPatientToAttend(Patient(17));
    h.addDoctor(d1);
    h.addDoctor(d2);
    bool res = h.addDoctor(11,"pediatria",8);

    //teste adicao medico quando nao existe medico de id dado: teste resultado
    vector<Doctor> ds = h.getDoctors();
    EXPECT_EQ(false, res);


    //teste adicao medico quando nao existe medico de id dado: teste adicao medico
    EXPECT_EQ(3, ds.size());
    vector<Doctor>::iterator it= find_if(ds.begin(), ds.end(),[](Doctor const &o) {
        return (o.getID()==11); });
    EXPECT_EQ(false, it==ds.end());
    if (it!=ds.end())
        EXPECT_EQ(0,it->getPatientsToAttend().size());


    Hospital h2;
    Doctor d12(4, "pediatria");
    d12.addPatientToAttend(Patient(14));
    Doctor d22(7, "oftalmologia");
    d22.addPatientToAttend(Patient(17));
    Doctor d32(5, "oftalmologia");
    h2.addDoctor(d12);
    h2.addDoctor(d22);
    h2.addDoctor(d32);
    res = h2.addDoctor(10,"pediatria",7);

    //teste adicao medico quando medico de id dado nao ee da especialidade: teste resultado
    ds = h2.getDoctors();
    EXPECT_EQ(false, res);


    //teste adicao medico quando medico de id dado nao ee da especialidade: teste adicao medico
    EXPECT_EQ(4, ds.size());
    it= find_if(ds.begin(), ds.end(),[](Doctor const &o) {
        return (o.getID()==10); });
    EXPECT_EQ(false, it==ds.end());
    if (it!=ds.end())
        EXPECT_EQ(0,it->getPatientsToAttend().size());


    Hospital h3;
    Doctor d13(4, "oftalmologia");
    d13.addPatientToAttend(Patient(14));
    d13.addPatientToAttend(Patient(24));
    Doctor d23(7, "pediatria");
    d23.addPatientToAttend(Patient(17));
    d23.addPatientToAttend(Patient(27));
    d23.addPatientToAttend(Patient(37));
    d23.addPatientToAttend(Patient(47));
    d23.addPatientToAttend(Patient(57));
    h3.addDoctor(d13);
    h3.addDoctor(d23);
    res = h3.addDoctor(20,"pediatria",7);

    //teste adicao medico quando redestribui doentes: teste resultado
    ds = h3.getDoctors();
    EXPECT_EQ(true, res);


    //teste adicao medico quando redestribui doentes: teste adicao medico e doentes medico novo
    EXPECT_EQ(3, ds.size());
    it= find_if(ds.begin(), ds.end(),[](Doctor const &o) {
        return (o.getID()==20); });
    EXPECT_EQ(false, it==ds.end());
    if (it!=ds.end()) {
        queue<Patient> q = it->getPatientsToAttend();
        EXPECT_EQ(2, q.size());
        if (2==q.size()) {
            EXPECT_EQ(27,q.front().getID());
            q.pop();
            EXPECT_EQ(47,q.front().getID());
        }
    }


    //teste adicao medico quando redestribui doentes: teste doentes medico antigo
    it= find_if(ds.begin(), ds.end(),[](Doctor const &o) {
        return (o.getID()==7); });
    EXPECT_EQ(false, it==ds.end());
    if (it!=ds.end()) {
        queue<Patient> q = it->getPatientsToAttend();
        EXPECT_EQ(3, q.size());
        if (3==q.size()) {
            EXPECT_EQ(17,q.front().getID());
            q.pop();
            EXPECT_EQ(37,q.front().getID());
            q.pop();
            EXPECT_EQ(57,q.front().getID());
        }
    }



}


