//
// Created by lu.gao on 3/13/2020.
//

#ifndef LIDAR_DETECTION_SIMULATION_CHIRPSIGNAL_H
#define LIDAR_DETECTION_SIMULATION_CHIRPSIGNAL_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Constants.h"
#include "DataStructure.h"

class ChirpSignal {

public:
    // constructor and destructor
    ChirpSignal();
    ~ChirpSignal();
    // calculate chirp signal in time domain
    void calcChirpSignal();
    void setChirpProperty(ChirpProperty chirpProperty, ADC adcProperty);
    // getter function to return the pointer to the chirp signal
    std::vector<ChirpSignalStruct>* getChirpSignal();

private:
    // chirp properties
    double chirpPeriod;
    double chirpSlopeTime;
    double samplingPeriod;
    // for each sample, time, frequency and signal are packed up in a struct
    std::vector<ChirpSignalStruct>* ptrChirpSignal = new std::vector<ChirpSignalStruct>;

};

#endif //LIDAR_DETECTION_SIMULATION_CHIRPSIGNAL_H
