/***********************************************************************
// OOP244 Workshop w8 p1:  VRVideo cpp file
//
// File VRVideo.cpp
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
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds
{
	VRVideo::VRVideo() : Video()
	{
		equipment = nullptr;
	}
	VRVideo::VRVideo(int length, const char* string) : Video(length)
	{
		if (length >= 0 && string != nullptr)
		{
			equipment = new char[strlen(string) + 1];
			strcpy(equipment, string);
		}
		else {
			equipment = nullptr;
		}
	}
	VRVideo::~VRVideo()
	{
		delete[] equipment;
		equipment = nullptr;
	}
	void VRVideo::load(std::istream& istr)
	{
		char temp[100];
		Video::load(istr);
		istr.getline(temp, 100);
		delete[] equipment;
		equipment = nullptr;
		if (Video::get() >= 0 && temp != nullptr)
		{
			equipment = new char[strlen(temp) + 1];
			strcpy(equipment, temp);
		}
		else
		{
			equipment = nullptr;
		}
	}
	std::ostream& VRVideo::play(std::ostream& ostr) const
	{
		if (Video::get() > 0 && equipment != nullptr)
		{
			ostr << "VRVideo requires " << equipment << endl;
			ostr << "Video Length = " << Video::get();
		}
		return ostr;
	}
}