#include <iostream>

#include "Patient.h"

Patient::Patient(std::string name, std::string dob, std::string regNum, Patient* nextPatient){
    this->nextPatient = nextPatient;
    
    this->name = name;
    this->dob = dob;
    this->regNum = regNum;
    
}

Patient::~Patient(){

}