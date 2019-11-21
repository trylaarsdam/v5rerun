#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Lmotor = motor(PORT2, ratio18_1, false);
motor Rmotor = motor(PORT10, ratio18_1, true);
motor LiftL = motor(PORT6, ratio36_1, false);
motor LiftR = motor(PORT8, ratio36_1, true);
motor Claw = motor(PORT17, ratio18_1, false);
vex::motor liftMotor1 = vex::motor(PORT3, vex::gearSetting::ratio36_1, true);
vex::motor liftMotor2 = vex::motor(PORT9, vex::gearSetting::ratio36_1, false);
motor_group Lift = motor_group(LiftL, LiftR);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}