# include "vex.h"

using namespace vex;


class PID {

private:
    float Kp, Ki, Kd, Integral, Derivative, previousError; //PID Constants 
    float settleError = .5; //distance from point that we want the bot to stop (half an inch)
    float timeSpentsettled = 0;

public:
    //Default Constructor
    PID () { 
        Kp = 0.00;
        Ki = 0.00;
        Kd = 0.00;
        Integral = 0.00;
        Derivative = 0.00;
         
    }
    //Defines the parts of PID for the function
    PID (float kP, float Ki, float Kd, float Integral) {
        this-> Kp = Kp;
        this-> Ki = Ki;
        this-> Kd = Kd;
    }

    
    /// @brief This is the function that calculates PID 
    /// @param error 
    /// @return 
    float calculatePID(float error) {
        float PID;

        Integral += error;
        Derivative = error - previousError;
        PID = (Kp*error) + (Ki*Integral) + (Kd*Derivative);
        previousError = error;
        if (error < settleError)
        {
            timeSpentsettled ++;
        }
        else 
            timeSpentsettled = 0;

        return PID;
    }

    /// @brief If it spends more than 3 secs settling it'll stop
    /// @return 
    bool isSettled(){    
        if(timeSpentsettled > 3000)
            return true;
        else 
            return false;

    }

};



