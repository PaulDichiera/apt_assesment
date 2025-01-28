#include <iostream>

#include "ward.h"

Ward::Ward(){
    // creates 5 wards calling the patient registry 5 times assigning the Enum as a name in the Patient registry data
    // head pointer needs to be assigned
    this->head = nullptr;
    
    PatientRegister* ward1 = new PatientRegister();
    PatientRegister* ward2 = new PatientRegister();

}

Ward::~Ward(){
    // deconstructor

}

void Ward::addPatient(std::string name, std::string dob, WardName ward){
    // calls method in patient registry associated with the appropriate ward to pass patient info and create node for the patient.

}

int Ward::getPatientTotals(){
    // iterate through a ward to collect a total number of patients

}

int Ward::getWardSize(WardName ward){
    // call getPatientTotals and add the sum of all wards

}

WardName getWard(std::string regNum){
    // using a patients regNum find which ward they are on

}

Ward Ward::operator[](const Ward& other){
    // allow the retrival of patient data via use of the [] operator and the ward name or number

}