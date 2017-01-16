/*	Programmer: Dan Reed  // Due: 12/10/2014
	Class: CS 1510  // Section A
	Filename: map.hpp
	Purpose: Function definitions for the map class
*/

using namespace std;
#include <iostream>

Map::Map(int x, int y)
{
	num_cols = x;
	num_rows = y;

	move[0][0]=0;
	move[1][0]=1; // x right
	move[2][0]=0;
	move[3][0]=-1;// x left
	move[0][1]=1; // y down
	move[1][1]=0;
	move[2][1]=-1;// y up
	move[3][1]=0;

	bank = new char*[x]; // allocating bank map
	for(int i=0; i<x; i++)
		bank[i] = new char[y]; // fills array with pointers to int arrays
}

Map::~Map() // destructor
{
	for(int i=0; i<num_cols; i++)
		delete[] bank[i]; // deallocating map
	delete[] bank;
	bank=NULL;

	return;
}

void Map::print()
{
	for(int j=0; j<num_rows; j++) // for each row
	{
		for(int i=0; i<num_cols; i++) // look at each character
		{
			cout << bank[i][j]; // and output it
			if(i==num_cols-1)
				cout << endl;
		}
	}
	return;
}

bool Map::pathfind(const int x, const int y)
{	// Variables Declaration:
	int x_new, y_new; // the new coordinates to be tried 
	bool isSolved; // 
	for(int m=0; m<4; m++) // down right up left
	{
		x_new = x + move[m][0]; // create new coordinates
		y_new = y + move[m][1];
		// check if not trap, not wall, not loop, not start, and in bounds
		if(bank[x_new][y_new]!='#' && bank[x_new][y_new]!='T'
		&& bank[x_new][y_new]!='.' &&  bank[x_new][y_new]!='B'
		&& x_new >= 0 && y_new >= 0 && x_new < num_cols && y_new < num_rows)
		{	// if success
			if(bank[x_new][y_new]=='E') 
				return true;
			else
			{ 	// mark path and try next move
				bank[x_new][y_new]='.';
				isSolved=this->pathfind(x_new,y_new);
				if(isSolved) 	// pass success to calling function if success
					return true;// found be the called function
				else
				{	
					bank[x_new][y_new]=' '; // pretend mistakes never happened
				}							// hehe
			}
		}
	}
	return false; // return false if no direction from (x,y) led to exit
}








