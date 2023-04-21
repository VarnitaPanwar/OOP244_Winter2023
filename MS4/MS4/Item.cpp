#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#include "Error.h"
#include "PosIO.h"
#include "Utils.h"
#include "POS.h"
#include "Item.h"

using namespace std;

namespace sdds {
	void Item::setEmpty()
	{
		for (int i = 0; i < MAX_SKU_LEN + 1; i++)
		{
			sku[i] = '\0';
		}

		name = nullptr;
		price = 0;
		taxed = false;
		_quantity = 0;

		_displayType = 1;
		errorState.clear();
	}

	Item::Item() : errorState()
	{
		setEmpty();
	}

	Item::Item(const Item& item) : errorState(item.errorState)
	{
		strcpy(sku, item.sku);

		if (item.name != nullptr)
		{
			name = new char[strlen(item.name) + 1];
			strcpy(name, item.name);
		}
		else
		{
			name = nullptr;
		}

		price = item.price;
		taxed = item.taxed;
		_quantity = item._quantity;

		_displayType = item._displayType;
		errorState = item.errorState;
	}

	Item& Item::operator=(const Item& item)
	{
		if (this != &item)
		{
			strcpy(sku, item.sku);

			if (item.name != nullptr)
			{
				delete[] name;

				name = new char[strlen(item.name) + 1];
				strcpy(name, item.name);
			}
			else
			{
				name = nullptr;
			}

			price = item.price;
			taxed = item.taxed;
			_quantity = item._quantity;

			_displayType = item._displayType;
			errorState = item.errorState;
		}

		return *this;
	}

	Item::~Item()
	{
		delete[] name;
	}

	bool Item::operator==(const char* sku) const
	{
		if (strcmp(sku, this->sku) == 0)
		{
			return true;
		}

		return false;
	}

	bool Item::operator>(const Item& item) const
	{
		if (strcmp(name, item.name) > 0)
		{
			return true;
		}

		return false;
	}

	int Item::operator+=(const int quantity)
	{
		this->_quantity += quantity;

		if (this->_quantity > MAX_STOCK_NUMBER)
		{
			this->_quantity = MAX_STOCK_NUMBER;
			errorState = ERROR_POS_QTY;
		}

		return this->_quantity;
	}

	int Item::operator-=(const int quantity)
	{
		if (quantity > this->_quantity)
		{
			this->_quantity = 0;
			errorState = ERROR_POS_STOCK;
		}
		else
		{
			this->_quantity -= quantity;
		}

		return this->_quantity;
	}

	Item::operator bool() const
	{
		return (!errorState);
	}

	double operator+=(double& value, const Item& item)
	{
		value += item.cost() * item.quantity();

		return value;
	}

	Item& Item::displayType(const int type)
	{
		_displayType = type;

		return *this;
	}

	double Item::cost() const
	{
		if (taxed)
		{
			return price + price * TAX;
		}

		return price;
	}

	int Item::quantity() const
	{
		return _quantity;
	}

	Item& Item::clear()
	{
		errorState.clear();

		return *this;
	}

	ostream& Item::write(ostream& out) const
	{
		if (errorState)
		{
			out << errorState;
		}
		else if (_displayType == POS_LIST)
		{
			out << setw(MAX_SKU_LEN) << left << sku;
			out << "|";

			if (strlen(name) > 20)
			{
				for (int i = 0; i < 20; i++)
				{
					cout << name[i];
				}
			}
			else
			{
				out << setw(20) << left << name;
			}

			out << "|";
			out << right;
			out << setw(7) << fixed << setprecision(2) << price;
			out << "|";

			if (taxed)
			{
				out << " X ";
			}
			else
			{
				out << "   ";
			}

			out << "|";
			out << setw(4) << quantity();
			out << "|";
			out << setw(9) << fixed << setprecision(2) << cost() * quantity();
			out << "|";
		}
		else if (_displayType == POS_FORM)
		{
			out << "=============v" << endl;
			out << "Name:        " << name << endl;
			out << "Sku:         " << sku << endl;
			out << "Price:       " << fixed << setprecision(2) << price << endl;
			out << "Price + tax: ";

			if (taxed)
			{
				out << fixed << setprecision(2) << cost() << endl;
			}
			else
			{
				out << "N/A" << endl;
			}

			out << "Stock Qty:   " << quantity();

			out << endl;
		}
		out << left;

		return out;
	}

	istream& Item::read(istream& in)
	{
		bool valid;

		cout << "Sku" << endl;
		cout << "> ";

		valid = false;

		do
		{
			in.getline(sku, MAX_SKU_LEN);

			if (in.fail())
			{
				cout << ERROR_POS_SKU << endl;
				cout << "> ";
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
			{
				valid = true;
			}
		} while (!valid);

		cout << "Name" << endl;
		cout << "> ";

		valid = false;
		char temp[256];

		do
		{
			in.getline(temp, MAX_NAME_LEN);

			if (in.fail())
			{
				cout << ERROR_POS_NAME << endl;
				cout << "> ";
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
			{
				valid = true;
			}
		} while (!valid);

		if (name)
		{
			delete[] name;
		}

		name = new char[strlen(temp) + 1];
		strcpy(name, temp);

		valid = false;

		cout << "Price" << endl;
		cout << "> ";
		while (!valid)
		{
			in >> price;

			if (cin.fail() || price <= 0)
			{
				cout << ERROR_POS_PRICE << endl;
				cout << "> ";
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
			{
				valid = true;
			}
		}

		valid = false;
		char tempChar;

		cout << "Taxed?" << endl;
		cout << "(Y)es/(N)o: ";
		while (!valid)
		{

			in >> tempChar;

			if (cin.fail() || (tempChar != 'n' && tempChar != 'y'))
			{
				cout << "Only 'y' and 'n' are acceptable: ";
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
			{
				valid = true;
			}
		}

		if (tempChar == 'y')
		{
			taxed = true;
		}
		else
		{
			taxed = false;
		}

		valid = false;

		cout << "Quantity" << endl;
		cout << "> ";
		while (!valid)
		{
			in >> _quantity;

			if (cin.fail() || _quantity <= 0 || _quantity > MAX_STOCK_NUMBER)
			{
				cout << ERROR_POS_QTY << endl;
				cout << "> ";
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
			{
				valid = true;
			}
		}

		return in;
	}

	ofstream& Item::save(ofstream& out) const
	{
		if (errorState)
		{
			cerr << errorState << endl;
		}
		else
		{
			out << itemType();
			out << ',';
			out << sku;
			out << ',';
			out << name;
			out << ',';
			out << fixed << setprecision(2) << price;
			out << ',';
			out << taxed;
			out << ',';
			out << quantity();
		}

		return out;
	}

	ifstream& Item::load(ifstream& in)
	{
		errorState.clear();

		char skuLocal[MAX_SKU_LEN + 1];
		char nameLocal[MAX_NAME_LEN + 1];
		double priceLocal;
		bool taxedLocal;
		int _quantityLocal;
		
		in.getline(skuLocal, MAX_SKU_LEN, ',');
		in.getline(nameLocal, MAX_NAME_LEN, ',');
		in >> priceLocal;
		in.ignore();
		in >> taxedLocal;
		in.ignore();
		in >> _quantityLocal;

		if (!in.fail())
		{
			if (strlen(skuLocal) > MAX_SKU_LEN)
			{
				errorState = ERROR_POS_SKU;
			}
			else if (strlen(nameLocal) > MAX_NAME_LEN)
			{
				errorState = ERROR_POS_NAME;
			}
			else if (priceLocal <= 0)
			{
				errorState = ERROR_POS_PRICE;
			}
			else if (_quantityLocal < 0 || _quantityLocal > MAX_STOCK_NUMBER)
			{
				errorState = ERROR_POS_QTY;
			}

			if (!errorState)
			{
				strcpy(sku, skuLocal);

				if (name)
				{
					delete[] name;
				}
				name = new char[strlen(nameLocal) + 1];
				strcpy(name, nameLocal);


				price = priceLocal;
				taxed = taxedLocal;
				_quantity = _quantityLocal;
			}
		}

		return in;
	}

	ostream& Item::bprint(ostream& out) const
	{
		out << "| ";

		if (strlen(name) > 20)
		{
			for (int i = 0; i < 20; i++)
			{
				cout << name[i];
			}
		}
		else
		{
			out << setw(20) << left << name;
		}

		out << "| ";
		out << setw(9) << right << fixed << setprecision(2);
		out << cost();
		out << " |  ";

		if (taxed)
		{
			out << "T";
		}
		else
		{
			out << " ";
		}

		out << "  |";

		out << endl;

		return out;
	}
}