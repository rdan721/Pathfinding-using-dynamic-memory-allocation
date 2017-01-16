/*	Programmer: Dan Reed  // Due: 12/10/2014
	Filename: map.h
	Purpose: Header file for the map class. 
	Note: 'B' represents the position of bender, who is trying to exit
	the maze.
*/

#ifndef MAP_H
#define MAP_H

#include <string>

using namespace std;

class Map
{
public:
	int num_rows;
	int num_cols;
	char** bank; // the map: dynamically allocated character array 
	int move[4][2]; // the movements allowed for pathfind

	// Description: Constructor. Allocates an empty map (a 2D character 
	// 	 array) of width x and height y. 
	// Post: Allocates 2D array pointed to by bank. Assigns values to move
	// 	 so that an (x,y) coordinate can be moved up, down, left, or right
	Map(int x, int y);

	// Description: Destructor
	// Post: Memory pointed to by bank is deallocated, bank is NULL
	~Map();

	// Description: Finds a path from 'B' to 'E' on bank (assuming one exists)
	//   The path is indicated by '.' characters.
	// Pre: (x,y) is a coordinate within the bank map
	// Post: modifies the bank map
	bool pathfind(const int x, const int y);

	// Description: Prints the bank map
	// Pre: The map characters have been filled in. It will still work
	//   otherwise, but will print the random contents of the array memory.
	// Post: Outputs the map line by line.
	void print();

}; 
#include "map.hpp"
#endif 
