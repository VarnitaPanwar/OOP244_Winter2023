#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

#include "Item.h"
#include "Perishable.h"

using namespace std;

namespace sdds {
	char Perishable::itemType()	const
	{
		return 'P';
	}

	ostream& Perishable::write(ostream& out) const
	{
		Item::write(out);
		if (errorState)
		{
			// do nothing
		}
		else
		{
			if (_displayType == POS_LIST)
			{
				out << "  ";
				out << expiryDate;
				out << " ";
				out << "|";
			}
			else if (_displayType == POS_FORM)
			{
				out << "Expiry date: ";
				out << expiryDate;
				out << endl;
				out << "=============^";
				out << endl;
			}
		}

		return out;
	}

	istream& Perishable::read(istream& in)
	{
		Item::read(in);
		if (errorState || in.fail())
		{
			// do nothing
		}
		else if (!errorState && !in.fail())
		{
			Date date;
			date.dateOnly(true);

			cout << "Expiry date (YYYY/MM/DD)" << endl;
			cout << "> ";
			in >> date;

			if (date)
			{
				expiryDate = date;
			}
			else
			{
				Error error = expiryDate.error();
				error = errorState;
			}
		}

		return in;
	}

	ofstream& Perishable::save(ofstream& out) const
	{
		Item::save(out);
		if (!errorState)
		{
			out << ",";
			out << expiryDate;
		}
		else
		{
			// do nothing
		}

		return out;
	}

	ifstream& Perishable::load(ifstream& in)
	{
		Item::load(in);
		if (errorState || in.fail())
		{
			// do nothing
		}
		else if (!errorState && !in.fail())
		{
			Date date;
			date.dateOnly(true);

			in.ignore();
			in >> date;

			if (date)
			{
				expiryDate = date;
			}
			else
			{
				errorState = date.error();
			}
		}

		return in;
	}
}