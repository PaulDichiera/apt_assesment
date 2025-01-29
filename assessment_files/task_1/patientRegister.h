#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

class Patient;

#include "patient.h"
#include "ward.h"

class PatientRegister {
    public:
        PatientRegister(PatientRegister* nextWard = nullptr);
        ~PatientRegister();

        void addPatient(std::string name, std::string dob);
        void removePatient(std::string regNum);
        int getPatientNum();
        bool checkPatient(std::string regNum);
        bool returnPatient(std::string regNum);
        void checkDupe(std::string regNum);
        
        // PatientRegister operator[](const PatientRegister& other);

        std::string wardName;
        PatientRegister* nextWard;

    private:
        Patient* headPatient;

};


#endif // PATIENTREGISTER_H