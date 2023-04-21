/***********************************************************************
// OOP244 Workshop 3 p2:  Store cpp file
//
// File Store.cpp
// Version 1.0
// Date  02/05/2023
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
#include <cstring>
#include "Store.h"
#include "Toys.h"

using namespace std;
namespace sdds {
	void Store::setStore(const char* sName, int no)
	{
		setEmpty();
		if (sName != nullptr)
			if (strlen(sName) <= MAX_SNAME)
			{
				strcpy(m_StoreName, sName);
			}
		if (no <= MAX_NUM_TOYS)
		{
			m_noOfToys = no;
		}
		else
		{
			m_noOfToys = 0;
		}
	}
	void Store::setToys(const char* tname, int sku, double price, int age)
	{
		if (m_addToys < MAX_NUM_TOYS && m_addToys < m_noOfToys)
		{
			m_Toy[m_addToys].addToys(tname, sku, price, age);
			m_addToys++;
		}
	}
	void Store::display()const
	{
		if (m_StoreName[0] == '\0')
		{
			cout << "Invalid Store" << endl;
		}
		else {
			cout.fill('*');
			cout.width(60);
			cout << '*' << endl;

			cout << m_StoreName << endl;

			cout.width(60);
			cout << '*' << endl;

			cout << "list of the toys" << endl;

			cout.fill(' ');
			cout.width(30);
			cout << "SKU";
			cout.width(10);
			cout << "Age";
			cout.width(11);
			cout << "Price";
			cout.width(10);
			cout << "Sale" << endl;
			for (int i = 0; i < m_noOfToys; i++)
			{
				cout << "Toy[" << i + 1 << "] :";
				m_Toy[i].display();
			}
		}
	}
	void Store::find(int sku)
	{
		for (int i = 0; i < m_noOfToys; i++)
		{
			if (sku == m_Toy[i].getSku() && !m_Toy[i].isOnSale())
			{
				m_Toy[i].isSale(true);
				m_Toy[i].calSale();
			}
		}
	}
	void Store::setEmpty()
	{
		m_StoreName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
		for (int i = 0; i < m_addToys; i++)
		{
			m_Toy[i] = {};
		}
	}
}