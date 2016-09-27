/*
 * listtest.cpp
 *
 * This program tests the custom-made template list.h data structure.
 *
 * Bryant Pong
 * 9/25/16
 *
 * Last Updated: 9/26/16   
 */

// Custom Includes:
#include "../src/list.h"
#include <iostream>

// Main function:
int main()
{
	// Create an integer linked list:
	List<int> intList; 
	intList.push_back( 1 );
	intList.push_back( 2 ); 	
	intList.push_back( 3 );
	intList.push_back( 4 );
	intList.push_back( 5 );

	// Iterate through the list and print out the results:
	std::cout << "Now printing out intList" << std::endl;
	List<int>::iterator itr; 
	for( itr = intList.begin(); itr != intList.end(); ++itr )
	{
		std::cout << *itr << std::endl;
	}

	return 0;
}
