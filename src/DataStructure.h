//
// Created by lu.gao on 3/14/2020.
//

#ifndef LIDAR_DETECTION_SIMULATION_DATASTRUCTURE_H
#define LIDAR_DETECTION_SIMULATION_DATASTRUCTURE_H

// chirp properties
struct ChirpProperty {
    double chirpSlopeVoltage;       // chirp slope vs chirp voltage in Hz/V
    double chirpVoltage;            // chirp voltage in V
    double chirpFreq;               // chirp frequency in Hz
    double chirpPeriod;             // chirp period in sec
    double chirpSlopeTime;          // chirp slope vs time in Hz/sec
    ChirpProperty(double chirpSlopeVoltage, double chirpVoltage, double chirpFreq){
        this->chirpSlopeVoltage = chirpSlopeVoltage;
        this->chirpVoltage = chirpVoltage;
        this->chirpFreq = chirpFreq;
        this->chirpPeriod = 1.0 / this->chirpFreq;
        this->chirpSlopeTime = this->chirpSlopeVoltage * this->chirpVoltage / (0.5 * this->chirpPeriod);
    }
};

// ADC properties
struct ADC {
    int adcResolution;      // ADC resolution in LSB
    float refVoltage;       // reference voltage in V
    double samplingFreq;    // sampling frequency in Hz
    ADC(int adcResolution, double refVoltage, double samplingFreq) {
        this->adcResolution = adcResolution;
        this->refVoltage = refVoltage;
        this->samplingFreq = samplingFreq;
    }
};

// structure of chirp signal consists of time, frequency and signal
struct ChirpSignalStruct {
    double time;
    double freq;
    double signal;
    ChirpSignalStruct(double time, double freq, double signal) {
        this->time = time;
        this->freq = freq;
        this->signal = signal;
    }
};

#endif //LIDAR_DETECTION_SIMULATION_DATASTRUCTURE_H