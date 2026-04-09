#include "vex.h"
#include "utils.h"
#include "pid.h"
#include <ctime>
#include <cmath>
#include <thread>

#include "../custom/include/autonomous.h"
#include "motor-control.h"

//set position: x_pos = x; y_pos = y;
//inertial_sensor.setRotation(θ, deg);
//AND use correct_angle = desired angle


void seven_ball_left() {
    correct_angle = inertial_sensor.rotation();  
    intake_motor.spin(vex::directionType::rev, 12, voltageUnits::volt);
    driveTo(24, 2000, true, 10);
    matchloadwait(460
    );
    

}