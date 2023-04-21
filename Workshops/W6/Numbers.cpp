/***********************************************************************
// OOP244 Workshop w6:  Numbers cpp file
//
// File Numbers.cpp
// Version 1.0
// Date  03/11/2023
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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Numbers.h"
using namespace std;

namespace sdds
{
	// private functions
	void Numbers::sort(double* array, unsigned int size)
	{
		if (array) {
			for (unsigned int i = 1; i < size; i++)
			{
				double max = array[i];
				int j = i - 1;
				while (j >= 0 && array[j] > max)
				{
					array[j + 1] = array[j];
					j--;
				}
				array[j + 1] = max;
			}
		}
	}
	
	unsigned int Numbers::count_Lines() const
	{
		int lineCount{};
		string str;
		ifstream f(fileName);
		if (f.is_open())
		{
			while (getline(f, str))
			{
				lineCount++;
			}
		}
		f.close();
		return lineCount;
	}
	void Numbers::set_Empty()
	{
		collection = nullptr;
		strcpy(fileName, "");
		collectionSize = 0;
		originalFlag = false;
		addFlag = false;
	}
	bool Numbers::load()
	{
		bool success = false;
		unsigned int noOfLines = count_Lines();
		unsigned int count{};
		double temp{};
		delete[] collection;
		collection = nullptr;
		if (noOfLines > 0)
		{
			collection = new double[noOfLines];
			ifstream f(fileName);
			if (f.is_open())
			{
				while (count < noOfLines && f >> temp)
				{
					collection[count] = temp;
					count++;
				}
				success = true;
			}
			f.close();
			if (noOfLines == count)
			{
				collectionSize = noOfLines;
				originalFlag = true;
			}
			else {
				delete[] collection; 
				set_Empty();
			}
		}
		return success;
	}
	void Numbers::save()
	{
		if (originalFlag && addFlag)
		{
			ofstream f(fileName);
			if (f.is_open()) {
				for (unsigned int i = 0; i < collectionSize; i++)
				{
					f.setf(ios::fixed);
					f.precision(2);
					f << collection[i] << endl;
				}
			}
		}
	}
	double Numbers::Maxi() const
	{
		double largest = collection[collectionSize - 1];
		for (unsigned int i = collectionSize - 2; i > 0; i--)
		{
			if (collection[i] > largest)
			{
				largest = collection[i];
			}
		}
		return largest;
	}
	double Numbers::Mini() const
	{
		double minimum = collection[0];
		for (unsigned int i = 1; i < collectionSize; i++)
		{
			if (collection[i] < minimum)
			{
				minimum = collection[i];
			}
		}
		return minimum;
	}
	double Numbers::average() const
	{
		double total{};
		for (unsigned int i = 0; i < collectionSize; i++)
		{
			total += collection[i];
		}
		return total / collectionSize;
	}

	// public functions
	Numbers::Numbers(const char* cString)
	{
		set_Empty();
		strcpy(fileName, cString);
		load();
	}
	Numbers::Numbers()
	{
		set_Empty();
	}
	Numbers::~Numbers()
	{
		save();
		delete[] collection;
	}
	// copy constructor
	Numbers::Numbers(const Numbers& source)
	{
		collection = nullptr;
		*this = source;
	}
	// copy assignment operator
	Numbers& Numbers::operator=(const Numbers& source)
	{
		if (this != &source)
		{
			save();
			delete[] collection;
			set_Empty();
			if (source)
			{
				originalFlag = false;
				collection = new double[source.collectionSize];
				for (unsigned int i = 0; i < source.collectionSize; i++)
				{
					collection[i] = source.collection[i];
				}
				collectionSize = source.collectionSize;
				strcpy(fileName, source.fileName);
			}
		}
		return *this;
	}
	Numbers::operator bool() const
	{
		return collection != nullptr;
	}
	void Numbers::sort()
	{
		sort(collection, collectionSize);
	}
	Numbers& Numbers::operator+=(double value)
	{
		if (*this)
		{
			double* temp = nullptr;
			temp = new double[collectionSize + 1];
			for (unsigned int i = 0; i < collectionSize; i++)
			{
				temp[i] = collection[i];
			}
			temp[collectionSize] = value;
			delete[] collection;
			collection = nullptr;
			collection = temp;
			collectionSize += 1;
			addFlag = true;
		}
		return *this;
	}
	ostream& Numbers::display(ostream& ostr) const
	{
		if (collection == nullptr)
		{
			ostr << "Empty list";
		}
		else
		{
			ostr.setf(ios::fixed);
			ostr.precision(2);
			if (!originalFlag) ostr << "Copy of ";
			ostr << fileName << endl;
			for (unsigned int i = 0; i < collectionSize - 1; i++)
			{
				ostr << collection[i] << ", ";
			}
			ostr << collection[collectionSize - 1] << endl;
			ostr.fill('-');
			ostr.width(76);
			ostr << '-' << endl;
			ostr << "Total of " << collectionSize << " number(s), "
				<< "Largest: " << Maxi() << ", "
				<< "Smallest: " << Mini() << ", "
				<< "Average: " << average() << endl;
			ostr.fill('=');
			ostr.width(76);
			ostr << '=';
		}
		return ostr;
	}
	// helper functions
	ostream& operator<<(ostream& ostr, const Numbers& right)
	{
		return right.display(ostr);
	}
	istream& operator>>(istream& istr, Numbers& right)
	{
		double temp{};
		istr >> temp;
		right += temp;
		return istr;
	}
}