#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>

class Patient {
    public:
        Patient(std::string name, std::string dob, std::string regNum, Patient* nextPatient = nullptr);
        ~Patient();

        Patient* nextPatient;

        std::string dob;
        std::string name;
        std::string regNum;

    private:

};

#endif // PATIENT_H