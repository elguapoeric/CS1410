//																			Eric Tinajero
//																			CS 1410 - Online
//																			Dr. Rague
//																			Due: 07/03/2016
//																			Version: 1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//This programs creates a pyramid that is composed of spaces and X's that is twenty rows high.
//
#include "stdafx.h"
#include<iostream>

using std::cout;	//Program uses cout
using std::cin;		//Program uses cin
using std::endl;	//Program uses endl

int main()
{
	int numXs;		//Represents the number of X's in each row
	int start;		//This variable will represent the number of spaces from the left side of cmd for each row.
					
	for(int rows=1; rows<=20; rows++)		//This loop will represent each row in the pyramid
	{
		start = (20 - rows);				//Since the base of the pyramid takes up 39 X's I need to put in at least 19 spaces for the peak of the pyramid, then subtract
											//one space for every row entered after.
		
		for (int spaces = 1; spaces <= start; spaces++)		//This loop will create the spaces needed for each row
		{
			cout << " ";
		}
		int numXs = 2 * rows - 1;
		for (int x=1; x <= numXs; x++)					//This loop will create the X's needed for each row
		{
			cout << "X";
			
		}
		
		cout << endl;										//Move to the next line
	}
    return 0;
}//End funtion main

