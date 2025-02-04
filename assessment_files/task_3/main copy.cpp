/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#include <exception>
#include <iostream>
#include <memory>
#include <iomanip>
#include "Time.h"

int main(){
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    std::cout << std::endl << "*** Q3 PART 1 ***" << std::endl;

    // Print hour with one leading zero
    // This can be useful when printing time
    int tempHour = 3;
    std::cout << "Hour: " << std::setfill('0') << std::setw(2) 
                                    << tempHour << std::endl;

    // Create a time object: examStartTime and initialize it to 09:00:00
    std::shared_ptr<Time> examStartTime = std::make_shared<Time>(9, 0, 0);
    // Print the examStartTime and the seconds from zero
    std::cout << "Exam Start Time: " << *examStartTime << " (" 
            << examStartTime->getnSeconds() << ") " << std::endl;

    // Create a time object: examEndTime and initialize it to 13:25:15
    std::shared_ptr<Time> examEndTime = std::make_shared<Time>(13, 25, 15);
    // Print the examEndTime and the seconds from zero
    std::cout << "Exam End Time: " << *examEndTime << " (" 
                        << examEndTime->getnSeconds() << ") "<< std::endl;

    // Compute & print examDuration
    Time examDuration = *examEndTime - *examStartTime;
    std::cout << "Exam Duration: " 
                    << examDuration << std::endl;

    // Exam exteded by 1 hour 20 minutes. Compute new end time
    *examEndTime += Time(1,20,0);
    std::cout << "New Exam End Time: " << *examEndTime << std::endl;

    
    std::cout << std::endl << "*** Q3 PART 2 ***" << std::endl;

    // Create two time objects
    Time time1(03, 12, 11);
    Time time2(11, 15, 35);
    
    std::cout << "time1: " << time1 << ", time2: " << time2 << std::endl;

    //Compare the two dates and print
    if (time1 == time2){
        std::cout << "time1 == time2" << std::endl;
    }else if (time1 > time2){
            std::cout << "time1 > time2" << std::endl;
    }else{
            std::cout << "time1 < time2" << std::endl;
    }

    std::cout << std::endl << "*** Q3 PART 3 ***" << std::endl;
    
    // Create a date object
    Time time3(10, 6, 20);
    std::cout << "time3: " << time3 << std::endl;

    // Reduce 45 seconds from time3
    time3 -= 45;
    std::cout << "time3: " << time3 << std::endl;

    std::cout << std::endl << "*** Q3 PART 4 ***" << std::endl;

    std::cout << "time3: " << time3 << std::endl;
    
    try{
    //Update the minute of time3
    time3["minute"] = 15;
    std::cout << "time3:  " << std::setfill('0') << std::setw(2) 
                                                << time3["hour"] 
                    << ":" << std::setfill('0') << std::setw(2) 
                                                << time3["minute"] 
                    << ":" << std::setfill('0') << std::setw(2) 
                                                << time3["second"] 
                    << std::endl;

    }catch (std::exception& e) {
      std::cout << "*** caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}