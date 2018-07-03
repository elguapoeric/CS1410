//																			Eric Tinajero
//																			CS 1410 - Online
//																			Dr. Rague
//																			Due: 07/10/2016
//																			Version: 1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//This programs has the user enter the three lengths of a triangle and identifies the type of triangle based on those lengths.
//
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double side1;		//Length of side 1
	double side2;		//Length of side 2
	double side3;		//Length of side 3
	double s1Sq;		//square of side 1
	double s2Sq;		//square of side 2
	double s3Sq;		//square of side 3 
	bool sFail;			//Variable used to check user input

	//Introduce user to program and rules
	cout << "Welcome to the Triangle Identifier this program identifies the type of triangle based on lengths of each side of the triangle" << endl;
	cout << "There are a few rules enter a postive real number for each side.  If you would like to end the program, enter zero for all" << endl;
	cout << "three lengths. ";
	cout << "Please enter the lengths of each side of the triangle." << endl;
	
	//Sticking statements inside a do loop that will terminate upon entering 0 for all three sides
	do 
	{
		//Receive user input and add user input checks for side1
		do                                                         
		{
			cout << "Side 1: ";
			cin >> side1;
			sFail = cin.fail();
			if (sFail)
			{
				cout << "Not a real number"<<endl;
			}
			else if (side1 < 0)
			{
				cout << "Not a positive number"<<endl;
			}
			else if (side1 == 0)
			{
				cout << "Entering 0 for all three sides will end the program" << endl;
			}
			cin.clear();
			cin.ignore(100, '\n');

		} while (sFail == true || side1<0);
		
		//Receive user input and add user input check for side2
		do                                                         
		{
			cout << "Side 2: ";
			cin >> side2;
			sFail = cin.fail();
			if (sFail)
			{
				cout << "Not a real number" << endl;
			}
			else if (side2 < 0)
			{
				cout << "Not a positive number" << endl;
			}
			else if (side2 == 0)
			{
				cout << "Entering 0 for all three sides will end the program" << endl;
			}
			cin.clear();
			cin.ignore(100, '\n');

		} while (sFail == true || side2<0);

		//Receive user input and add user input check for side3
		do                                                          
		{
			cout << "Side 3: ";
			cin >> side3;
			sFail = cin.fail();
			if (sFail)
			{
				cout << "Not a real number" << endl;
			}
			else if (side3 < 0)
			{
				cout << "Not a positive number." << endl;
			}
			else if (side3 == 0)
			{
				cout << "Entering 0 for all three sides will end the program" << endl;
			}
			cin.clear();
			cin.ignore(100, '\n');

		} while (sFail == true || side3<0);
		
		//Calculate the square of each side 
		s1Sq = pow(side1, 2);
		s2Sq = pow(side2, 2);
		s3Sq = pow(side3, 2);

		//Create the conditions for identifying the triangle type
		if ((side1 + side2) <= side3 || (side1 + side3) <= side2 || (side2 + side3) <= side1)		//Conditions for invalid triangle
		{
			cout << side1 << " " << side2 << " " << side3 << " does not form a triangle."<<endl;
		}
		else if (side1 == side2 && side1 == side3)													//Conditions for equalateral triangle
		{
			cout << side1 << " " << side2 << " " << side3 << " form an equalateral triangle."<<endl;
		}
		else if (side1 == side2 || side1 == side3 || side2 == side3)								//Conditions for isosceles triangle
		{
			cout << side1 << " " << side2 << " " << side3 << " form an isosceles triangle."<<endl;
		}
		else if ((s1Sq + s2Sq) == s3Sq || (s1Sq + s3Sq) == s2Sq || (s2Sq + s3Sq) == s1Sq)			//Conditions for right triangle
		{
			cout << side1 << " " << side2 << " " << side3 << " form a right triangle."<<endl;
		}
		else
		{
			if ((s1Sq > s2Sq && s1Sq > s3Sq && s1Sq <= (s2Sq + s3Sq)) || (s2Sq > s1Sq && s2Sq > s3Sq && s2Sq <= (s1Sq + s3Sq)) || (s3Sq > s1Sq && s3Sq > s2Sq && s3Sq <= (s1Sq + s2Sq)))	//Actute triangle conditions
			{
				cout << side1 << " " << side2 << " " << side3 << " form an acute triangle"<<endl;
			}
			else if ((s1Sq > s2Sq && s1Sq > s3Sq && s1Sq > (s2Sq + s3Sq)) || (s2Sq > s1Sq && s2Sq > s3Sq && s2Sq > (s1Sq + s3Sq)) || (s3Sq > s1Sq && s3Sq > s2Sq && s3Sq > (s1Sq + s2Sq)))	//Obtuse triangle conditions
			{
				cout << side1 << " " << side2 << " " << side3 << " form an obtuse triangle"<<endl;
			}
		}
	} while (side1 != 0 || side2 != 0 || side3 != 0);

	return 0; //end main 
}


