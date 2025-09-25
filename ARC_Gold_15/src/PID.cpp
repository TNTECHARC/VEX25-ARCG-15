# include "vex.h"

using namespace vex;


class PID {

private:
    float Kp, Ki, Kd, Integral, Derivative, previousError; //PID Constants

public:
    PID () { //Default Constructor
        Kp = 0.00;
        Ki = 0.00;
        Kd = 0.00;
        Integral = 0.00;
        Derivative = 0.00;
         
    }
    PID (float kP, float Ki, float Kd, float Integral) {
        this-> Kp = Kp;
        this-> Ki = Ki;
        this-> Kd = Kd;
    }

    //Accessor Functions
    getKp() const {
        return Kp;
    }
    getKi() const {
        return Ki;
    }
    getKd() const {
        return Kd;
    }

    //Mutator functions

    setKp(Kp) {
        this-> Kp = Kp;
    }

    setKi(Ki) {
        this-> Ki = Ki;
    }

    setKd(Kd) {
        this-> Kd = Kd;
    }

    float calculatePID(float error) {
        float PID;

        Integral += error;
        Derivative = error - previousError;
        PID = (Kp*error) + (Ki*Integral) + (Kd*Derivative);
        previousError = error;

        return PID;
    }

};



