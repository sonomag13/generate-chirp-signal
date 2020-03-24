//
// Created by lu.gao on 3/14/2020.
//

#ifndef LIDAR_DETECTION_SIMULATION_TOOLBOX_H
#define LIDAR_DETECTION_SIMULATION_TOOLBOX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DataStructure.h"
#include "ChirpSignal.h"

// print out time domain chirp signal
void printfChirpSignal(std::vector<ChirpSignalStruct>* chirpSignal, int printType) {

    if (printType == 1) {
        for(auto itr = chirpSignal->begin(); itr != chirpSignal->end(); itr++) {
            std::cout << "\t\t" << itr->time << ", " << itr->freq  << ", "<< itr->signal << std::endl;
        }
    }
    else {
        std::ofstream fileChirpSignal;
        fileChirpSignal.open ("chirp-signal-time-domain.csv");
        fileChirpSignal << "time (s), frequency (Hz), signal\n";
        for(auto itr = chirpSignal->begin(); itr != chirpSignal->end(); itr++) {
            fileChirpSignal << itr->time << "," << itr->freq  << ","<< itr->signal << "\n";
        }
        fileChirpSignal.close();
    }

}

#endif //LIDAR_DETECTION_SIMULATION_TOOLBOX_H
