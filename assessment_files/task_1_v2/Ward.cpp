#include <iostream>

#include "Ward.h"
// #include "PatientRegister.h"

Ward::Ward(){
    registerHead = nullptr;
    PatientRegister* prevNode = nullptr;

    for(int i = 0; i < WARD_SIZE; i++){
        std::string wardName = getWardString(i);
        PatientRegister* newNode = new PatientRegister(wardName);
        if(registerHead == nullptr){
            registerHead = newNode;
        }else{
            prevNode->nextRegister = newNode;
        }
        prevNode = newNode;
    }
}

Ward::~Ward(){
    
}

int Ward::getWardFullTotals(){
    int count = 0;
    PatientRegister* tempNode = registerHead;
    while(tempNode != nullptr){
        count += tempNode->registerSize();
        tempNode = tempNode->nextRegister;
    }
    return count;
}

void Ward::addPatient(std::string name, std::string dob, std::string regNum, std::string ward){
    PatientRegister* tempNode = registerHead;
    while(tempNode != nullptr){
        if(tempNode->wardName == ward){
            tempNode->addPatient(name, dob, regNum);
        }
        tempNode = tempNode->nextRegister;
    }
}

void Ward::removePatient(std::string regNum){
    bool incomplete = true;
    PatientRegister* tempNode = registerHead;
    while(tempNode != nullptr && incomplete){
        if(tempNode->checkPatient(regNum)){
            tempNode->removePatient(regNum);
            incomplete = false;
        }
        tempNode = tempNode->nextRegister;
    }
}

int Ward::getWardTotals(std::string ward){
    int count = 0;
    bool incomplete = true;
    PatientRegister* tempNode = registerHead;
    while(tempNode != nullptr && incomplete){
        std::cout << tempNode->wardName << " " << ward << std::endl;
        if(tempNode->wardName == ward){
            count = tempNode->registerSize();
            incomplete = false;
        }
        tempNode =  tempNode->nextRegister;
    }
    return count;
}

std::string Ward::getPatientWard(std::string regNum){
    std::string ward = "** Patient not found **";
    PatientRegister* tempNode = registerHead;
    while(tempNode != nullptr){
        if(tempNode->checkPatient(regNum)){
            ward = tempNode->wardName;
        }
        tempNode = tempNode->nextRegister;
    }
    return ward;
}

std::string Ward::getWardString(int wardIndex){

    switch(static_cast<WardName>(wardIndex)){
        case WardName::BLUE: return "Blue";
        case WardName::GREEN: return "Green";
        case WardName::PURPLE: return "Purple";
        case WardName::RED: return "Red";
        case WardName::YELLOW: return "Yellow";
        default: return "UNKOWN";
    }
}