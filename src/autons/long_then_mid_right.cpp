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

void long_then_mid_right() {
turnToAngle(45, 1500, false, 12);
driveTo(3, 2000, false, 12);
turnToAngle(15, 1500, false, 12);
driveTo(-30, 2000, true, 12);
turnToAngle(-45, 1400, true, 12);
}