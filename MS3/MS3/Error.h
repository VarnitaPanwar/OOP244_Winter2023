/***********************************************************************
// OOP244 Project MS3:  Error h file
//
// File Error.h 
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

#ifndef ERROR_H
#define ERROR_H

using namespace std;

namespace sdds {
	class Error {
	private:
		char* errorMessage;
	public:
		Error();
		Error(const char errorMessage[]);

		Error(const Error& error);
		Error& operator=(const Error& error);
		~Error();

		void operator=(const char errorMessage[]);
		operator bool() const;
		Error& clear();

		ostream& operator<<(ostream& out) const;
	};

	// Error Functions
	ostream& operator<<(ostream& out, const Error& error);
}

#endif