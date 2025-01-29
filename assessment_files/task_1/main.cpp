#include <iostream>

#include "ward.h"
#include "patientRegister.h"
#include "patient.h"

int main(void){

    Ward* ward = new Ward();

    ward->addPatient("Paul Dichiera", "02/06/1986", GREEN);
    ward->addPatient("Stephen Hawking", "11/10/1952", GREEN);

    ward->addPatient("Jessica Jones", "12/06/1980", BLUE);
    ward->addPatient("Julian Claire", "19/01/1998", BLUE);
    ward->addPatient("Jake Ryan", "09/08/1989", BLUE);

    ward->addPatient("Damien Dwyer", "17/05/1986", ORANGE);
    ward->addPatient("James O'Brian", "22/12/1978", ORANGE);



    std::cout << "Number of patients on ward: " << ward->getWardSize(GREEN) << std::endl;
    std::cout << "Number of patients on ward: " << ward->getWardSize(BLUE) << std::endl;
    std::cout << "Number of patients on ward: " << ward->getWardSize(ORANGE) << std::endl;

    std::cout << "Number of patients on all wards: " << ward->getPatientTotals() << std::endl;

    ward->removePatient("test007");

    std::cout << "Number of patients on all wards: " << ward->getPatientTotals() << std::endl;



    return EXIT_SUCCESS;
}