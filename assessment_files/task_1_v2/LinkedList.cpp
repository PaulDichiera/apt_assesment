#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList(){
    patientHead = nullptr;
}

LinkedList::~LinkedList(){

}

void LinkedList::addPatient(std::string name, std::string dob, std::string regNum){
    Patient* newNode = new Patient(name, dob, regNum);
    if(patientHead == nullptr){
        patientHead = newNode;
        std::cout << "** Patient: " << newNode->name << " has been added to the register **" << std::endl;
    }else{
        Patient* tempNode = patientHead;
        while(tempNode->nextPatient != nullptr){
            tempNode = tempNode->nextPatient;
        }
        tempNode->nextPatient = newNode;
        std::cout << "** Patient: " << newNode->name << " has been added to the register **" << std::endl;
    }
}

void LinkedList::removePatient(std::string regNum){
    if(patientHead == nullptr){
        std::cout << "** Notice, there are currently no patient on this ward **" << std::endl;
    }else if(patientHead->regNum == regNum){
        Patient* remove = patientHead;
        patientHead = patientHead->nextPatient;
        std::cout << "** Patient: " << remove->name << " has been removed from registry **" << std::endl;
        delete remove;

    }else{
        Patient* tempNode = patientHead;
        Patient* prevNode = nullptr;
        while(tempNode != nullptr){
            if(tempNode->regNum == regNum){
                if(tempNode->nextPatient == nullptr){
                    Patient* remove = tempNode;
                    prevNode->nextPatient = tempNode->nextPatient;
                    std::cout << "** Patient: " << remove->name << " has been removed from registry **" << std::endl;
                    delete remove;
                }else{
                    Patient* remove = tempNode->nextPatient;
                    
                    tempNode->nextPatient = remove->nextPatient;
                    std::cout << "** Patient: " << remove->name << " has been removed from registry **" << std::endl;
                    delete remove;
                }
            }
            prevNode = tempNode; // trails behind tempNode so we can safely detach tempNode and attach tempNode->nextPatient
            tempNode = tempNode->nextPatient;
        }
    }
}

int LinkedList::registerSize(){
    int count = 0;
    if(patientHead == nullptr){
        std::cout << "** Notice, there are currently no patient on this ward **" << std::endl;
    }else{
        Patient* tempHead = patientHead;
        while(tempHead != nullptr){
            count++;
            tempHead = tempHead->nextPatient;
        }
    }
    return count;
}

// std::string LinkedList::createReg(){
//     std::string regNum;
//     if(patientHead == nullptr){
//         // create default regestration number
//         regNum = "R0000001";
//     }else{

//     }
//     return 
// }