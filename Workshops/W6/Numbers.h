/***********************************************************************
// OOP244 Workshop w6:  Numbers h file
//
// File Numbers.h
// Version 1.0
// Date  03/11/2023
// Author Varnita Panwar
// Section OOP244-NDD
// Seneca ID   : 166484212
// Seneca email: vpanwar1@myseneca.ca
//
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_NUMBERS_H
#define SDDS_NUMBERS_H
#include <iostream>

namespace sdds
{
	class Numbers
	{
		double* collection; 
		char fileName[256];
		unsigned int collectionSize{}; 
		bool originalFlag{};	
		bool addFlag{};			

		void sort(double* array, unsigned int size);
		unsigned int count_Lines() const;
		void set_Empty();
		bool load();
		void save();
		double Maxi() const;
		double Mini() const;
		double average() const;

	public:
		Numbers(const char* cString); 
		Numbers();
		~Numbers();
		Numbers(const Numbers& source);
		Numbers& operator=(const Numbers& source);
		operator bool() const;
		void sort();
		Numbers& operator+=(double value);
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
	
	std::ostream& operator<<(std::ostream& ostr, const Numbers& right);
	std::istream& operator>>(std::istream& istr, Numbers& right);
}
#endif // !SDDS_NUMBERS_H
