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



void seven_ball_right() {
    thread ml = thread(getCenterBlocks);
    thread it = thread(shortIntake);
    y_pos = 2;
   moveToPoint(10, 28, 1, 2000, false, 12);
   correct_angle = -45;
    turnToAngle(-45, 300, false, 12);
    driveTo(-19.23, 2500, false, 12);
    driveTo(-11, 2500, true, 4);
    matchload.set(true);
    correct_angle = 180;
    driveTo(14, 2000, false, 12);
    thread im = thread(IntakeThread);
    wait(800, msec);
    turnToAngle(180, 400);
    driveTo(-50, 1200, true, 12);
    lift.set(true);
    intakeTime(1200);
setPoseZero();
inertial_sensor.setHeading(0, degrees);
turnToAngle(45, 400, false, 12);
driveTo(3, 400, true, 12);
turnToAngle(0, 1500, false, 12);
correct_angle = 0;
driveTo(-30, 2000, true, 12);
turnToAngle(-45, 1400, true, 12);
}

    thread it = thread(shortIntake);
    y_pos = 2;
   moveToPoint(10, 26, 1, 2000, false, 12);
   correct_angle = -45;
    turnToAngle(-45, 300, false, 12);
    driveTo(-19.23, 2500, false, 12);
    driveTo(-11, 2500, true, 4);
    matchload.set(true);
    correct_angle = 180;
    driveTo(14, 2000, false, 12);
    thread im = thread(IntakeThread);
    wait(800, msec);
    turnToAngle(180, 400);
    driveTo(-50, 1200, true, 12);
    lift.set(true);
    intakeTime(1200);
setPoseZero();
inertial_sensor.setHeading(0, degrees);
turnToAngle(45, 400, false, 12);
driveTo(3, 400, true, 12);
turnToAngle(0, 1500, false, 12);
correct_angle = 0;
driveTo(-30, 2000, true, 12);
turnToAngle(-45, 1400, true, 12);