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
		delete[] this->errorMessage;
	}

	void Error::operator=(const char errorMessage[])
	{
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

	// Error Functions
	ostream& operator<<(ostream& out, const Error& error) {
		return error << out;
	}
}