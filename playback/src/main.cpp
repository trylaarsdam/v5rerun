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
uint8_t     myTestData[15000];
uint8_t     myReadBuffer[15000];
int nWritten = 0;
int main() {
    // set the test data to something detectable
    // write test data to SD Card
    vex::task::sleep(1000);
    /*for(int i=0;i<999;i++)
    {
      myTestData[1] = (Controller1.Axis3.position(percent));
      myTestData[2] = (Controller1.Axis2.position(percent));
      myTestData[3] = (Controller1.ButtonL1.pressing() * 100);
      nWritten = Brain.SDcard.appendfile( "test.txt", myTestData, sizeof(myTestData) );
      vex::task::sleep(15);
    }
    myTestData[1] = (Controller1.Axis3.position(percent));
    myTestData[2] = (Controller1.Axis2.position(percent));
    myTestData[3] = (Controller1.ButtonL1.pressing() * 100);
    //Brain.SDcard.savefile( "test.h", myTestData, sizeof(myTestData) );
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
            Brain.Screen.print("%f ", (float)myReadBuffer[i]);
    }
    else {
        Brain.Screen.printAt( 10, 40, "Error writing to the SD Card" );        
    }*/
    int nRead = Brain.SDcard.loadfile( "test.txt", myReadBuffer, sizeof(myReadBuffer) );
    for(int i=0;i<1000;i++)
    {
      Lmotor.spin(fwd, (float)myReadBuffer[1], pct);
      Rmotor.spin(vex::directionType::fwd, (float)myReadBuffer[2], vex::percentUnits::pct);
      Lift.spin(vex::directionType::fwd, (float)myReadBuffer[3], vex::percentUnits::pct);
      vex::task::sleep(15);
    }
}