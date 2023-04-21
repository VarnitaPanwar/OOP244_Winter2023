#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include "Item.h"
using namespace std;

namespace sdds {
	class NonPerishable : public Item {
		public:
			char itemType()	const;
			ostream& write(ostream& out) const;
	};
}

#endif