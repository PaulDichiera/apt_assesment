#ifndef WARD_H
#define WARD_H

#include <iostream>

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
        int getPatientTotals();
        int getWardSize(WardName ward);
        WardName getWard(std::string regNum);

        Ward operator[](const Ward& other);


    private:
        Ward* head;

};

#endif // WARD_H