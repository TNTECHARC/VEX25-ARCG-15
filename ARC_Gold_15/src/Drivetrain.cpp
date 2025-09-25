#include "vex.h"
#include "driveTrain.h"

using namespace std;

// Moving forward
void forwardDT() {
    lDrive.spin(forward);
    rDrive.spin(forward);
}

// Moving backward
void backwardDT() {
    lDrive.spin(backward);
    rdrive.spin(backward);
}

// Turns right
void turnRight() {
    lDrive.spin(forward);
    rDrive.spin(backward);
}

// Turns left
void turnLeft() {
    rDrive.spin(forward);
    lDrive.spin(backward);
}


