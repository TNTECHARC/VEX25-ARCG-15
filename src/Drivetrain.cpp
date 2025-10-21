#include "driveTrain.h"


driveTrain::driveTrain(float wheelDiameter, motor_group lDrive, motor_group rDrive, int inertialPort) : inertSensor(inertial(inertialPort)), lDrive(lDrive), rDrive(rDrive)
{
    this-> wheelDiameter = wheelDiameter;
}

void driveTrain::arcadeControls() 
{
    // Get Joystick location values in percent
    float axis3 = controller1.Axis3.position(percent);
    float axis1 = controller1.Axis1.position(percent);

    // If outside of deadzone, then move driveTrain accordingly, else set driveTrain to zero
    if(controller1.Axis3.position() > 5 || controller1.Axis3.position() < -5 || controller1.Axis1.position() > 5 || controller1.Axis1.position() < -5)
    {
        lDrive.spin(forward, axis3 + axis1, percent);
        rDrive.spin(forward, axis3 - axis1, percent); 
    }
    else 
    {
        lDrive.spin(forward, 0, percent);
        rDrive.spin(forward, 0, percent);
    }    

}


/// @brief PID drive for auton
/// @param distance inches wanting to travel
void driveTrain::driveDistance(float distance)
{
    // Create PID instances
    PID drivePID(10, 0.05, 25);
    PID angularPID(1.5, 0, 1);

    // Update distance value
    distance = getDriveTrainPosition() + distance;

    // Create starting position for the current heading
    float startHeading = inertSensor.heading();

    // Run motors using the given PID value till the drivePID has settled
    while(!drivePID.isSettled())
    {
        // Distance PID Calculation
        float current = getDriveTrainPosition();
        float error = distance - current;
        float output = drivePID.calculatePID(error);  

        // Angular PID Calculation
        float angularError = fmod(startHeading - inertSensor.heading(), 180);
        float correction = angularPID.calculatePID(angularError);
        
        // Clamp correction and output to between -12 and 12 volts
        correction = clamp(-12, 12, correction);
        output = clamp(-12, 12, output);

        // Spin Drivetrain according to the PID Values
        lDrive.spin(forward, output - correction, volt);
        rDrive.spin(forward, output + correction, volt);
        wait(10, msec);
        
    }
    
    // Set driveTrain movement to 0 to prevent drift.
    lDrive.spin(forward, 0, volt);
    rDrive.spin(forward, 0, volt);
}

/// @brief Gets the current position from the driveTrain encoders
/// @return The position in inches
float driveTrain::getDriveTrainPosition() {
    float position;
    float posL = lDrive.position(degrees);
    float posR = rDrive.position(degrees);
    position = (posL + posR) / 2;
    position = (position / 360) * M_PI * wheelDiameter;
    
    return position;
}

/// @brief Clamps the input between two values
/// @param min The minimum that input can be
/// @param max The maximum that input can be
/// @param input The number being clamped
/// @return Input clamped between min and max
float driveTrain::clamp(float min, float max, float input) {
    if(input < min)
        input = min;
    if(input > max) 
        input = max;

    return input;
}