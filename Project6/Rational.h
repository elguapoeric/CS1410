#ifndef Rational_h_
#define Rational_h_
#include <iostream>					
#include <iomanip>

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
	friend ostream& operator<<(ostream& os, Rational& rhs); //friend function
	friend istream& operator >> (istream& is, Rational& rhs);
	class ZeroDen {};
	class Alpha {};
};
#endif