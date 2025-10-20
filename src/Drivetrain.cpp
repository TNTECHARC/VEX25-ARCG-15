#include "vex.h"
#include "driveTrain.h"
#include "PID.h"


driveTrain::driveTrain(float wheelDiameter)
{
    this-> wheelDiameter = wheelDiameter;
    Inertial.calibrate();

}


// turns robot L & R
void driveTrain::turn() {
    if(controller1.Axis1.value() > 5 || controller1.Axis1.value() < -5){
        lDrive.spin(forward, controller1.Axis1.value(), rpm);
        rDrive.spin(reverse, controller1.Axis1.value(), rpm);
    }
}  
void driveTrain::arcadeControls() {
    float axis3 = controller1.Axis3.position(percent);
    float axis1 = controller1.Axis1.position(percent);
    if(controller1.Axis3.position() > 5 || controller1.Axis3.position() < -5 || controller1.Axis1.position() > 5 || controller1.Axis1.position() < -5){
        lDrive.spin(forward, axis3 + axis1, percent);
        rDrive.spin(forward, axis3 - axis1, percent); 
    }
    else {
        lDrive.spin(forward, 0, percent);
        rDrive.spin(forward, 0, percent);
    }    

}


/// @brief PID drive for aunton
/// @param distance in inches wanting to travel
void driveTrain::driveDistance(float distance)
{
    PID drivePID(10, 0.05, 25);
    PID angularPID(1.5, 0, 1);
    float current = getDriveTrainPosition();
    distance = current + distance;
    float error = distance - current;
    float startHeading = Inertial.heading();
    float angularError = startHeading - Inertial.heading();

    while(!drivePID.isSettled()){

        current = getDriveTrainPosition();
        error = distance - current;
        float output = drivePID.calculatePID(error);

        angularError = fmod(startHeading - Inertial.heading(), 180);
        float correction = angularPID.calculatePID(angularError);
        
        //clamp correction and output to between -12 and 12
        correction = clamp(-6, 6, correction);
        output = clamp(-12, 12, output);

        lDrive.spin(forward, output + correction, volt);
        rDrive.spin(forward, output - correction, volt);
        wait(10, msec);
        
    }
    lDrive.spin(forward, 0, volt);
    rDrive.spin(forward, 0, volt);
}

float driveTrain::getDriveTrainPosition() {
    float position;
    float posL = lDrive.position(degrees);
    float posR = rDrive.position(degrees);
    position = (posL + posR) / 2;
    position = (position / 360) * M_PI * wheelDiameter;
    
    return position;
}

float driveTrain::clamp(float min, float max, float input) {
    if(input < min)
        input = min;
    if(input > max) 
        input = max;

    return input;
}