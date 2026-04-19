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

void getCenterBlocks() {
  matchloadwait(400, 400);
}

void shortIntake() {
    intakeTime(900);
}



void mid_fill_right() {
    thread ml = thread(getCenterBlocks);
    thread it = thread(shortIntake);
    y_pos = 2;
   moveToPoint(10, 26, 1, 2000, false, 12);
    turnToAngle(-45, 1500);
    driveTo(20, 2000, true, 12);
    outtakeTime(1200);
    it.interrupt();
    ml.interrupt();
    wait(500, msec);
    driveTo(-39.23, 2500, false, 12);
    driveTo(-14,2500, true, 4);
    matchload.set(true);
    turnToAngle(180, 2000, true, 9);
    driveTo(14, 1200, true, 12);
    intakeTime(1800);
    turnToAngle(180, 2000, false, 12);
    correct_angle = 180;
    driveTo(-50, 1200, true, 12);
    lift.set(true);
    intakeTime(1200);
setPoseZero();
inertial_sensor.setHeading(0, degrees);
moveToPoint(x_pos-8, y_pos-4, 1, 2000, true, 12);
turnToAngle(180, 1500, true, 12);
driveTo(-20, 2000, true, 12);



    
}