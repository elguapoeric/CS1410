//																			Eric Tinajero
//																			CS 1410 - Online
//																			Dr. Rague
//																			Due: 07/24/2016
//																			Version: 1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// This program takes in two fractions and can add, subtract, multiply, or divide the two fractions.  The fractions
//by default are set to 1/1 if the user does not choose to add in there own fractions.

#include <iostream>					
#include <iomanip>
#include <cmath>

using namespace std;			

class Rational									//class representing a fraction
{
private:										//Declaring private variables and functions
	int numerator;
	int denominator;
	Rational Normalize(Rational result);
	Rational Reduce(Rational result);
	
	
public:										//Public functions that will be used in main
	Rational(int num, int den);
	Rational();
	void Input();
	void Display();
	void DisplayFlo();
	Rational Add(Rational rhs);
	Rational Subtract(Rational rhs);
	Rational Multiply(Rational rhs);
	Rational Divide(Rational rhs);
};

Rational::Rational(int num, int den)	//Constructor to set private variables
{
	numerator = num;
	denominator = den;
}

Rational::Rational()				//Constructor default is set to 1/1
{
	numerator = 1;
	denominator = 1;
}

void Rational::Input()				//Will ask the user initialize the numerator and denominator by entering a fraction
{
	int num;
	int den;
	char s;

	do
	{
		cout << "\nPlease enter a fraction in 'Num/Den' (Num and Den are integers) format: ";
		cin >> num >> s >> den;
		if (den == 0)
		{
			cout << "\nCannot have a 0 in the denominator" << endl;
		}

	} while (den == 0);

	numerator = num;
	denominator = den;
}

Rational Rational::Normalize(Rational result)			//This fucntion will move the negative sign around to normalize the fraction depending on its location if both numerator and denominator contain a negative then it will remove both
{	
	if (result.numerator > 0 && result.denominator < 0)
	{
		result.numerator = -1 * result.numerator;
		result.denominator = -1 * result.denominator;
	}
	else if (result.numerator < 0 && result.denominator < 0)
	{
		result.numerator = -1 * result.numerator;
		result.denominator = -1 * result.denominator;
	}
	return result;
}

Rational Rational::Reduce(Rational result)				//This will use the greatest common divisor to reduce the fraction
{
	Rational equals;
	int top = abs(result.numerator);
	int bot = abs(result.denominator);
	if (top == 0)										//Added an exception in case the numerator is 0
	{
		equals.denominator = result.denominator;
		equals.numerator = result.numerator;
	}
	else if (bot == 1)									//Added an exception in casethe numerator is 1 already
	{
		equals.denominator = result.denominator / 1;
		equals.numerator = result.numerator / 1;
	}
	else if (top >=1 && bot >=1)
	{
		while (top != bot)
		{
			if (top > bot)
			{
				top = top - bot;
			}
			else
			{
				bot = bot - top;
			}
		}
		equals.denominator = result.denominator / top;
		equals.numerator = result.numerator / top;
	}
	return equals;
}

void Rational::Display()							//Display the fraction in n/d form
{
	cout << numerator << "/" << denominator;
}

void Rational::DisplayFlo()
{	
	double deci;
	deci = (double)numerator / denominator;
	cout << fixed << setprecision(3)<<deci;
}

Rational Rational::Add(Rational rhs)				//Will add to fractions and reduce and normalize the result
{
	Rational result;
	result.numerator = (numerator * rhs.denominator) + (denominator *rhs.numerator);
	result.denominator = denominator * rhs.denominator;
	result = Normalize(result);
	result = Reduce(result);
	return result;
}

Rational Rational::Subtract(Rational rhs)		//Will subtract two fractions and reduce and normalize the result
{
	Rational result;
	result.numerator = numerator * rhs.denominator - denominator*rhs.numerator;
	result.denominator = denominator * rhs.denominator;
	result = Normalize(result);
	result = Reduce(result);
	return result;
}

Rational Rational::Multiply(Rational rhs)		//Will mulitply two fractions and reduce and normalize the result
{
	Rational result;
	result.numerator = numerator * rhs.numerator;
	result.denominator = denominator * rhs.denominator;
	result = Normalize(result);
	result = Reduce(result);
	return result;
}

Rational Rational::Divide(Rational rhs)			//Will divide two fractions and reduce and noramlize the result
{
	Rational result;
	result.numerator = numerator * rhs.denominator;
	result.denominator = denominator*rhs.numerator;
	result = Normalize(result);
	result = Reduce(result);
	return result;
}


int main()									//main
{
	Rational frac1;							//Objects used for calculations
	Rational frac2;
	Rational frac3;
	int select;								//variable used for menu selection
	int quit = 1;							//variable used to end the program
	
	//Prompt user to for inputs
	cout << "This program takes in two fractions and adds, subtracts, multiplies, or divides the the two and shows the result."<<endl;
	cout << "Please select from one of the choices below.\n" << endl;
	
	do                                     //This loop will end the program when the user selects 6 which will change quit to 0
	{
		do                                //This loop will  make sure the user enters a number 1-6
		{
			cout << "\n\t\t\t\t1. Input two fractions" << endl;
			cout << "\t\t\t\t2. Add and display result" << endl;
			cout << "\t\t\t\t3. Subtract and display result" << endl;
			cout << "\t\t\t\t4. Multiply and Display result" << endl;
			cout << "\t\t\t\t5. Divide and display result" << endl;
			cout << "\t\t\t\t6. Quit\n" << endl;
			cout << "\t\t\t\tSelection Choice: ";
			cin >> select;
			
			if (select < 1 || select > 6)
			{
				cout << "\n\t\t\t\tSorry not a valid choose between 1 and 6.\n"<< endl;
			}
		
		} while (select < 1 &&  select > 6);
		
		//User selections 
		if (select == 1)
		{
			cout << "Fraction1";
			frac1.Input();
			cout << "Fraction2";
			frac2.Input();
		}
		else if (select == 2)	//Performs Addition
		{	
			frac3 = frac1.Add(frac2);
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " + "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 3)	//Perfroms Subtraction
		{
			frac3 = frac1.Subtract(frac2);
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " - "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 4)	//Performs Multiply
		{
			frac3 = frac1.Multiply(frac2);
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " * "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 5)	//Perfroms Divide
		{
			frac3 = frac1.Divide(frac2);
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " / "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 6)	//Quits the program
		{
			cout << "\nThanks for using the Fractions program \n";
			quit = 0;
		}
	} while (quit == 1);
	
	return 0;		//End

}




