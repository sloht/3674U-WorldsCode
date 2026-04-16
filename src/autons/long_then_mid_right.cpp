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



void long_then_mid_right() {
    thread ml = thread(getCenterBlocks);
    thread it = thread(shortIntake);
   moveToPoint(10, 27, 1, 2000, false, 12);
    turnToAngle(-45, 1500);
    driveTo(20, 2000, true, 12);
    outtakeTime(800);
    it.interrupt();
    ml.interrupt();
    wait(500, msec);
    driveTo(-39.23, 2500, false, 12);
    driveTo(-14,2500, true, 4);
    matchload.set(true);
    turnToAngle(180, 2000, true, 9);
    driveTo(10, 2000, false, 12);
    intakeTime(900);
    moveToPoint(x_pos, y_pos-50, getInertialHeading(), 2000, true, 12);
    hood.set(true);
    intakeTime(700);
wait(900, msec);
setPoseZero();
moveToPoint(x_pos+9, y_pos+4, 1, 2000, false, 12);
turnToAngle(0, 1500, false, 12);
driveTo(-30, 2000, false, 12);
turnToAngle(45, 1500, false, 12);

    
}