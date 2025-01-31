#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Patient.h"

class LinkedList {
    public:
        LinkedList();
        virtual ~LinkedList();

        virtual void addPatient(std::string name, std::string dob, std::string regNum, std::string ward);
        virtual void removePatient(std::string regNum);
        virtual int registerSize();


    protected:
    // virtual std::string createReg();
        Patient* patientHead;

};

#endif // LINKEDLIST_H