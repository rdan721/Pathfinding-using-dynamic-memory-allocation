/*	Programmer: Dan Reed  // 12/10/2014
	Class: CS 1510  // Section A
	Filename: heist.cpp
	Purpose: This program simulates a scenario where Bender from Futurama 
	performs a heist and must then find the exit to a maze laden with traps. 
	It is designed to take in a rectangular map of characters. It first takes 
	in the width and height of the map, and then the map itself as input. An 
	unlimited number of maps can be input as long as they end in 0 0 to signal 
	the programs end. The maps initially consist of walls '#', bender 'B', 
	open space ' ', traps 'T', and the exit 'E'. The program uses the map 
	class to pathfind from the location of bender to the exit using a greedy 
	recursive algorithm. 

*/

#include "map.h"
#include <iostream>
using namespace std;

int main()
{   // Variable Declarations
	int rows = 1;
	int cols = 1;
	char object;
	int counter =0;
	int bender_row;
	int bender_col;

	while(rows!=0 && cols!=0)
	{
		cin >> cols;
		cin >> rows;

		if(rows!=0 && cols!=0)
		{
			Map bank_map(cols,rows);
			for(int j=0; j<rows; j++) // arranges the row index j
			{
				for(int i=0; i<cols; i++) // and the column index i
				{	
					cin.get(object);  // so that when a characte ris obtained
					if(object=='\n')
						cin.get(object);
					bank_map.bank[i][j]=object; // it can be written to the 
					if(object=='B')				// appropriate spot in the 
					{							// map
						bender_row=j;
						bender_col=i;
					}
				}
			}
			bank_map.pathfind(bender_col, bender_row); // find path
			cout << endl;
			cout << "Map : " << counter << endl;
			bank_map.print(); 						   // print path
			counter++;
		}
	}
	cout << endl;
	return 0;
}

/* Compiling Notes
in command window:

g++ heist.cpp
a < sampleinput.txt > output.txt
*/
