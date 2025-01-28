#include <iostream>

#include "patient.h"

Patient::Patient(std::string name, std::string dob, std::string regNum){
    // name format checks
    // dob format checks
    // regNum, check for copies, if name and dob are correct provide unique number

}

Patient::Patient(Patient& other){
    // copy constructor
}

Patient::~Patient(){
    // deconstructor
}

void setAdminHistory(){
    // check date and ward, if already input update with discharge date.
}

void getAdminHistory(){
    // prints admin history listings.
}