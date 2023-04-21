#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "GPA.h"
#include "UI.h"
#include "GPAlist.h"


using namespace std;

namespace sdds
{
	void clearInputBuffer(void)
	{
		// Discard all remaining input from the standard input buffer:
		while (getchar() != '\n')
		{
			;
		}
	}
	//begin the interface system
	void interface(struct GPA search[])
	{
		double gpaInput;
		int i, flag = 1;
		char symbol, programExit;

		cout << "Enter GPA query..." << endl;
		do
		{
			//reset left counter
			int listNumber = 1;
			cout << "? ";
			cin >> symbol;
			if (symbol == '!')
			{
				cout << "Exit the program? (Y)es/(N)o: ";
				cin >> programExit;
				if (programExit == 'y' || programExit == 'Y')
				{
					flag = 0;
				}
				else if (programExit == 'n' || programExit == 'N')
				{
					flag = 1;
				}
			}
			else if (symbol != '!')
			{
				cin >> gpaInput;
			}
			clearInputBuffer();
			//take input then clear buffer 
			if (symbol == '>')
			{
				for (i = 0; i < COUNT; i++)
				{
					if (search[i].gpa > gpaInput)
					{
						printf("[%d] %d: %0.1lf (%s)\n", listNumber++, search[i].stno, search[i].gpa, search[i].name);
						flag = 1;
					}
				}
			}
			else if (symbol == '<')
			{
				for (i = 0; i < COUNT; i++)
				{
					if (search[i].gpa < gpaInput && search[i].gpa != 0)
					{
						printf("[%d] %d: %0.1lf (%s)\n", listNumber++, search[i].stno, search[i].gpa, search[i].name);
						flag = 1;
					}
				}
			}
			else if (symbol == '~')
			{
				for (i = 0; i < COUNT; i++)
				{
					if (search[i].gpa <= (gpaInput + 0.05) && search[i].gpa >= (gpaInput - 0.05))
					{
						printf("[%d] %d: %0.1lf (%s)\n", listNumber++, search[i].stno, search[i].gpa, search[i].name);
						flag = 1;
					}
				}
			}
			else if (symbol != '~' && symbol != '<' && symbol != '>' && symbol != '!')
			{
				printf("Syntax error: ? [Op][value]<ENTER>\n");
				printf("Op: [>,<,~,!]\n");
				printf("value: GPA value\n\n");
				flag = 1;
			}
		} while (flag != 0);
	}
}