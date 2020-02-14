/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Clawbot Template (Drivetrain, No Gyro)                    */
/*                                                                            */
/*    Name:                                                                   */
/*    Date:                                                                   */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Lmotor               motor         2               
// Rmotor               motor         10              
// Lift                 motor         8               
// Claw                 motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// storage for some information to save
uint32_t loopCount = 12*1000;
uint8_t     myTestData[15000];
uint8_t     myReadBuffer[15000];
int nWritten = 0;
int main() {
    // set the test data to something detectable
    // write test data to SD Card
        // now read it back into a different buffer
        int nRead = Brain.SDcard.loadfile( "test.txt", myReadBuffer, sizeof(myReadBuffer) );

        // display on screen how many bytes we read
        Brain.Screen.setCursor( 3, 2 );
        Brain.Screen.print( "We read %d bytes from the SD Card", nRead );

        // and display some of the data
        Brain.Screen.setCursor( 6, 2 );
        for(int i=0;i<8;i++)
            Brain.Screen.print("%i ", myReadBuffer[i]);

    for(int i=0;i<loopCount;i=i+3)
    {
      if((int)myReadBuffer[i+0] < 101){
        Lmotor.spin(forward, (int)myReadBuffer[i+0], pct);
      }
      else if((int)myReadBuffer[i+0] >= 101){
        Lmotor.spin(forward, -((float)myReadBuffer[i+0] - 100), pct);
      }
      //else{
      //  Lmotor.stop();
      //}

      if((int)myReadBuffer[i+1] < 101){
        Rmotor.spin(forward, (int)myReadBuffer[i+1], pct);
      }
      else if((int)myReadBuffer[i+1] > 100){
        Rmotor.spin(forward, -((float)myReadBuffer[i+1] - 100), pct);
      }
      //else {
      //  Rmotor.stop();
      //}

      if((int)myReadBuffer[i+2] == 100){
        Lift.spin(forward, -100, pct);
      }
      else if((int)myReadBuffer[i+2] == 200){
        Lift.spin(forward, 100, pct);
      }
      else{
        Lift.stop(brakeType::brake);
      }
      //else {
        //Lift.stop(brakeType::brake);
      //}      
      vex::task::sleep(15);
      Lmotor.stop();
      Rmotor.stop();

    }
/* Arm Claw Thing and Stuff */