# include "PID.h"

    /// @brief Default Constructor
    PID::PID () { 
        Kp = 0.00;
        Ki = 0.00;
        Kd = 0.00;
        Integral = 0.00;
        Derivative = 0.00; 
    }

    /// @brief Defines the parts of PID for the function
    /// @param Kp Proportion Constant
    /// @param Ki Integral Constant
    /// @param Kd Derivative Constant
    PID::PID (float Kp, float Ki, float Kd) {
        this->Kp = Kp;
        this->Ki = Ki;
        this->Kd = Kd;
    }

    
    /// @brief This is the function that calculates PID 
    /// @param error Where you want to be - where you are
    /// @return PID output
    float PID::calculatePID(float error) {
        float PID;

        Integral += error;
        Derivative = error - previousError;

        if((previousError > 0 && error < 0) || (previousError < 0 && error > 0)) {
            Integral = 0;
        }

        PID = (Kp*error) + (Ki*Integral) + (Kd*Derivative);
        previousError = error;

        if (fabs(error) < settleError)
            timeSpentSettled++;
        else 
            timeSpentSettled = 0;

        return PID;
    }

    /// @brief If it spends more than 3 secs settling it'll stop
    /// @return True if settled, and false if not
    bool PID::isSettled(){    
        if(timeSpentSettled > 3000)
            return true;
        else 
            return false;
    }




