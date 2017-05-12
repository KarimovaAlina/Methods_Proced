#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;

void ChckInFile(ifstream &file)
{
	if (!file)
	{
		cout << "Error. Can't open input file." << endl;
		system("pause");
		exit(1);
	}
}

void ChckInValue(ifstream &file)
{
	if (file.fail())
	{
		cout << "Error. Incorrect values. There are strange symbols in the input file or there is int or float overflow." << endl;
		system("pause");
		exit(1);
	}
}

void ChckNegative(float value)
{
	if (value < 0)
	{
		cout << "Error. Incorrect values. There are negative values." << endl;
		system("pause");
		exit(1);
	}
}

void ChckOutFile(ofstream &file)
{
	if (!file)
	{
		cout << "Error. Can't open output file." << endl;
		system("pause");
		exit(1);
	}
}