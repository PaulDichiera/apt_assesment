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
        void getPatientNum();
        bool checkPatient(std::string regNum);
        std::string returnPatient(std::string regNum);
        std::string checkDupe(std::string regNum);
        
        PatientRegister operator[](const PatientRegister& other);





    private:
        Patient* head;
        Patient* next;


};


#endif // PATIENTREGISTER_H