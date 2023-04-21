/***********************************************************************
// OOP244 Workshop w8 p1:  Video cpp file
//
// File Video.cpp
// Version 1.0
// Date  03/25/2023
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
#include <iostream>
#include "Video.h"
using namespace std;

namespace sdds
{
	int Video::get() const
	{
		return m_length;
	}
	Video::Video()
	{
		m_length = 0;
	}
	Video::Video(int length)
	{
		if (length >= 0)
		{
			m_length = length;
		}
		else
		{
			m_length = 0;
		}
	}
	void Video::load(std::istream& istr)
	{
		istr >> m_length;
		istr.ignore();
	}
}