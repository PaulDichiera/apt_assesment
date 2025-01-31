#include <iostream>

#include "Ward.h"

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

int Ward::getFullWardTotals(){
    
}

std::string Ward::getWardString(int wardIndex){

    switch(wardIndex){
        case BLUE: return "Blue";
        case GREEN: return "Green";
        case PURPLE: return "Purple";
        case RED: return "Red";
        case YELLOW: return "Yellow";
        default: return "UNKOWN";
    }
}