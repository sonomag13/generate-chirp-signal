#include <iostream>
#include "ChirpSignal.h"
#include "ToolBox.h"

int main() {

    std::cout << "\n\ncreat half chirp in time domain" << std::endl;

    // chirp properties
    std::cout << "- get chirp property" << std::endl;
    double chirpSlopeVoltage = 180.0e+6;   // chirp slope vs chirp voltage in Hz/V
    double chirpVoltage = 7.0;             // chirp voltage in V
    double chirpFreq = 180.0e3;            // chirp frequency
    ChirpProperty chirpProperty(chirpSlopeVoltage, chirpVoltage, chirpFreq);

    // std::cout << "chirp freq = " << chirpProperty.chirpFreq << std::endl;
    // std::cout << "chirp Period = " << chirpProperty.chirpPeriod << std::endl;

    // ADC property
    std::cout << "- get ADC property" << std::endl;
    int adcResolution = 12;
    float refVoltage = 1.7;
    double samplingFreq = 3.0e9;
    ADC adcProperty(adcResolution, refVoltage, samplingFreq);

    // instantiate chirp signal object
    std::cout << "\n\ninstantiate chirp signal" << std::endl;
    std::cout << "- chirp signal constructor" << std::endl;

    ChirpSignal chirpSignal;
    chirpSignal.setChirpProperty(chirpProperty, adcProperty);
    std::cout << "- calculate chirp signal in time domain" << std::endl;
    chirpSignal.calcChirpSignal();
    std::cout << "\n\nprint the value of half chirp" << std::endl;
    // printType = 1: print on screen; 2: print to a csv file
    printfChirpSignal(chirpSignal.getChirpSignal(), 2);

    return 0;

}