#ifndef WARD_H
#define WARD_H

#include <iostream>

class PatientRegister;

#include "patientRegister.h"
#include "patient.h"

enum WardName {
    BLUE,
    RED,
    GREEN,
    YELLOW,
    ORANGE
};

class Ward {
    public:
        Ward();
        ~Ward();

        void addPatient(std::string name, std::string dob, WardName ward);
        void removePatient(std::string regNum);
        int getPatientTotals();
        int getWardSize(WardName ward);
        void getWard(std::string regNum);

        void operator[](const std::string regNum);


    private:
        std::string enumToString(WardName ward);

        PatientRegister* head;

};

#endif // WARD_H