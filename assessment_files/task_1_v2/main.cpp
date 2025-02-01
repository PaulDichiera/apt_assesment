#include <iostream>

#include "LinkedList.h"
#include "PatientRegister.h"
#include "Ward.h"

int main(void) {

    Ward* ward2 = new Ward();

    std::cout << ward2->getWardFullTotals() << std::endl;

    ward2->addPatient("Paul Dichiera", "02/06/1986", "R0007", "Blue");
    ward2->addPatient("Paul Fichiera", "02/06/1986", "R0008", "Blue");

    std::cout << ward2->getWardFullTotals() << std::endl;

    ward2->removePatient("R0008");

    std::cout << ward2->getWardFullTotals() << std::endl;

    std::cout << ward2->getWardTotals("Blue") << std::endl;

    std::cout << ward2->getPatientWard("R0007") << std::endl;

    // ward2->addPatient("Sally Jones", "01/01/1991", "R00009", "Red");
    // std::cout << ward2->registerSize() << std::endl;

    // // ward2->checkPatient("R00009");
    
    // ward2->addPatient("Sally Jones", "01/01/1991", "R00009", "Red");
    // ward2->addPatient("Sally Jones", "01/01/1991", "R00009", "Red");

    // ward2->checkDupe("R00009");





    return EXIT_SUCCESS;
}