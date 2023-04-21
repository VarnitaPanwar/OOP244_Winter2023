/***********************************************************************
// OOP244 Workshop w3p1:  Department h file
//
// File Department.h
// Version 1.0
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

#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_

namespace sdds
{

	const int MAX_TOPIC_LENGTH = 25;

	struct Project
	{
		char topic[MAX_TOPIC_LENGTH + 1]; 
		double cost;
		
	};

	class Department
	{
		char* m_Name;
		Project* m_project;
		int m_numOfProject;
		double m_budget = 15345.99;
	public:
		void updateName(const char* newname);
		void updateBudget(double change);
		bool addProject(Project& newproject);
		void createDepartment(const char* newname,
			Project& newproject,
			double change);
		Project* fetchProjects() const;
		int fetchNumProjects() const;
		double fetchBudget() const;
		char* fetchName() const;
		double totalexpenses();
		double remainingBudget();
		void clearDepartment();
	};

	
	void display(const Project& project);
	void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_
