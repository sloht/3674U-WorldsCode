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
    thread it = thread(shortIntake);
    thread ml = thread(getCenterBlocks());
   moveToPoint(-11, 27, 1, 2000, false, 12);
    turnToAngle(45, 1500);
   
    driveTo(-20.23, 2500, false, 12);
    driveTo(-16,2500, true, 4);
     matchload.set(true);
    turnToAngle(180, 350, false, 9);
    correct_angle = 180;
    driveTo(11, 1200, false, 12);
    intakeTime(680);
    turnToAngle(180, 2000, false, 12);
    correct_angle = 180;
    driveTo(-50, 1200, true, 12);
    lift.set(true);
    intakeTime(1200);
setPoseZero();
turnToAngle(45, 1500, false, 12);
driveTo(6, 2000, true, 12);
turnToAngle(5, 1500, true, 12);
driveTo(30, 2000, true, 12);



}