#pragma once
#include "vex.h"

using namespace vex;

// drivetrain veriables
class driveTrain{
    private:
        controller controller1;

        //left drivetrain motors & group
        motor LMotor1 = motor(PORT17, ratio6_1, true);
        motor LMotor2 = motor(PORT19, ratio6_1, true);
        motor LMotor3 = motor(PORT14, ratio6_1, true);
        motor LMotor4 = motor(PORT18, ratio6_1, false); //true
        //motor LMotor3 = motor(PORT3, false);
        //motor LMotor4 = motor(PORT4, false);
        motor_group lDrive = motor_group(LMotor1, LMotor2, LMotor3, LMotor4);
        //right drivetrain motors & group
        motor RMotor1 = motor(PORT11, ratio6_1, true); //falsen
        motor RMotor2 = motor(PORT12, ratio6_1, false);
        motor RMotor3 = motor(PORT13, ratio6_1, false);
        motor RMotor4 = motor(PORT16, ratio6_1, false);
        //motor RMotor3 = motor(PORT7, false);
        //motor RMotor4 = motor(PORT8, false);
        motor_group rDrive = motor_group(RMotor1, RMotor2, RMotor3, RMotor4);

        //inertial sensor
        inertial Inertial = inertial(PORT6);

        //float wheelDiameter;
        float wheelDiameter;

    public:
    
        driveTrain(float wheelDiameter);
        void arcadeControls();
        void turn();
        void driveDistance(float distance);
        float getDriveTrainPosition();
        float clamp(float, float, float);

};


