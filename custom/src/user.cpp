#include "vex.h"
#include "motor-control.h"
#include "../custom/include/autonomous.h"
#include "../custom/include/robot-config.h"

// Modify autonomous, driver, or pre-auton code below

bool drift = false;

void runAutonomous() {
  int auton_selected = 6;
  switch(auton_selected) {
    case 1:
      seven_ball_left();
      break;
    case 2:
      seven_ball_right();
      break;  
    case 3:
      fourball_left();
      break;
    case 4:
      fourball_right();
      break;
    case 5:
      long_then_mid_left();
      break;
    case 6:
      long_then_mid_right();
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
  }
}

// controller_1 input variables (snake_case)
int ch1, ch2, ch3, ch4;
bool l1, l2, r1, r2;
bool button_a, button_b, button_x, button_y;
bool button_up_arrow, button_down_arrow, button_left_arrow, button_right_arrow;
int chassis_flag = 0;


bool matchloadCD = true;
bool descoreCD = true;
bool hoodCD = true;

bool matchloadState = false;
bool descoreState = false;
bool hoodState = false;

bool liftState = true;



void runDriver() {
  stopChassis(coast);
  heading_correction = false;
  int screenUpdateCounter = 0;
  while (true) {
    // [-100, 100] for controller stick axis values
    ch1 = controller_1.Axis1.value();
    ch2 = controller_1.Axis2.value();
    ch3 = controller_1.Axis3.value();
    ch4 = controller_1.Axis4.value();

    // true/false for controller button presses
    l1 = controller_1.ButtonL1.pressing();
    l2 = controller_1.ButtonL2.pressing();
    r1 = controller_1.ButtonR1.pressing();
    r2 = controller_1.ButtonR2.pressing();
    button_a = controller_1.ButtonA.pressing();
    button_b = controller_1.ButtonB.pressing();
    button_x = controller_1.ButtonX.pressing();
    button_y = controller_1.ButtonY.pressing();
    button_up_arrow = controller_1.ButtonUp.pressing();
    button_down_arrow = controller_1.ButtonDown.pressing();
    button_left_arrow = controller_1.ButtonLeft.pressing();
    button_right_arrow = controller_1.ButtonRight.pressing();



int intakePct = (r1 ? 100 : 0) - (r2 ? 100 : 0);
if (intakePct > 0) {
    double veloControl = (liftState ? 1 : 1);
    intake_motor.spin(directionType::fwd, intakePct * veloControl, velocityUnits::pct);
} else if (intakePct < 0) {
    intake_motor.spin(directionType::rev, -intakePct, velocityUnits::pct);
} else {
    intake_motor.stop(brakeType::coast);
}

    if (button_down_arrow) {
      if (matchloadCD) {
        matchloadCD = false;
        matchloadState = !matchloadState;
        matchload.set(matchloadState);
      }
    } else {
      matchloadCD = true;
    }


    if (button_b) {
      if (descoreCD) {
        descoreCD = false;
        descoreState = !descoreState;
        descore.set(descoreState);
      }
    } else {
      descoreCD = true;
    }


    if (l1) {
      lift.set(true);
      liftState = true;
    } else {
      lift.set(false);
      liftState = false;
    }


    if (l2) {
      if (hoodCD) {
        hoodCD = false;
        hoodState = !hoodState;
        hood.set(hoodState);
        intake_motor.spin(directionType::fwd, 12, velocityUnits::pct);
      }
    } else {
      hoodCD = true;
    }

    driveChassis(ch3 * 0.12 + ch1 * 0.12 , ch3 * 0.12 - ch1 * 0.12);

    if (++screenUpdateCounter >= 10) {
      screenUpdateCounter = 0;
      double leftTemp = (left_chassis1.temperature(temperatureUnits::celsius) + left_chassis2.temperature(temperatureUnits::celsius) + left_chassis3.temperature(temperatureUnits::celsius)) / 3.0;
      double rightTemp = (right_chassis1.temperature(temperatureUnits::celsius) + right_chassis2.temperature(temperatureUnits::celsius) + right_chassis3.temperature(temperatureUnits::celsius)) / 3.0;
      double intakeTemp = (lowerIntake.temperature(temperatureUnits::celsius) + upperIntake.temperature(temperatureUnits::celsius)) / 2.0;
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("L: %.1fC", leftTemp);
      Brain.Screen.newLine();
      Brain.Screen.print("R: %.1fC", rightTemp);
      Brain.Screen.newLine();
      Brain.Screen.print("I: %.1fC", intakeTemp);
    }

    wait(10, msec);
  }
}

void runPreAutonomous() {
  vexcodeInit();
  
  inertial_sensor.calibrate();
  double initial = inertial_sensor.heading();
	wait(1000, msec);
	if(std::abs(inertial_sensor.heading() - initial) > 0.5) drift = true; 
  if (inertial_sensor.isCalibrating()) {
    while (inertial_sensor.isCalibrating()) {
      wait(10, msec);
    }
    controller_1.rumble(".");
  } else {
    controller_1.rumble("...");
  }
  if (drift) {
    controller_1.rumble("...");
  }

  double current_heading = inertial_sensor.heading();
  Brain.Screen.print(current_heading);
  
  // odom tracking
  resetChassis();
  if(using_horizontal_tracker && using_vertical_tracker) {
    thread odom = thread(trackXYOdomWheel);
  } else if (using_horizontal_tracker) {
    thread odom = thread(trackXOdomWheel);
  } else if (using_vertical_tracker) {
    thread odom = thread(trackYOdomWheel);
  } else {
    thread odom = thread(trackNoOdomWheel);
  }
}