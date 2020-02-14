using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FLdrive;
extern motor FRdrive;
extern motor_group DR4B;
extern motor clawMotor;
extern motor_group intake;
extern motor liftMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );