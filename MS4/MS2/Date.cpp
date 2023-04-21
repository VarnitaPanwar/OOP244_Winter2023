/***********************************************************************
// Final Project Milestone 2 
// Filename: Date.cpp
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
#include <iomanip>
#include "Date.h"
#include "Utils.h"
#include "Error.h"
#include "POS.h"

using namespace std;

namespace sdds {
	Date::Date() : dateError()
	{
		_dateOnly = false;
		getSystemDate(year, month, day, hour, minute, _dateOnly);
	}

	Date::Date(int year, int month, int day) : dateError()
	{
		_dateOnly = true;
		this->year = year;
		this->month = month;
		this->day = day;

		this->hour = 0;
		this->minute = 0;

		validate();
	}

	Date::Date(int year, int month, int day, int hour, int minute) : dateError()
	{
		_dateOnly = false;
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;

		validate();
	}

	Date::Date(const Date& date) : dateError(date.dateError)
	{
		_dateOnly = date._dateOnly;

		year = date.year;
		month = date.month;
		day = date.day;
		hour = date.hour;
		minute = date.hour;
	}

	Date& Date::operator=(const Date& date)
	{
		if (this != &date)
		{
			dateError = date.dateError;
			_dateOnly = date._dateOnly;

			year = date.year;
			month = date.month;
			day = date.day;
			hour = date.hour;
			minute = date.hour;
		}

		return *this;
	}

	void Date::validate()
	{
		if (year < MIN_YEAR || year > MAX_YEAR)
		{
			dateError = "Invalid Year";
		}
		else if (month < 1 || month > 12)
		{
			dateError = "Invalid Month";
		}
		else if (day < 1 || day > daysOfMonth(year, month))
		{
			dateError = "Invalid Day";
		}
		else if (!_dateOnly)
		{
			if (hour < 0 || hour > 23)
			{
				dateError = "Invalid Hour";
			}
			else if (minute < 0 || minute > 59)
			{
				dateError = "Invlid Minute";
			}
		}
	}

	int Date::getUniqueDateValue() const
	{
		int value = uniqueDateValue(year, month, day, hour, minute);
		return value;
	}

	bool Date::operator==(const Date& date) const
	{
		if (getUniqueDateValue() == date.getUniqueDateValue())
		{
			return true;
		}

		return false;
	}

	bool Date::operator!=(const Date& date) const
	{
		if (getUniqueDateValue() != date.getUniqueDateValue())
		{
			return true;
		}

		return false;
	}

	bool Date::operator<(const Date& date) const
	{
		if (getUniqueDateValue() < date.getUniqueDateValue())
		{
			return true;
		}

		return false;
	}

	bool Date::operator>(const Date& date) const
	{
		if (getUniqueDateValue() > date.getUniqueDateValue())
		{
			return true;
		}

		return false;
	}

	bool Date::operator<=(const Date& date) const
	{
		if (getUniqueDateValue() <= date.getUniqueDateValue())
		{
			return true;
		}

		return false;
	}

	bool Date::operator>=(const Date& date) const
	{
		if (getUniqueDateValue() >= date.getUniqueDateValue())
		{
			return true;
		}

		return false;
	}

	Date& Date::dateOnly(const bool _dateOnly)
	{
		this->_dateOnly = _dateOnly;
		if (this->_dateOnly == true)
		{
			this->hour = 0;
			this->minute = 0;
		}

		return *this;
	}

	Date::operator bool() const
	{
		return (!dateError);
	}

	const Error& Date::error() const
	{
		return dateError;
	}

	ostream& Date::operator<<(ostream& out) const
	{
		if (!dateError)
		{
			out << year << "/";
			out << setfill('0') << setw(2) << month << "/";
			out << setfill('0') << setw(2) << day;

			if (!_dateOnly)
			{
				out << ", ";
				out << setfill('0') << setw(2) << hour << ":";
				out << setfill('0') << setw(2) << minute;
			}
		}
		else
		{
			out << dateError;
			out << "(";
			out << year << "/";
			out << setfill('0') << setw(2) << month << "/";
			out << setfill('0') << setw(2) << day;
			
			if (!_dateOnly)
			{
				out << ", ";
				out << setfill('0') << setw(2) << hour << ":";
				out << setfill('0') << setw(2) << minute;
			}

			out << ")";
		}

		return out;
	}

	istream& Date::operator>>(istream& in)
	{
		resetDate();

		in >> year;
		if (!in.fail())
			in.ignore();
		else
		{
			dateError = "Cannot read year entry";
			return in;
		}

		in >> month;
		if (!in.fail())
			in.ignore();
		else
		{
			dateError = "Cannot read month entry";
			return in;
		}
		

		in >> day;
		if (in.fail())
		{
			dateError = "Cannot read day entry";
			return in;
		}

		if (!_dateOnly)
		{
			in.ignore();

			in >> hour;
			if (!in.fail())
				in.ignore();
			else
			{
				dateError = "Cannot read hour entry";
				return in;
			}

			in >> minute;
			if (in.fail())
			{
				dateError = "Cannot read minute entry";
				return in;
			}
		}
		else
		{
			hour = 0;
			minute = 0;
		}

		if (!dateError)
			validate();

		return in;
	}

	ostream& operator<<(ostream& out, const Date& date)
	{
		return date << out;
	}

	istream& operator>>(istream& in, Date& date) 
	{
		return date >> in;
	}

	void Date::resetDate()
	{
		dateError.clear();
		year = 0;
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
	}
}