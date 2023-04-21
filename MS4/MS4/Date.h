#ifndef DATE_H
#define DATE_H

#include "Error.h"
using namespace std;

namespace sdds {
	class Date {
	private:
		int year, month, day, hour, minute;
		bool _dateOnly;
		Error dateError;
	public:
		Date();
		Date(int year, int month, int day);
		Date(int year, int month, int day, int hour, int minute = 0);
		Date(const Date& date);

		Date& operator=(const Date& date);
		void validate();
		int getUniqueDateValue() const;

		bool operator==(const Date& date) const;
		bool operator!=(const Date& date) const;
		bool operator<(const Date& date) const;
		bool operator>(const Date& date) const;
		bool operator<=(const Date& date) const;
		bool operator>=(const Date& date) const;

		Date& dateOnly(const bool _dateOnly);
		operator bool() const;
		const Error& error() const;

		ostream& operator<<(ostream& out) const;
		istream& operator>>(istream& in);

		void resetDate();
	};

	ostream& operator<<(ostream& out, const Date& date);
	istream& operator>>(istream& in, Date& date);
}

#endif