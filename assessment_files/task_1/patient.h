#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <vector>
#include <tuple>
#include "ward.h"
#include "patientRegister.h"

class Patient {
    public:
        Patient(std::string name, std::string dob, Patient* next = nullptr);
        Patient(Patient& other);
        ~Patient();

        void setAdminHistory(std::string adDate, std::string disDate = "N/A");
        void getAdminHistory();
    
        std::string name;
        std::string dob;
        std::string regNum;
        std::vector<std::tuple<std::string, std::string, std::string>> adHistory;

        Patient* next;
        
};

#endif // PATIENT_H