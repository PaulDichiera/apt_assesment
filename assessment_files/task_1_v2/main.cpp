#include <iostream>

#include "LinkedList.h"
#include "PatientRegister.h"
#include "Ward.h"

int main(void) {

    LinkedList* ward = new LinkedList();
    std::cout << "ward object created" << std::endl;

    ward->addPatient("Paul Fichiera", "02/06/1984", "R00007", "blue");
    ward->addPatient("Paul Dichiera", "02/06/1986", "R00006", "blue");
    std::cout << ward->registerSize() << std::endl;
    ward->removePatient("R00006");
    std::cout << ward->registerSize() << std::endl;

    Ward* ward2 = new Ward();

    ward2->addPatient("Sally Jones", "01/01/1991", "R00009", "Red");
    std::cout << ward2->registerSize() << std::endl;

    // ward2->checkPatient("R00009");
    
    ward2->addPatient("Sally Jones", "01/01/1991", "R00009", "Red");
    ward2->addPatient("Sally Jones", "01/01/1991", "R00009", "Red");

    // ward2->checkDupe("R00009");





    return EXIT_SUCCESS;
}