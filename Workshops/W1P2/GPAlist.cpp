/***********************************************************************
// Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "GPAlist.h"
#include "GPA.h"
#include "File.h"
#include "UI.h"


using namespace std;

namespace sdds
{
	GPA gpas[100] = { {0} };
	// read file to the structure then pull in the sort function to sort the student numbers
	bool startGPA(const char* file)
	{
		GPA gp;

		int readGPA = 0;
		bool readSuccess = true;
		if (fileOpen(file))
		{
			while (readSuccess && readGPA < 100)
			{
				readSuccess = stuName(gp.name) && stuID(&gp.stno) && stuGPA(&gp.gpa);

				if (readSuccess)
				{
					gpas[readGPA++] = gp;
				}

			}
			fileClose();
		}
		bSort(gpas);
		return readGPA;
	}
	// start the UI once a true is thrown
	bool gpaQuery(const char* filename)
	{
		bool flag = false;

		if (startGPA(filename) == true)
		{
			flag = true;
			interface(gpas);
		}
		return flag;
	}

	// Sorting the student numbers from lowest value to highest
	void bSort(struct GPA stuno[])
	{
		int i, j, x;
		GPA noStudent = { {0} };

		for (i = j = 0; i < COUNT && stuno[i].stno != 0; i++)
		{
			j++;
		}
		for (i = 0; i < j - 1; i++)
		{
			for (x = i + 1; x < j; x++)
			{
				if (stuno[i].stno > stuno[x].stno)
				{
					noStudent = stuno[i];
					stuno[i] = stuno[x];
					stuno[x] = noStudent;
				}
			}
		}
	}
}