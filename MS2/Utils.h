#ifndef UTILS_H
#define UTILS_H

namespace sdds {
	void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
	int uniqueDateValue(int year, int mon, int day, int hour, int min);
	int daysOfMonth(int year, int month);
}

#endif