#pragma once
#include "PID.h"

class PID {

private:
    float Kp, Ki, Kd, Integral, Derivative, previousError; //PID Constants 
    float settleError = .5; //distance from point that we want the bot to stop (half an inch)
    float timeSpentsettled = 0;

public:
    //Default Constructor
    PID();
    //Defines the parts of PID for the function
    PID(float kP, float Ki, float Kd);

    
    /// @brief This is the function that calculates PID 
    /// @param error 
    /// @return 
    float calculatePID(float error);
    /// @brief If it spends more than 3 secs settling it'll stop
    /// @return 
    bool isSettled();

};



