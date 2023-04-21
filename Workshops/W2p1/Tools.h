/***********************************************************************
// OOP244 Workshop 2 p1
//
// Version 1.0
// Date 01/27/2023
// Author Varnita panwar
// Description
// MyId: 166484212
// Email: vpanwar1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds{
	int openFile_r(const char filename[]); 
	void closefile();					   
	int NoOfTraces();					   
	int read(char packName[]);
	int read(int& cusTimeUsing);
	int read(double& timeInHours);
	int read(char& dayOfWeek);

	void strCpy(char* des, const char* src); 
	int strLen(const char* s);				 
}
#endif
