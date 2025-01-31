#ifndef WARD_H
#define WARD_H

#include "PatientRegister.h"
#include "LinkedList.h"

#define WARD_SIZE   5

enum WardName {
    BLUE,
    RED,
    GREEN,
    YELLOW,
    PURPLE
};

class Ward : public LinkedList{
    public:
        Ward();
        ~Ward();

        int getWardFullTotals();
        // int getWardTotals(std::string ward);
        // void getPatientWard(std::string regNum);
    
    private:
    std::string getWardString(int wardIndex);
    PatientRegister* registerHead;
};



#endif //WARD_H