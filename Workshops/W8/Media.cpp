/***********************************************************************
// OOP244 Workshop w8 p1:  Media cpp file
//
// File Media.cpp
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
#include "Media.h"
#include "VRVideo.h"
#include "Animation.h"
#include "Video.h"
using namespace std;

namespace sdds
{
	std::istream& operator>>(std::istream& istr, Media& M)
	{
		M.load(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Media& M)
	{
		return M.play(ostr);
	}
}
