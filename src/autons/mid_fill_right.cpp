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
  matchloadwait(400, 200);
}

void shortIntake() {
    intakeTime(600);
}



void mid_fill_right() {
    thread ml = thread(getCenterBlocks);
    thread it = thread(shortIntake);
   moveToPoint(10, 27, 1, 2000, true, 12);
   driveTo(-1.7, 1500, true, 4);
    turnToAngle(-45, 1500);
    driveTo(20, 2000, true, 12);
    it.interrupt();
    ml.interrupt();
}