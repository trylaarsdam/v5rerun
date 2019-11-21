using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Lmotor;
extern motor Rmotor;
extern motor_group Lift;
extern motor LiftL;
extern motor LiftR;
extern motor Claw;
extern motor_group Bottom;
extern motor BottomL;
extern motor BottomR;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );