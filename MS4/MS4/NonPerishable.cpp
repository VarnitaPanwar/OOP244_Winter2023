#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Item.h"
#include "NonPerishable.h"

using namespace std;

namespace sdds {
	char NonPerishable::itemType() const
	{
		return 'N';
	}

	ostream& NonPerishable::write(ostream& out) const
	{
		if (!errorState)
		{
			Item::write(out);
			
		    if (_displayType == POS_LIST)
			{
				out << "     N / A   |";
			}
			else if (_displayType == POS_FORM)
			{
				out << "=============^" << endl;
			}
		}

		return out;
	}
}