/***********************************************************************
// Final Project Milestone 2 
// Filename: utils.h
// Version 1.0
// Author	Varnita Panwar
// Revision History
// -----------------------------------------------------------
// Date : 2023-03-24     
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my project milestones.
// -----------------------------------------------------------
***********************************************************************/


#ifndef UTILS_H
#define UTILS_H

namespace sdds {
	void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
	int uniqueDateValue(int year, int mon, int day, int hour, int min);
	int daysOfMonth(int year, int month);
}

#endif