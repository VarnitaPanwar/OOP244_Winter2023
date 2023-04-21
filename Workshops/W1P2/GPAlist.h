#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_GPALIST_H
#define SDDS_GPALIST_H
#include "GPA.h"
#include "File.h"

namespace sdds
{
	bool startGPA(const char* file);

	bool gpaQuery(const char* filename);

	void bSort(struct GPA stuno[]);

}

#endif
