#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_UI_H
#define SDDS_UI_H
#define COUNT 100
#include "GPA.h"

namespace sdds
{
	void clearInputBuffer(void);

	void interface(struct GPA search[]);
}

#endif