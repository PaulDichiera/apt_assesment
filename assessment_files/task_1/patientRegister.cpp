#include <iostream>

#include "patientRegister.h"

PatientRegister::PatientRegister(){
    // creates the linked list
    head = nullptr;
    next = nullptr;
}

PatientRegister::~PatientRegister(){
    // destructor

}

void PatientRegister::addPatient(std::string name, std::string dob){
    // adds a node to the linked list
    Patient* newPatient = new Patient(name, dob);
    Patient* temp = head;
    if(head == nullptr){
        head = newPatient;
        std::cout << "New Patient successfully added to ward " << std::endl;
    }else{
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newPatient;
        std::cout << "New Patient successfully added to ward " << std::endl;
    }
}

void PatientRegister::removePatient(std::string regNum){
    Patient* temp = head;
    if(head == nullptr){
        std::cout << "There are no patients admitted to this ward" << std::endl;
    }else{
        while(temp->next != nullptr){
            if(temp->regNum == regNum){
                temp->~Patient();
            }else{
                temp = temp->next;
            }
        }
    }
}

int PatientRegister::getPatientNum(){
    // returns the number of patients or the size of the linked list
    Patient* temp = head;
    int count = 0;
    if(head == nullptr){
        std::cout << "There are no patients admitted to this ward" << std::endl;
    }else{
        while(temp->next != nullptr){
            temp++;
            temp = temp->next;
        }
    }
    return count;
}

bool PatientRegister::checkPatient(std::string regNum){
    // checks if a patient is in the register 
    Patient* temp = head;
    bool check = false;
    if(head == nullptr){
        std::cout << "There are no patients admitted to this ward" << std::endl;
    }else{
        while(temp->next != nullptr){
            if(temp->regNum == regNum){
                check = true;
                std::cout << "Paitient is admitted to the ward" << std::endl;
            }else{
                temp = temp->next;
            }
        }
        if(!check){
            std::cout << "Patient is not admitted to the ward" << std::endl;
        }
    }
    return check;
}

void PatientRegister::returnPatient(std::string regNum){
    // returns the patients details 
    Patient* temp = head;
    if(head == nullptr){
        std::cout << "There are no patients admitted on this ward" << std::endl;
    }else{
        while(temp->next != nullptr){
            if(temp->regNum == regNum){
                std::cout << "Patient Name: " << temp->name << std::endl
                    << "Patients Date of Birth: " << temp->dob << std::endl
                    << "Patients Registration Number: " << temp->regNum << std::endl;
            }else{
                temp = temp->next;
            }
        }
    }
}

void PatientRegister::checkDupe(std::string regNum){
    // checks for duplicate regestration numbers
    Patient* temp = head;
    int count = 0;
    if(head == nullptr){
        std::cout << "There are no patients admitted to this ward" << std::endl;
    }else{
        while(temp->next != nullptr){
            if(temp->regNum == regNum){
                count++;
            }
            temp = temp->next;
        }
    }
    std::cout << "There are: " << count << " duplicate registration numbers on this ward" << std::endl;
}

PatientRegister PatientRegister::operator[](const PatientRegister& other){
    // supports the retrieval of a patients info via a regiastration number
    // i think instead of the object i need to pass the regNumber in or both this needs to be checked.

}

