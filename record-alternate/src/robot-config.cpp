#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
vex::brain  Brain;

// VEXcode device constructors
vex::controller Controller1 = controller(primary);
vex::motor FLdrive = vex::motor(PORT14, vex::gearSetting::ratio18_1, false); //ports may need to be changed later based on dead ports
vex::motor FRdrive = vex::motor(PORT13, vex::gearSetting::ratio18_1, true); //ports may need to be changed later based on dead ports
vex::motor DR4B1 = vex::motor(PORT15, vex::gearSetting::ratio36_1, false);
vex::motor DR4B2 = vex::motor(PORT18, vex::gearSetting::ratio36_1, true);
vex::motor liftMotor = vex::motor(PORT20, vex::gearSetting::ratio36_1, true);
vex::motor intakeL = vex::motor(PORT12, vex::gearSetting::ratio6_1, false);
vex::motor clawMotor = vex::motor(PORT19, vex::gearSetting::ratio18_1, true);
vex::motor intakeR = vex::motor(PORT21, vex::gearSetting::ratio6_1, false);
vex::motor_group DR4B( DR4B1, DR4B2);
vex::motor_group intake( intakeL, intakeR );
// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}