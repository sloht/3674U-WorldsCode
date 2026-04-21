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
matchload.set(true);
driveTo(33.6, 1400, true, 12);
turnToAngle(90, 1500, true, 12);
driveTo(14, 2000, false, 12);
thread im = thread(IntakeThread);
wait(850, msec);
turnToAngle(90, 1500, false, 12);
correct_angle = 90;
driveTo(-50, 1300, true, 12);
lift.set(true);
wait(1000, msec); 
matchload.set(false);

curveCircle( -135,  6,  1200, true, 12);
lift.set(false);
thread gb = thread(getblocks);
driveTo(20, 2000, false, 12);
driveTo(10, 2000, true, 12);
im.interrupt();
driveTo(15, 2000, true, 12);
thread ot = thread(OuttakeThread);
wait(1100, msec);
ot.interrupt();
driveTo(-37, 2000, true, 12);
turnToAngle(90, 2000, true, 12);
driveTo(-32, 2000, true, 12);
}