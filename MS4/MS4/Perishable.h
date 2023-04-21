#ifndef PERISHABLE_H
#define PERISHABLE_H

#include "Item.h"
#include "Date.h"
using namespace std;

namespace sdds {
	class Perishable : public Item {
		private:
			Date expiryDate;
		public:
			char itemType()	const;
			
			ostream& write(ostream& out) const;
			istream& read(istream& in);
			ofstream& save(ofstream& out) const;
			ifstream& load(ifstream& in);
	};
}

#endif