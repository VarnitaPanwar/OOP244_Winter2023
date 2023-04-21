/***********************************************************************
// OOP244 Project MS3:  Item h file
//
// File Item.h 
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

#ifndef ITEM_H
#define ITEM_H

#include "Error.h"
#include "PosIO.h"
#include "POS.h"

namespace sdds {
	class Item : public PosIO {
		private:
			char sku[MAX_SKU_LEN + 1];
			char* name;
			double price;
			bool taxed;
			int _quantity;
		protected:
			int _displayType;
			Error errorState;
		public:
			void setEmpty();

			Item();

			Item(const Item& item);
			Item& operator=(const Item& item);
			~Item();

			bool operator==(const char* sku) const;
			bool operator>(const Item& item) const;
			int operator+=(const int quantity);
			int operator-=(const int quantity);

			operator bool() const;

			virtual char itemType()	const = 0;
			Item& displayType(const int type);
			double cost() const;
			int quantity() const;

			Item& clear();

		    ostream& write(ostream& out) const;
			istream& read(istream& in);
			ofstream& save(ofstream& out) const;
			ifstream& load(ifstream& in);

			ostream& bprint(ostream& out) const;
	};

	double operator+=(double& value, const Item& item);
}

#endif