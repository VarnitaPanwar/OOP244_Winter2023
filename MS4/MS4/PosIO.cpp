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