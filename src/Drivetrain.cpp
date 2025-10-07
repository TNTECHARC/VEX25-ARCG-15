#include "vex.h"
#include "driveTrain.h"
#include "PID.h"


driveTrain::driveTrain(float wheelDiameter)
{
    this-> wheelDiameter = wheelDiameter;
}


// turns robot L & R
void driveTrain::turn() {
    if(controller1.Axis1.value() > 5 || controller1.Axis1.value() < -5){
        lDrive.spin(forward, controller1.Axis1.value(), rpm);
        rDrive.spin(reverse, controller1.Axis1.value(), rpm);
    }
}  
void driveTrain::arcadeControls() {
    float axis2 = controller1.Axis3.position(percent);
    float axis1 = controller1.Axis1.position(percent);
    if(controller1.Axis3.position() > 5 || controller1.Axis3.position() < -5 || controller1.Axis1.position() > 5 || controller1.Axis1.position() < -5){
        lDrive.spin(forward, axis2 + axis1, percent);
        rDrive.spin(forward, axis1 - axis2, percent); 
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
    PID drivePID(0.5, 0.01, 5);
    PID angularPID(0.4, 0, 1);
    float current = getDriveTrainPosition();
    distance = current + distance;
    float error = distance - current;
    float startHeading = Inertial.heading();
    float anglularError = startHeading - Inertial.heading();

    while(!drivePID.isSettled()){

        current = getDriveTrainPosition();
        error = distance - current;
        float output = drivePID.calculatePID(error);

        anglularError = fmod(startHeading - Inertial.heading(), 180);
        float correction = angularPID.calculatePID(anglularError);
        
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