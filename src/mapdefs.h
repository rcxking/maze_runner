/*
 * mapdefs.h
 *
 * This header file defines structures used to represent
 * the maze.
 *
 * Bryant Pong
 * 9/16/16 
 */

#ifndef _MAPDEFS_H_
#define _MAPDEFS_H_

/***** STRUCTURES *****/

// Representation of a point on the internal map: 
typedef struct Point {
	int x;
	int y;
	
	// Constructor for a point:
	Point( int x_, int y_ ) : x( x_ ), y( y_ ) {}		
} Point;
/***** END SECTION STRUCTURES *****/
#endif
