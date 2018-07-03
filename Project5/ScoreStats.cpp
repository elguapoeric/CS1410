//																Eric Tinajero
//																CS 1410 - Online
//																Dr. Rague
//																Due: 08/07/2016
//																Version: 1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// This program will read a file containing names and scores from a file and then sorts scores in descending order
//it will then calculate the average, standard deviation, median, high, low scores and display them.   


#include <iostream>
#include <iomanip>			
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class StudentStat
{
private:
	int Size;
	string Names[20];
	int Scores[20];
	float Avg,
		StDev,
		Median;
	int High_Score,
		Low_Score,
		Range;
	void Sortem();
public:
	void Input();
	void Calc_Avg();
	void Calc_StDev();
	void Calc_Median();
	void Calc_Range(); //Also calculates the high and low score
	void Output();
};

void StudentStat::Sortem()
{
	for (int a = 0; a < Size; a++)							//I have already subtracted one from the Size in the Input Function to make up for indexing
	{
		for (int b = a + 1; b <= Size; b++)
		{
			if (*(Scores + a) < *(Scores + b))
			{
				int tempS = *(Scores + a);
				*(Scores + a) = *(Scores + b);
				*(Scores + b) = tempS;

				string tempN = *(Names + a);
				*(Names + a) = *(Names + b);
				*(Names + b) = tempN;
			}
		}
	}
}

void StudentStat::Input()								//Read the file to be sorted 
{
	ifstream inFile;
	char fileName[20];
	int idxpos = 0;

	cout << "Welcome to Stats Program.  This program will read a file containing names and scores and then sorts scores in descending order." << endl;		//User info prompt
	cout << "It will then calculate the average, standard deviation, median, high, low score, and display them in the output file. " << endl << endl;
	cout << "Input the name of the file you would like to read from: ";
	cin >> fileName;

	inFile.open(fileName);							//Opening file

	if (!inFile)									//In case user inputs an invalid file
	{
		cout << "Cannot open file: " << fileName << endl;
		exit(0);
	}

	while (!inFile.eof())					//Read the Names and Scores
	{
		inFile >> *(Names + idxpos);
		inFile >> *(Scores + idxpos);
		idxpos++;
	}

	Size = idxpos - 1;				//Subtracted 1 to make up for the 0 index
	inFile.close();					//Close infile
}

void StudentStat::Calc_Avg()
{
	float temp = 0;
	for (int i = 0; i <= Size; i++)			//Will add up all the Scores
	{
		temp = temp + *(Scores + i);
	}

	temp = temp / (Size + 1);						//(Sum of scores)/(number of scores)
	Avg = temp;
}

void StudentStat::Calc_StDev()
{
	float temp = 0;
	float diff = 0;

	for (int i = 0; i <= Size; i++)
	{
		diff = abs(*(Scores + i) - Avg);	//absoulte value of the difference between score and average
		temp = temp + pow(diff, 2);			//Taking the difference for each score from the average and squaring it then adding previous difference squared
	}

	temp = sqrt(temp / (Size + 1));               //Taking the sum of differences squared and dividing by the number of scores to get the variance and then taking the square root to get Stdev.

	StDev = temp;
}

void StudentStat::Calc_Median()
{
	Sortem();									//Must sort first 
	float temp1 = 0;
	float temp2 = 0;

	if ((Size + 1) % 2 == 0)						//Have to add 1 to Size since I subtracted it in input function to make it less confusing in the sortem function
	{

		temp1 = *(Scores + ((Size + 1) / 2) - 1);  //I compensated for the index starting at 0 by subtracting 1 for the first of the two middle numbers
		temp2 = *(Scores + (Size + 1) / 2);		//No need for compensation for the second middle number because of the indexing
		Median = (temp1 + temp2) / 2;
	}
	else
	{
		Median = *(Scores + (Size / 2));
	}
}

void StudentStat::Calc_Range()
{
	Sortem();								//Sorted again just in case Range is ran before StDev since the order will matter here 
	Low_Score = *(Scores + Size);
	High_Score = *(Scores);
	Range = High_Score - Low_Score;
}

void StudentStat::Output()			//Display output
{
	char filename[30];				//Used for filename
	ofstream outfile;

	cout << "Enter the name of the file you would like to output: ";
	cin >> filename;
	outfile.open(filename);

	outfile << setw(20) << left << "Names" << setw(10)<< right << "Scores" << endl;   //Setting header to display
	for (int c = 0; c <= Size; c++)									//loop will print elements in array
	{
		outfile << setw(20) << left << *(Names + c) << setw(10) << right << *(Scores + c) << endl;
	}

	outfile << endl;
	outfile << setw(15) << left << "Average:" << setw(6) << fixed << setprecision(2) << Avg << endl;
	outfile << setw(15) << left << "St Dev:" << setw(6) << fixed << setprecision(2) << StDev << endl;
	outfile << setw(15) << left << "Median:" << setw(6) << fixed << setprecision(2) << Median << endl;
	outfile << setw(15) << left << "High Score:" << setw(6) << fixed << setprecision(2) << High_Score << endl;
	outfile << setw(15) << left << "Low Score:" << setw(6) << fixed << setprecision(2) << Low_Score << endl;
	outfile << setw(15) << left << "Range:" << setw(6) << fixed << setprecision(2) << Range << endl;
	outfile << endl;

	outfile.close();    //close the output file
}


int main()
{
	StudentStat StudObj;				//Creating an object
	StudObj.Input();
	StudObj.Calc_Avg();
	StudObj.Calc_StDev();
	StudObj.Calc_Median();
	StudObj.Calc_Range();
	StudObj.Output();
	return 0;                         //end main
}

