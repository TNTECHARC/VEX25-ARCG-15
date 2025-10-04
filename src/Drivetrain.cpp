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
    PID drivePID(1, 1, 1);
    float current;
    float error = distance - current;

    while(!drivePid.isSettled())
    {
        current;
        error = distance - current;
        float output = drivePID.calculatePID(error);

        lDrive.spin(forward, output, volts);
        rDrive.spin(forward, output, volts);

        wait(10, msec);
    }
    lDrive.spin(forward, 0, volts);
    rDrive.spin(forward, 0, volts);
    //(deg/360)*pi*wheelDiameter = inches
}


