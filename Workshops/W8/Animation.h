/***********************************************************************
// OOP244 Workshop w8 p1:  Animation header file
//
// File Animation.h
// Version 1.0
// Date  03/25/2023
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


#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include "Video.h"

namespace sdds
{
	class Animation : public Video
	{
		int m_dimension{};
	public:
		Animation();
		Animation(int length, int dimension);

		void load(std::istream& istr) override;
		std::ostream& play(std::ostream& ostr)const override;
	};
}
#endif // !SDDS_ANIMATION_H