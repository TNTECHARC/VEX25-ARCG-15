#include "vex.h"
#include "driveTrain.h"

using namespace std;

class Drive {
private:
public:
    // drives robot forward and back
    void drive() {
        if(controler.axis2 > 5 || controler.axis2 < -5){
            lDrive.spin(forward, controler.axis2, rpm);
            rDrive.spin(forward, controler.axis2, rpm);  
        }
    }
    // turns robot L & R
    void turn() {
        if(controler.axis1 > 5 || controler.axis1 < -5){
            lDrive.spin(forward, controler.axis1, rpm);
            rDrive.spin(backward, controler.axis1, rpm);
        }
    }  
};