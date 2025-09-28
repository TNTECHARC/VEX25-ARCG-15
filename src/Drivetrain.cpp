#include "vex.h"
#include "driveTrain.h"


// drives robot forward and back
// void driveTrain::drive2() {
//     if(controller1.Axis3.value() > 5 || controller1.Axis3.value() < -5 ){
//         lDrive.spin(forward, controller1.Axis3.value(), rpm);
//         rDrive.spin(forward, controller1.Axis3.value(), rpm);  
//     }
// }
// turns robot L & R
void driveTrain::turn() {
    if(controller1.Axis1.value() > 5 || controller1.Axis1.value() < -5){
        lDrive.spin(forward, controller1.Axis1.value(), rpm);
        rDrive.spin(reverse, controller1.Axis1.value(), rpm);
    }
}  
void driveTrain::drive() {
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
