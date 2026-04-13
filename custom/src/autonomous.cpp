#include "vex.h"
#include "utils.h"
#include "pid.h"
#include <ctime>
#include <cmath>
#include <thread>

#include "../include/autonomous.h"
#include "motor-control.h"

//set position: x_pos = x; y_pos = y;
//inertial_sensor.setRotation(θ, deg);
//AND use correct_angle = desired angle

void intakeTime(double time_ms) {
  intake_motor.spin(vex::directionType::rev, 12, voltageUnits::volt);
  wait(time_ms, msec);
  intake_motor.stop(brakeType::coast);
}

