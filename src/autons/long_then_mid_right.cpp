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
thread im = thread(IntakeThread);
matchload.set(true);
driveTo(32.3, 1400, true, 12);
turnToAngle(90, 1500, true, 12);
driveTo(13, 900, false, 12);
turnToAngle(90, 1500, false, 12);
correct_angle = 90;
driveTo(-50, 1300, true, 12);
lift.set(true);
wait(1000, msec); 
matchload.set(false);

curveCircle( -135,  5,  1200, true, 12);
correct_angle = -135;
lift.set(false);
driveTo(20, 2000, false, 12);
im.interrupt();
driveTo(6, 2000, false, 7);
driveTo(11, 2000, true, 5);
thread ot = thread(OuttakeThread);
wait(1400, msec);
ot.interrupt();
driveTo(-37, 2000, true, 12);
turnToAngle(90, 2000, true, 12);
driveTo(-30, 2000, true, 12);
}