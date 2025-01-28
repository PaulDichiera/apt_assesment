#include <iostream>

#include "ward.h"

Ward::Ward(){
    // creates 5 wards calling the patient registry 5 times assigning the Enum as a name in the Patient registry data
    // head pointer needs to be assigned
    this->head = nullptr;

    PatientRegister* BLUE = new PatientRegister();
    BLUE->wardName = "BLUE";
    PatientRegister* RED = new PatientRegister();
    RED->wardName = "RED";
    PatientRegister* GREEN = new PatientRegister();
    GREEN->wardName = "GREEN";
    PatientRegister* YELLOW = new PatientRegister();
    YELLOW->wardName = "YELLOW";
    PatientRegister* ORANGE = new PatientRegister();
    ORANGE->wardName = "ORANGE";

    // connect wards in linked list
    this->head = BLUE;
    BLUE->next = RED;
    RED->next = GREEN;
    GREEN->next = YELLOW;
    YELLOW->next = ORANGE;



}

Ward::~Ward(){
    // deconstructor

}

void Ward::addPatient(std::string name, std::string dob, WardName ward){
    // calls method in patient registry associated with the appropriate ward to pass patient info and create node for the patient.
    PatientRegister* temp = head;
    std::string wardString = enumToString(ward);

    while(temp->next != nullptr){
        if(temp->wardName == wardString){
            temp->addPatient(name, dob);
        }else{
            temp = temp->next;
        }
    }
    
}

int Ward::getPatientTotals(){
    // iterate through a ward to collect a total number of patients
    int totals = 0;
    PatientRegister* temp = head;

    while(temp->next != nullptr){
        totals += temp->getPatientNum();
        temp = temp->next;
    }

    return totals;
}

int Ward::getWardSize(WardName ward){
    // call getPatientTotals and add the sum of all wards
    int total = 0;
    PatientRegister* temp = head;
    std::string wardString = enumToString(ward);

    while(temp->next != nullptr){
        if(temp->wardName == wardString){
            total = temp->getPatientNum();
        }else{
            temp = temp->next;
        }
    }
    return 0;
}

WardName getWard(std::string regNum){
    // using a patients regNum find which ward they are on

}

Ward Ward::operator[](const Ward& other){
    // allow the retrival of patient data via use of the [] operator and the ward name or number

}

std::string enumToString(WardName ward){
    std::string result;

    switch(ward){
        case 0:
            result = "BLUE";
            break;
        case 1:
            result = "RED";
            break;
        case 2:
            result = "GREEN";
            break;
        case 3:
            result = "YELLOW";
            break;
        case 4:
            result = "ORANGE";
            break;
    }

    return result;
}