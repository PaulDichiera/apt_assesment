#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <vector>

class Patient {
    public:
        Patient(std::string name, std::string dob, std::string RegNum);
        Patient(Patient& other);
        ~Patient();

        void setAdminHistory();
        void getAdminHistory();



    private:
        std::string name;
        std::string dob;
        std::string RegNum;
        std::vector<std::string> AdHistory;
        Patient* next;
        

};

#endif // PATIENT_H