#include "vex.h"
#include "driveTrain.h"


// drives robot forward and back
void driveTrain::drive2() {
    if(controller1.Axis2.value() > 5 || controller1.Axis2.value() < -5 ){
        lDrive.spin(forward, controller1.Axis2.value(), rpm);
        rDrive.spin(forward, controller1.Axis2.value(), rpm);  
    }
}
// turns robot L & R
void driveTrain::turn() {
    if(controller1.Axis1.value() > 5 || controller1.Axis1.value() < -5){
        lDrive.spin(forward, controller1.Axis1.value(), rpm);
        rDrive.spin(reverse, controller1.Axis1.value(), rpm);
    }
}  
void driveTrain::drive() {
    float axis2 = controller1.Axis2.position(percent);
    float axis1 = controller1.Axis1.position(percent);
    if(controller1.Axis2.position() > 5 || controller1.Axis2.position() < -5 || controller1.Axis4.position() > 5 || controller.Axis4.position() < -5){
        lDrive.spin(forward, axis2 + axis1, rpm);
        rDrive.spin(forward, axis1 - axis2, rpm);  
    }
}
