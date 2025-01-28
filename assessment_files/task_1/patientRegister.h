#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include <iostream>
#include "patient.h"

class PatientRegister {
    public:
        PatientRegister();
        ~PatientRegister();

        void addPatient(std::string name, std::string dob);
        void removePatient(std::string regNum);
        int getPatientNum();
        bool checkPatient(std::string regNum);
        void returnPatient(std::string regNum);
        void checkDupe(std::string regNum);
        
        PatientRegister operator[](const PatientRegister& other);

        std::string wardName;
        PatientRegister* next;

    private:
        Patient* head;


};


#endif // PATIENTREGISTER_H