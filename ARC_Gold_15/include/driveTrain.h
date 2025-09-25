#include "vex.h"

using namespace std;
// drivetrain veriables
void driveTrain{
    //left drivetrain motors & group
    motor LMotor1 = motor(PORT1, false)
    motor LMotor2 = motor(PORT2, false)
    motor LMotor3 = motor(PORT3, false)
    motor LMotor4 = motor(PORT4, false)
    motor_group lDrive = motor_group(LMotor1, LMotor2, LMotor3, LMotor4)
    //right drivetrain motors & group
    motor RMotor1 = motor(PORT5, false)
    motor RMotor2 = motor(PORT6, false)
    motor RMotor3 = motor(PORT7, false)
    motor RMotor4 = motor(PORT8, false)
    motor_group rDrive = motor_group(RMotor1, RMotor2, RMotor3, RMotor4)
}