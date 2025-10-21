#pragma once
#include <math.h>

class PID 
{

    private:

        // Variables
        float Kp, Ki, Kd, Integral = 0, Derivative = 0, previousError = 0;
        float settleError = .5; //distance from point that we want the bot to stop (half an inch)
        float timeSpentSettled = 0;

    public:

        // Constructors
        PID();
        PID(float Kp, float Ki, float Kd);

        // Functions
        float calculatePID(float error);
        bool isSettled();

};



