#pragma once
#include "vex.h"

using namespace vex;

// drivetrain veriables
class driveTrain{
    private:
        controller controller1;

        //left drivetrain motors & group
        motor LMotor1 = motor(PORT1, false);
        motor LMotor2 = motor(PORT11, false);
        //motor LMotor3 = motor(PORT3, false);
        //motor LMotor4 = motor(PORT4, false);
        motor_group lDrive = motor_group(LMotor1, LMotor2);
        //right drivetrain motors & group
        motor RMotor1 = motor(PORT10, false);
        motor RMotor2 = motor(PORT20, false);
        //motor RMotor3 = motor(PORT7, false);
        //motor RMotor4 = motor(PORT8, false);
        motor_group rDrive = motor_group(RMotor1, RMotor2);

        //float wheelDiameter;
        float wheelDiameter;

    public:
    
    driveTrain(float wheelDiameter);

    void arcadeControls();
    void turn();

    void driveDistance(float distance);

    float getDriveTrainPosition();
};


