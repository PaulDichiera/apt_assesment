#include <iostream>

#include "ward.h"

Ward::Ward(){
    // creates 5 wards calling the patient registry 5 times assigning the Enum as a name in the Patient registry data
    // head pointer needs to be assigned
    head = nullptr;

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
    head = BLUE;
    BLUE->nextWard = RED;
    RED->nextWard = GREEN;
    GREEN->nextWard = YELLOW;
    YELLOW->nextWard = ORANGE;
    ORANGE->nextWard = nullptr;



}

Ward::~Ward(){
    // deconstructor

}

void Ward::addPatient(std::string name, std::string dob, WardName ward){
    PatientRegister* temp = head;
    std::string wardString = enumToString(ward);

    while(temp != nullptr){
        if(temp->wardName == wardString){
            temp->addPatient(name, dob);
        }
        temp = temp->nextWard;
    }
    
}

void Ward::removePatient(std::string regNum){
    PatientRegister* temp = head;

    while(temp->nextWard != nullptr){
        if(temp->checkPatient(regNum)){
            temp->removePatient(regNum);
        }
        temp = temp->nextWard;
    }
}

int Ward::getPatientTotals(){
    // iterate through a ward to collect a total number of patients
    int totals = 0;
    PatientRegister* temp = head;

    while(temp != nullptr){
        totals += temp->getPatientNum();
        temp = temp->nextWard;
    }

    return totals;
}

int Ward::getWardSize(WardName ward){
    // call getPatientTotals and add the sum of all wards
    int total = 0;
    PatientRegister* temp = head;
    std::string wardString = enumToString(ward);
    while(temp != nullptr){
        if(temp->wardName == wardString){
            total = temp->getPatientNum();
        }
        temp = temp->nextWard;
    }
    return total;
}

void Ward::getWard(std::string regNum){
    PatientRegister* temp = head;
    if(head == nullptr){
        std::cout << "There are no patients admitted to this ward" << std::endl;
    }else{
        while(temp != nullptr){
            if(temp->returnPatient(regNum)){
                std::cout << "Patient can be found on ward: " << temp->wardName << std::endl;
            }else{
                temp = temp->nextWard;
            }
        }
    }
    

}

void Ward::operator[](const std::string regNum){
    // allow the retrival of patient data via use of the [] operator and the ward name or number
    getWard(regNum);
}

std::string Ward::enumToString(WardName ward){
    std::string result;

    switch(ward){
        case WardName::BLUE: return "BLUE";
        case WardName::RED: return "RED";
        case WardName::GREEN: return "GREEN";
        case WardName::YELLOW: return "YELLOW";
        case WardName::ORANGE: return "ORANGE";
    }
}