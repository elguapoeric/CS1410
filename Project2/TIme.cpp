//																			Eric Tinajero
//																			CS 1410 - Online
//																			Dr. Rague
//																			Due: 07/17/2016
//																			Version: 1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//This program asks the user for two times in military time format and then adds the two times then display the result in military time format again.
//
#include <iostream>
using namespace std;

struct Time					//Struct used for holding the time the users enters
{
	int Hours;
	int Minutes;
	int Seconds;
};

void Input_Time(Time&);			//Will prompt the user to enter the first time and return a stuct using a reference parameter
Time Input_Time();				//Will prompt the user to enter the second time and return a struct using the return statement
int Validate_Time(Time);		//Will check the time and return a -1 if the time is invalid or a zero if valid
void Display_Time(Time);		//This will print the time to the screen in the correct time format
long Time_To_Seconds(Time);		//Pass in the time in a struct and return the time converted converted to seconds
Time Seconds_To_Time(long);		//Pass in the time and in seconds as an integer and return Hours, Minutes, Seconds to a stuct
void Print_Zero(int);			//Print a zero in front of zero if its missing a zero in front of the time

int main()
{	//Give the user info about what the program does
	cout << "This program will ask the user to enter two times in military time format." << endl;
	cout << "It will then add the two times and display the result in military time." << endl;
	cout << "This program will run 50 cases before it terminates." << endl<< endl;
	
	int a = 1;
	
	//Run the program fifty times before it ends
	while (a <= 50)
	{
		//Define t1,t2,t3 as struct
		Time t1;
		Time t2;
		Time t3;

		Input_Time(t1);
		t2 = Input_Time();
		cout << endl;
		cout << "Case " << a << endl;
		cout << "\tTime 1: ";
		Display_Time(t1);
		cout << "\tTime 2: ";
		Display_Time(t2);
		cout << "\tResult: ";
		if (Validate_Time(t1) == -1 || Validate_Time(t2) == -1)			//Tell the user if the time is invalid
		{
			cout << "Invalid time was entered"<<endl << endl;
		}
		else if (Validate_Time(t1) == 0 && Validate_Time(t2) == 0)		//Display the sum of the time
		{
			long resultSecs;
			resultSecs = Time_To_Seconds(t1) + Time_To_Seconds(t2);
			t3 = Seconds_To_Time(resultSecs);
			Display_Time(t3);
			cout << endl;
		}
		a++;
	}
	return 0;	//End main
}
//Will prompt the user to enter the first time and return a stuct using a reference parameter
void Input_Time(Time& t)	
{	
	cout << "Enter a time in HH:MM:SS uses spaces instead of colons: ";
	cin >> t.Hours >> t.Minutes >> t.Seconds;
}

//Will prompt the user to enter the second time and return a struct using the return statement
Time Input_Time()		
{
	Time t2;
	cout << "Enter the second time in HH:MM:SS uses spaces instead of colons: ";
	cin >> t2.Hours >> t2.Minutes >> t2.Seconds;
	return t2;
}

//Will check the time and return a -1 if the time is invalid or a zero if valid
int Validate_Time(Time c)
{
	int val;
	if (c.Hours <= 23 && c.Hours >= 0 && c.Minutes <=59 && c.Minutes >= 0 && c.Seconds <= 59 && c.Seconds >= 0)
	{
		val = 0;
	}
	else
	{
		val = -1;
	}
	return val;
}

//This will print the time to the screen in the correct time format
void Display_Time(Time t)
{
	Print_Zero(t.Hours);
	cout << t.Hours << ":";
	Print_Zero(t.Minutes);
	cout << t.Minutes << ":";
	Print_Zero(t.Seconds);
	cout << t.Seconds << endl;
}

//Pass in the time in a struct and return the time converted converted to seconds
long Time_To_Seconds(Time j)
{
	long total;
	total = j.Hours * 3600 + j.Minutes * 60 + j.Seconds;
	return total;
}

//Pass in the time and in seconds as an integer and return Hours, Minutes, Seconds to a stuct
Time Seconds_To_Time(long k)
{
	Time convert;
	convert.Hours = k / 3600;
	k %= 3600;
	convert.Minutes = k / 60;
	convert.Seconds = k % 60;
	if (convert.Hours > 23)
		convert.Hours = convert.Hours - 24;
	return convert;
}

//Print a zero in front of zero if its missing a zero in front of the time
void Print_Zero(int i)
{
	if (i < 10 && i >= 0)
	{
		cout << "0";
	}
}