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
// Lmotor               motor         1               
// Rmotor               motor         10              
// Lift                 motor         8               
// Claw                 motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// storage for some information to save
uint32_t loopCount = 3*1000;
uint8_t     myTestData[15000];
uint8_t     myReadBuffer[15000];
int nWritten = 0;
int main() {
    // set the test data to something detectable
    // write test data to SD Card
    vex::task::sleep(1000);
    for(int i=0;i<loopCount;i=i+3)
    {
      myTestData[i+0] = (uint8_t)(Controller1.Axis3.position(percent));
      myTestData[i+1] = (uint8_t)(Controller1.Axis2.position(percent)); //fill array with all info, then write buffer
      myTestData[i+2] = (uint8_t)(Controller1.ButtonL1.pressing() * 100);
     // nWritten = Brain.SDcard.appendfile( "test.txt", myTestData, sizeof(myTestData) );
      vex::task::sleep(15);
    }
    nWritten = Brain.SDcard.savefile( "test.txt", myTestData, sizeof(myTestData) );

    // did that work ?
    if( nWritten > 0) {
        // display on screen how many bytes we wrote
        Brain.Screen.setCursor( 2, 2 );
        Brain.Screen.print( "We wrote %d bytes to the SD Card", nWritten );

        // now read it back into a different buffer
        int nRead = Brain.SDcard.loadfile( "test.txt", myReadBuffer, sizeof(myReadBuffer) );

        // display on screen how many bytes we read
        Brain.Screen.setCursor( 3, 2 );
        Brain.Screen.print( "We read %d bytes from the SD Card", nRead );

        // and display some of the data
        Brain.Screen.setCursor( 6, 2 );
        for(int i=0;i<8;i++)
            Brain.Screen.print("%i ", myReadBuffer[i]);
    }
    else {
        Brain.Screen.printAt( 10, 40, "Error writing to the SD Card" );        
    }
    for(int i=0;i<1000;i++)
    {
      Lmotor.spin(fwd, (float)myReadBuffer[0], pct);
      Rmotor.spin(fwd, (float)myReadBuffer[1], pct);
      Lift.spin(fwd, (float)myReadBuffer[2], pct);
      vex::task::sleep(15);
    }
}