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
// Drivetrain           drivetrain    1, 10           
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// storage for some information to save
uint8_t     myTestData[100];
uint8_t     myReadBuffer[ 1000 ];

int main() {
    // set the test data to something detectable
    // write test data to SD Card
    vex::task::sleep(1000);
    myTestData[0] = (uint8_t)(Controller1.Axis3.position(percent)); //cast to 1 byte
    Brain.Screen.setCursor( 9, 2 );
    for(int i=0;i<8;i++){
            Brain.Screen.print("%i ", myTestData[i]);
    }
    //Brain.SDcard.savefile( "test.h", myTestData, sizeof(myTestData) );
    int nWritten = Brain.SDcard.savefile( "test.txt", myTestData, sizeof(myTestData) );

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
    Drivetrain.driveFor((double)myReadBuffer[0], inches);
}