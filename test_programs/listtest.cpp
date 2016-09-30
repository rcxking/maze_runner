/*
 * listtest.cpp
 *
 * This program tests the custom-made template list.h data structure.
 *
 * Bryant Pong
 * 9/25/16
 *
 * Last Updated: 9/29/16   
 */

// Custom Includes:
#include "../src/list.h"
#include <iostream>
#include <cassert>

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

	assert( intList.size() == 5 );

	intList.pop_back();

	assert( intList.size() == 4 );

	// Iterate through the list and print out the results:
	std::cout << "Now printing out intList" << std::endl;
	List<int>::iterator itr; 
	for( itr = intList.begin(); itr != intList.end(); ++itr )
	{
		std::cout << *itr << std::endl;
	}

	// Create a second list to test the push_front capability:
	List<int> intList2( intList );

	// Iterate through the list and print out the results (expecting: 1-2-3-4-5):
	std::cout << std::endl << "Now printing out intList2" << std::endl;
	for( itr = intList2.begin(); itr != intList2.end(); ++itr )
	{
		std::cout << *itr << std::endl;
	}

	assert( intList2.size() == 4 );

	return 0;
}
