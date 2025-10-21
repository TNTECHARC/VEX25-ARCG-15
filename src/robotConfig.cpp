#include "robotConfig.h"

// Controller Instance
controller controller1;

// Left drivetrain motors
motor LMotor1 = motor(PORT1, ratio6_1, false);
motor LMotor2 = motor(PORT11, ratio6_1, false);

// Right drivetrain motors
motor RMotor1 = motor(PORT10, ratio6_1, false);
motor RMotor2 = motor(PORT20, ratio6_1, false);

// Inertial sensor
inertial inertSensor = inertial(PORT6);