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


void fourball_left() {
matchload.set(true);
driveTo(33.6, 1400, true, 12);
turnToAngle(-90, 1500, true, 12);
driveTo(14, 2000, false, 12);
thread im = thread(IntakeThread);
wait(850, msec);
turnToAngle(-90, 1500, false, 12);
correct_angle = -90;
driveTo(-50, 1300, true, 12);
lift.set(true);
wait(1000, msec); 
matchload.set(false);
setPoseZero();
inertial_sensor.setHeading(0, degrees);
turnToAngle(45, 1500, false, 12);
driveTo(3, 2000, false, 12);
turnToAngle(15, 1500, false, 12);
driveTo(-30, 2000, true, 12);
turnToAngle(-45, 1400, true, 12);

}