#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include <iostream>
#include "LinkedList.h"
#include "Patient.h"

class PatientRegister : public LinkedList {
    public:
        PatientRegister(std::string wardName);
        ~PatientRegister();

        bool checkPatient(std::string regNum);
        Patient* returnPatient(std::string regNum);
        void checkDupe(std::string regNum);

        PatientRegister* nextRegister;
        std::string wardName;

        // Patient* operator[](const std::string regNum);

    private:
    
};

#endif // PATIENTREGISTER_H