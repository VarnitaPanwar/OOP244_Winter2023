/***********************************************************************
// OOP244 Project MS3:  PosIO cpp file
//
// File PosIO.cpp 
// Version 1.0
// Date  04/01/2023
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
#include "PosIO.h"

using namespace std;

namespace sdds {
	PosIO::~PosIO()
	{

	}

	ostream& PosIO::operator<<(ostream& out) const
	{
		return write(out);
	}

	ofstream& PosIO::operator<<(ofstream& out) const
	{
		return save(out);
	}

	istream& PosIO::operator>>(istream& in)
	{
		return read(in);
	}

	ifstream& PosIO::operator>>(ifstream& in)
	{
		return load(in);
	}

	// PosIO Functions
	ostream& operator<<(ostream& out, const PosIO& posIO)
	{
		return posIO << out;
	}

	ofstream& operator<<(ofstream& out, const PosIO& posIO)
	{
		return posIO << out;
	}

	istream& operator>>(istream& in, PosIO& posIO)
	{
		return posIO >> in;
	}

	ifstream& operator>>(ifstream& in, PosIO& posIO)
	{
		return posIO >> in;
	}
}