/***********************************************************************
// Final Project Milestone 2
// Filename: Error.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds {
	Error::Error()
	{
		this->errorMessage = nullptr;
	}

	Error::Error(const char errorMessage[])
	{
		this->errorMessage = new char[strlen(errorMessage) + 1];
		strcpy(this->errorMessage, errorMessage);
	}

	Error::Error(const Error& error)
	{
		/*if (this->errorMessage != nullptr && this->errorMessage != NULL)
		{
			delete[] this->errorMessage;
		}*/

		if (error.errorMessage != nullptr)
		{
			this->errorMessage = new char[strlen(error.errorMessage) + 1];
			strcpy(this->errorMessage, error.errorMessage);
		}
		else
		{
			this->errorMessage = nullptr;
		}
	}

	Error& Error::operator=(const Error& error)
	{
		if (this != &error)
		{
			/*if (this->errorMessage != nullptr && this->errorMessage != NULL)
			{
				delete[] this->errorMessage;
			}*/

			delete[] this->errorMessage;

			if (error.errorMessage != nullptr)
			{
				this->errorMessage = new char[strlen(error.errorMessage) + 1];
				strcpy(this->errorMessage, error.errorMessage);
			}
		}

		return *this;
	}

	Error::~Error()
	{
		/*if (this->errorMessage != nullptr && this->errorMessage != NULL)
		{
			delete[] this->errorMessage;
		}*/
		delete[] this->errorMessage;
	}

	void Error::operator=(const char errorMessage[])
	{
		/*if (this->errorMessage != nullptr && this->errorMessage != NULL)
		{
			delete[] this->errorMessage;
		}*/

		delete[] this->errorMessage;

		this->errorMessage = new char[strlen(errorMessage) + 1];
		strcpy(this->errorMessage, errorMessage);
	}

	Error::operator bool() const
	{
		return this->errorMessage != nullptr;
	}

	Error& Error::clear()
	{
		/*if (this->errorMessage != nullptr && this->errorMessage != NULL)
		{
			delete[] this->errorMessage;
		}*/

		delete[] this->errorMessage;

		this->errorMessage = nullptr;

		return *this;
	}

	ostream& Error::operator<<(ostream& out) const {
		if (this->errorMessage != nullptr)
		{
			out << this->errorMessage;
		}
		return out;
	}

	ostream& operator<<(ostream& out, const Error& error) {
		return error << out;
	}
}