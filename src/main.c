/*
 * main.cpp
 *
 * This is the maze runner program for the Homebrew Robotics Club
 * Maze Challenge.
 *
 * This code is designed to run on a Pololu 3pi robot.
 *
 * Bryant Pong
 * 8/28/16
 *
 * Last Updated: 9/16/16
 */

// 3rd Party Libraries:
#include <pololu/3pi.h> // 3 pi library
#include <avr/pgmspace.h> // For accessing values in FLASH

// Custom Libraries:
#include "list.h" // Custom Linked List class
//#include <queue>

/***** CONSTANTS/GLOBALS/ENUMERATIONS *****/

/*
 * Strings for displaying information to user.  These are stored
 * in flash to avoid taking up space in RAM.
 */
const char intro_line1[] PROGMEM = "Maze";
const char intro_line2[] PROGMEM = "Solver";  
const char calib_line1[] PROGMEM = "Calib.";
const char calib_line2[] PROGMEM = "Sensors";

/*
 * Sounds for debugging.   
 */
const char beep[] PROGMEM = ">g32>>c32";

/*
 * The type of junction that the robot has encountered.
 * From the HBRC rules, these are as follows:
 * 
 * 1) Maze's End
 * 2) Plus (+)    
 * 3) Tee ( T )
 * 4) Left 90 Degree Turn
 * 5) Right 90 Degree Turn
 * 6) Straight Line  
 */
enum JUNCTION_TYPES
{
	MAZE_END=0,
	PLUS,
	TEE,
	LEFT_TURN,
	RIGHT_TURN,
	STRAIGHT	
};
/***** END SECTION CONSTANTS *****/ 

/***** FUNCTION PROTOTYPES *****/
void Display2Lines( const char *line1, const char *line2 );
void OnForXMSecs( const int leftPower, const int rightPower, const int millisecs ); 
void InitializeRobot();
void CalibrateLineSensors();
void PerformMappingRun();
void PerformActualRun();
enum JUNCTION_TYPES DetermineJunctionType(); 
/***** END SECTION FUNCTION PROTOTYPES *****/

/*
 * This helper function displays two lines of text
 * for 1 second before clearing the screen. 
 */
void Display2Lines( const char *line1, const char *line2 )
{
	print_from_program_space( line1 );
	lcd_goto_xy( 0, 1 );
	print_from_program_space( line2 );
	play_from_program_space( beep );
	delay( 1000 );
	clear();
}

/*
 * This function sets the motors to run at their specified
 * speeds for the given number of milliseconds.  
 */
void OnForXMSecs( const int leftPower, const int rightPower,
                  const int millisecs )
{
	set_motors( leftPower, rightPower );
	delay_ms( millisecs );
	set_motors( 0, 0 );
}

/*
 * This helper function spins the robot in place
 * by 45 degrees so the line sensors can calibrate.       
 */
void CalibrateLineSensors()
{
	// Display a message for beginning calibration:
	Display2Lines( calib_line1, calib_line2 );

	// Wait for the user to press the B Button before moving:
	while( !button_is_pressed( BUTTON_B ) )
	{
		clear();
		print( "Press B" );
		delay_ms( 100 );
	}

	// Wait for the user to release the B Button before spinning to calibrate:
	wait_for_button_release( BUTTON_B );
	delay( 1000 );
	clear();

	// The amount to spin:
	const int SPIN_SPEED = 30;

	set_motors( SPIN_SPEED, -1 * SPIN_SPEED );
				
}

/*
 * This function initializes the 3pi.  This includes
 * displaying the welcome message, initializing the sensors
 * etc.     
 */
void InitializeRobot()
{
	// Initialize the 3pi sensors:
	pololu_3pi_init( 2000 );     

	// Display the "Maze Solver" message:
	Display2Lines( intro_line1, intro_line2 );

	/*
	 * Check that the battery levels are acceptable.  The
	 * 3pi uses 4 AAA batteries (at 1.5 Volts a piece). 
	 *   
	 */

	// Finally, spin in place and calibrate the line sensors:
	CalibrateLineSensors();
}

// Main function:
int main()
{
	// Initialize the 3pi
	InitializeRobot();
	return 0;
}
