#pragma once
#include "vex.h"
#include "PID.h"

using namespace vex;

// Drivetrain variables
class driveTrain
{
    private:

        // Left drivetrain motors & group
        motor_group lDrive;

        // Right drivetrain motors & group
        motor_group rDrive;

        // Inertial sensor
        inertial inertSensor;

        //float wheelDiameter;
        float wheelDiameter;
        

    public:

        // Constructors
        driveTrain(float wheelDiameter, motor_group lDrive, motor_group rDrive, int inertialPort);

        // Functions
        void arcadeControls();
        void driveDistance(float distance);
        float getDriveTrainPosition();
        float clamp(float min, float max, float input);
};


