//
// Created by lu.gao on 3/13/2020.
//

#include "ChirpSignal.h"

ChirpSignal:: ChirpSignal() {
    // std::cout << "\n\nchirp signal constructor" << std::endl;
}

ChirpSignal::~ChirpSignal() {
    std::cout << "\n\nchirp signal destructor" << std::endl;
}

void ChirpSignal::setChirpProperty(ChirpProperty chirpProperty, ADC adcProperty) {
    this->chirpPeriod = chirpProperty.chirpPeriod;
    this->chirpSlopeTime = chirpProperty.chirpSlopeTime;
    this->samplingPeriod = 1.0 / adcProperty.samplingFreq;
    // std::cout << "chirp period = " << this->chirpPeriod << std::endl;
}

void ChirpSignal::calcChirpSignal() {
    int numSampleHalfChirp = 0.5 * chirpPeriod / samplingPeriod;
    double currentTime = 0.00, currentFreq, signal;
    std::vector<std::pair<double, double>> upChirpSignal;
    std::pair<double, double> currentFreqSignal;
    for(int i = 0; i < numSampleHalfChirp; i++) {
        currentFreq = chirpSlopeTime * currentTime;
        signal = sin(PI * chirpSlopeTime * pow(currentTime, 2));
        upChirpSignal.push_back(std::make_pair(currentFreq, signal));
        currentTime += samplingPeriod;
    }
    // insert the up chirp into the full chirp vector
    currentTime = 0.00;  // reset the time stamp
    for(int i = 0; i < upChirpSignal.size(); i++) {
        ChirpSignalStruct chrpSig(currentTime, upChirpSignal[i].first, upChirpSignal[i].second);
        ptrChirpSignal->push_back(chrpSig);
        currentTime += samplingPeriod;
    }
    while(!upChirpSignal.empty()) {
        currentFreqSignal = upChirpSignal.back();
        upChirpSignal.pop_back();
        ptrChirpSignal->push_back(ChirpSignalStruct(currentTime, currentFreqSignal.first, currentFreqSignal.second));
        currentTime += samplingPeriod;
    }
}

std::vector<ChirpSignalStruct>* ChirpSignal::getChirpSignal() {
    return ptrChirpSignal;
}

