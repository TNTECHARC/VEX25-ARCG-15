#pragma once
#include "vex.h"

using namespace vex;

// Drivetrain variables
class driveTrain
{
    private:

        // Controller Instance
        controller controller1;

        // Left drivetrain motors & group
        motor LMotor1 = motor(PORT1, ratio6_1, false);
        motor LMotor2 = motor(PORT11, ratio6_1, false);
        motor_group lDrive = motor_group(LMotor1, LMotor2);

        // Right drivetrain motors & group
        motor RMotor1 = motor(PORT10, ratio6_1, false);
        motor RMotor2 = motor(PORT20, ratio6_1, false);
        motor_group rDrive = motor_group(RMotor1, RMotor2);

        // Inertial sensor
        inertial inertSensor = inertial(PORT6);

        //float wheelDiameter;
        float wheelDiameter;

    public:

        // Constructors
        driveTrain(float wheelDiameter);

        // Functions
        void arcadeControls();
        void driveDistance(float distance);
        float getDriveTrainPosition();
        float clamp(float min, float max, float input);

};


