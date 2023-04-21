#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
	bool fileOpen(const char file[]);

	void fileClose();

	bool stuName(char stdName[]);

	bool stuID(int* ID);

	bool stuGPA(double* GPA);
}

#endif 