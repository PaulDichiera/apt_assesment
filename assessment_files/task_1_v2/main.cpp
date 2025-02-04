#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "LinkedList.h"
#include "PatientRegister.h"
#include "Ward.h"

void readPatientFile(std::fstream& file, Ward* ward);
void addPatient(Ward* ward);
void removePatient(Ward* ward);
void getAdmittedTotals(Ward* ward);
void getWardTotals(Ward* ward);
void getAdmittedWard(Ward* ward);
void printInputBuffer();
std::string wardCheck(int wardNum);

int main(int argc, char **argv) {

    std::cout << "Number of arguments: " << argc << std::endl;

    std::string filename = argv[1];
    std::cout << filename << std::endl;
    std::fstream file(filename);

    Ward* ward = new Ward();
    readPatientFile(file, ward);
    bool running = true;

    while(running){
        std::string select;

        std::cout << "** Please Select a Menu Function **" << std::endl;
        std::cout << "   Add Patient to ward           - 1" << std::endl;
        std::cout << "   Remove Patient from ward      - 2" << std::endl;
        std::cout << "   Get total pations admitted    - 3" << std::endl;
        std::cout << "   Find total patrints on a ward - 4" << std::endl;
        std::cout << "   Find the ward a patient is in - 5" << std::endl;

        std::getline(std::cin, select);

        if(select == "1"){
            addPatient(ward);
        }else if (select == "2"){
            removePatient(ward);
        }else if (select == "3"){
            getAdmittedTotals(ward);
        }else if (select == "4"){
            getWardTotals(ward);
        }else if (select == "5"){
            getAdmittedWard(ward);
        }
    }


    return EXIT_SUCCESS;
}

void readPatientFile(std::fstream& file, Ward* ward){
        std::string line;

    if(file.is_open()){
        std::cout << "Patient File Loading..." << std::endl;
        while(std::getline(file, line)){
            std::cout << "reading file" << std::endl;
            std::stringstream ss(line);
            std::string name, dob, regNum, wardName;

            std::getline(ss, name, '-');
            std::getline(ss, dob, '-');
            std::getline(ss, regNum, '-');
            std::getline(ss, wardName, '-');
            std::cout << name << std::endl;
            ward->addPatient(name, dob, regNum, wardName);

        }
    }
}

void addPatient(Ward* ward){
    std::string name, dob, regNum, wardNum;
    bool valid = false; 
    bool quit = false;


    while(!quit){

            while(!valid && !quit){
            std::cout << "To admit a patient please first enter their first and last name" << std::endl;
            std::cout << "Example: John Smith" << std::endl;

            std::getline(std::cin, name);

            if(name == "quit" || name == "Quit"){
                quit = true;
                std::cout << "** Exiting to main menu **" << std::endl;
            }
            if(!quit){
                std::cout << "enter name validation" << std::endl;
                for(char c : name ){
                    if(!std::isalpha(c) && c != ' '){
                        std::cout << "** Only characters may be input **" << std::endl;
                    } else {
                        std::istringstream input(name);
                        std::string word;
                        std::string result;

                        while(input >> word){
                            word[0] = std::toupper(word[0]);
                            for(int i = 0; i < word.length(); ++i){
                                word[i] = std::tolower(word[i]);
                            }
                            result += word + " ";
                        }
                        name = result;
                        valid = true;
                    }
                }  
            } 
        }
        valid = false;
        while(!valid && !quit){
            std::cout << " ** Input Patients date of birth using standard day/month/year format **" << std::endl;
            std::cout << " ** Example: 02/06/1882 **" << std::endl;

            std::getline(std::cin, dob);

            if(dob == "quit" || dob == "Quit"){
                quit = true;
                std::cout << "** Exiting to main menu **" << std::endl;
            }

            if(!quit){
                if(dob.length() != 10){
                    std::cout << "** date of birth input too short, check format **" << std::endl; 
                }
                    for(int i = 0; i < dob.length(); i++){
                        if(i == 2 || i == 5){
                            if(dob[i] != '/'){
                                std::cout << " ** date of birth format requires day/month/year format **" << std::endl;
                            }
                        }else{
                            if(!std::isdigit(dob[i])){
                                std::cout << "** Only input numbers and forward slash seperators **" << std::endl;
                            }
                        valid = true;
                    }
                }
            }
        }

        valid = false;
        while(!valid && !quit){
            std::cout << "** Input a number for the patients corresponding ward **" << std::endl;
            std::cout << "** Blue   - 1 **" << std::endl;
            std::cout << "** Red    - 2 **" << std::endl;
            std::cout << "** Green  - 3 **" << std::endl;
            std::cout << "** Yellow - 4 **" << std::endl;
            std::cout << "** Purple - 5 **" << std::endl;

            std::cout << "Selection: ";

            std::getline(std::cin, wardNum);

            if(wardNum == "quit" || wardNum == "Quit"){
                quit = true;
                std::cout << "** Exiting to main menu **" << std::endl;
            }

            int wardDigit = -1;
            wardDigit = std::stoi(wardNum);
            if(wardDigit > 0 && wardDigit < 6){
                wardNum = wardCheck(wardDigit);
            }else{
                std::cout << "** Please only select a number corresponding to a ward **" << std::endl; 
            }
            valid = true;
        }
        std::cout << "Exiting" << std::endl;
        std::cout << name << " " << dob << " " << wardNum << std::endl;

        if(valid){
            std::cout << "adding patient" << std::endl;
            ward->addPatient(name, dob, "R0009", wardNum);
            quit = true;
            }
    }


}


void removePatient(Ward* ward){

}

void getAdmittedTotals(Ward* ward){

}

void getWardTotals(Ward* ward){

}

void getPatientWard(Ward* ward){

}

void getAdmittedWard(Ward* ward){

}

//std::cin.clear(); // Clears error flags
//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flushes input buffer

void printInputBuffer() {
    std::cout << "Buffer contents: ";
    while (std::cin.peek() != '\n' && std::cin.peek() != EOF) {
        std::cout << static_cast<char>(std::cin.get());  // Read and print each character
    }
    std::cout << " [END]" << std::endl;
}

std::string wardCheck(int ward){
    switch(ward){
        case 1: return "Blue";
        case 2: return "Red";
        case 3: return "Green";
        case 4: return "Yellow";
        case 5: return "Purple";
        default: return "Unknown";
    }

}
