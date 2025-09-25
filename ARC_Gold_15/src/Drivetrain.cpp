#include "vex.h"
#include "driveTrain.h"


// drives robot forward and back
void driveTrain::drive() {
    if(controller1.Axis2.value() > 5 || controller1.Axis2.value() < -5){
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
