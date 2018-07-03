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
	void Normalize();
	void Reduce();


public:										//Public functions that will be used in main
	Rational(int num, int den);
	Rational();
	void Input();
	void Display();
	void DisplayFlo();
	Rational Add(Rational rhs);
	Rational operator+(Rational rhs);
	Rational Subtract(Rational rhs);
	Rational operator-(Rational rhs);
	Rational Multiply(Rational rhs);
	Rational operator*(Rational rhs);
	Rational Divide(Rational rhs);
	Rational operator/(Rational rhs);
	bool Equals(Rational rhs);
	bool operator==(Rational rhs);
	bool Less(Rational rhs);
	bool operator<(Rational rhs);
	bool Greater(Rational rhs);
	bool operator>(Rational rhs);
};

Rational::Rational(int num, int den)	//Constructor to set private variables
{
	if (den == 0)
	{
		denominator = 1;
		cout << "Denominator was set to zero so changed to 1";
	}
	else
	{
		denominator = den;
	}

	numerator = num;
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

void Rational::Normalize()			//This fucntion will move the negative sign around to normalize the fraction depending on its location if both numerator and denominator contain a negative then it will remove both
{
	if (numerator > 0 && denominator < 0)
	{
		numerator = -1 * numerator;
		denominator = -1 * denominator;
	}
	else if (numerator < 0 && denominator < 0)
	{
		numerator = -1 * numerator;
		denominator = -1 * denominator;
	}
}

void Rational::Reduce()				//This will use the greatest common divisor to reduce the fraction
{
	int top = abs(numerator);
	int bot = abs(denominator);
	if (top == 0)										//Added an exception in case the numerator is 0
	{
		denominator = denominator;
		numerator = numerator;
	}
	else if (bot == 1)									//Added an exception in casethe numerator is 1 already
	{
		denominator = denominator;
		numerator = numerator;
	}
	else if (top >= 1 && bot >= 1)
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
		denominator = denominator / top;
		numerator = numerator / top;
	}
}

void Rational::Display()							//Display the fraction in n/d form
{
	cout << numerator << "/" << denominator;
}

void Rational::DisplayFlo()
{
	double deci;
	deci = (static_cast<double> (numerator)) / denominator;
	cout << fixed << setprecision(3) << deci;
}

Rational Rational::Add(Rational rhs)				//Will add to fractions and reduce and normalize the result
{
	Rational result;
	result.numerator = (numerator * rhs.denominator) + (denominator *rhs.numerator);
	result.denominator = denominator * rhs.denominator;
	result.Reduce();
	result.Normalize();
	return result;
}

Rational Rational::operator+(Rational rhs)		//Overloading + operator
{
	Rational result;
	result = Add(rhs);
	return result;
}

Rational Rational::Subtract(Rational rhs)		//Will subtract two fractions and reduce and normalize the result
{
	Rational result;
	result.numerator = numerator * rhs.denominator - denominator*rhs.numerator;
	result.denominator = denominator * rhs.denominator;
	result.Reduce();
	result.Normalize();

	return result;
}

Rational Rational::operator-(Rational rhs)		//Overloading - operator
{
	Rational result;
	result = Subtract(rhs);
	return result;
}

Rational Rational::Multiply(Rational rhs)		//Will mulitply two fractions and reduce and normalize the result
{
	Rational result;
	result.numerator = numerator * rhs.numerator;
	result.denominator = denominator * rhs.denominator;
	result.Reduce();
	result.Normalize();
	return result;
}

Rational Rational::operator*(Rational rhs)		//Overloading * operator
{
	Rational result;
	result = Multiply(rhs);
	return result;
}

Rational Rational::Divide(Rational rhs)			//Will divide two fractions and reduce and noramlize the result
{
	Rational result;
	result.numerator = numerator * rhs.denominator;
	result.denominator = denominator*rhs.numerator;
	result.Reduce();
	result.Normalize();
	return result;
}

Rational Rational::operator/(Rational rhs)		//Overloading / operator
{
	Rational result;
	result = Divide(rhs);
	return result;
}

bool Rational::Equals(Rational rhs)				//Will check if two fractions are equal return true or false
{
	double frac1;
	double frac2;
	bool result = false;
	frac1 = (static_cast<double> (numerator)) / denominator;
	frac2 = (static_cast<double> (rhs.numerator)) / rhs.denominator;
	if (frac1 == frac2)
	{
		result = true;
	}
	return result;
}
bool Rational::operator==(Rational rhs)			//Overloading == operator
{
	bool result;
	result = Equals(rhs);
	return result;

}
bool Rational::Less(Rational rhs)				//Will check if first fraction is less than the second fraction
{
	double frac1;
	double frac2;
	bool result = false;
	frac1 = (static_cast<double> (numerator)) / denominator;
	frac2 = (static_cast<double> (rhs.numerator)) / rhs.denominator;
	if (frac1 < frac2)
	{
		result = true;
	}
	return result;
}
bool Rational::operator<(Rational rhs)			//Overloading < operator
{
	bool result;
	result = Less(rhs);
	return result;
}
bool Rational::Greater(Rational rhs)			//Will check if first fraction is greater than the second fraction
{
	double frac1;
	double frac2;
	bool result = false;
	frac1 = (static_cast<double> (numerator)) / denominator;
	frac2 = (static_cast<double> (rhs.numerator)) / rhs.denominator;
	if (frac1 > frac2)
	{
		result = true;
	}
	return result;
}
bool Rational::operator>(Rational rhs)		//Overloading > operator
{
	bool result;
	result = Greater(rhs);
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
	cout << "This program takes in two fractions and adds, subtracts, multiplies, or divides the the two and shows the result." << endl;
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
				cout << "\n\t\t\t\tSorry not a valid choose between 1 and 6.\n" << endl;
			}

		} while (select < 1 && select > 6);

		//User selections 
		if (select == 1)
		{
			cout << "Fraction1";
			frac1.Input();
			cout << "Fraction2";
			frac2.Input();
			bool eql = false;
			bool equalLess = false;
			bool equalGreater = false;
			eql = frac1 == frac2;						//Using overloaded operators to check equalities
			equalLess = frac1 < frac2;
			equalGreater = frac1 > frac2;

			if (eql)
			{
				cout << "\nFraction1 is equal to Fraction2!\n";
			}
			else if (equalLess)
			{
				cout << "\nFraction1 is less than Fraction2!\n";
			}
			else if (equalGreater)
			{
				cout << "\nFraction1 is greater than Fraction2!\n";
			}

		}
		else if (select == 2)	//Performs Addition
		{
			frac3 = frac1 + frac2;
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " + "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 3)	//Perfroms Subtraction
		{
			frac3 = frac1 - frac2;
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " - "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 4)	//Performs Multiply
		{
			frac3 = frac1 * frac2;
			cout << "\n\t\t\t\t";  frac1.Display(); cout << " * "; frac2.Display(); cout << " = "; frac3.Display(); cout << " or "; frac3.DisplayFlo(); cout << "\n\n";
		}
		else if (select == 5)	//Performs Divide
		{
			frac3 = frac1 / frac2;
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
