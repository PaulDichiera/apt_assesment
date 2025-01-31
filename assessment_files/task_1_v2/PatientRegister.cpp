#include <iostream>

#include "PatientRegister.h"

PatientRegister::PatientRegister(std::string wardName){
    this->patientHead = nullptr;
    this->wardName = wardName;

}

PatientRegister::~PatientRegister(){

}

bool PatientRegister::checkPatient(std::string regNum){
    bool check = false;
    if(patientHead == nullptr){
        std::cout << "** Notice, there are currently no patient on this ward **" << std::endl;
    }else{
        Patient* tempNode = patientHead;
        while(tempNode != nullptr){
            if(tempNode->regNum == regNum){
                check = true;
                std::cout << "** Notice, Patient: " << tempNode->name << " is currently admitted to this ward **" << std::endl;
            }
            tempNode = tempNode->nextPatient;
        }
    }
    return check;
}

Patient* PatientRegister::returnPatient(std::string regNum){
    if(checkPatient(regNum)){
        Patient* tempNode = patientHead;
        while(tempNode != nullptr){
            if(tempNode->regNum == regNum){
                return tempNode;
            }
            tempNode = tempNode->nextPatient;
        }
    }else{
        std::cout << "** Notice, Patient not admitted under this registration number ** " << std::endl;
    }
    return NULL; // find a solution to returning a null ptr if it gets printed we get a segmentation fault.
}

void PatientRegister::checkDupe(std::string regNum){
    if(checkPatient(regNum)){
        Patient* tempNode = patientHead;
        while(tempNode != nullptr){
            if(tempNode->regNum == regNum){
                std::cout << "** Notice, Dupllicate found: " << tempNode->name << " Registration: " << tempNode->regNum << std::endl;
            }
            tempNode = tempNode->nextPatient;
        }
    }
}