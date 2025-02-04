#ifndef WARD_H
#define WARD_H

#define WARD_SIZE   5

#include "PatientRegister.h"


enum WardName {
    BLUE,
    RED,
    GREEN,
    YELLOW,
    PURPLE
};

// class PatientRegister;

class Ward {
    public:
        Ward();
        ~Ward();

        void addPatient(std::string name, std::string dob, std::string regNum, std::string ward);
        void removePatient(std::string regNum);
        int getWardFullTotals();
        int getWardTotals(std::string ward);
        std::string getPatientWard(std::string regNum);

        Patient* operator[](std::string regNum);
    
    private:
    std::string getWardString(int wardIndex);
    PatientRegister* registerHead;
};



#endif //WARD_H