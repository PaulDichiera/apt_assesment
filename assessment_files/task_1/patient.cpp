#include <iostream>

#include "patient.h"

Patient::Patient(std::string name, std::string dob, Patient* next){
    this->next = next;

    this->name = name; // implement validation checks
    this->dob = dob;   // implement validation checks
    std::string regNum = "test007";
    this->regNum = regNum;

}

Patient::Patient(Patient& other){
    // copy constructor
}

Patient::~Patient(){
    // deconstructor
}

void Patient::setAdminHistory(std::string adDate, std::string disDate){
    // check date and ward, if already input update with discharge date.
    // call redNum then call the ward method to find and apply the ward from ward.
    std::string wardName = "test";
    // ward.getWard(this->regNum);
    this->adHistory.push_back(std::make_tuple(adDate, disDate, wardName));

}

void Patient::getAdminHistory(){
    // prints admin history listings.
    // cycle through users vector to print history.
}