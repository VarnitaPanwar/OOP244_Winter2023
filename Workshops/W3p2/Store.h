/***********************************************************************
// OOP244 Workshop 3 p2:  Store header file
//
// File Store.h
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


#include "Toys.h"
#ifndef SDDS_STORE_H
#define SDDS_STORE_H
#define MAX_NUM_TOYS 10	
#define MAX_SNAME 31	

namespace sdds
{
	class Store
	{
		char m_StoreName[MAX_SNAME];
		int m_noOfToys;
		int m_addToys;
		Toys m_Toy[MAX_NUM_TOYS];

	public:
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display()const;
		void find(int sku);
		void setEmpty();
	};
}
#endif // !SDDS_STORE_H