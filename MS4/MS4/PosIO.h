#ifndef POSIO_H
#define POSIO_H

using namespace std;

namespace sdds {
	class PosIO {
	public:
		virtual ostream& write(ostream& out) const = 0;
		virtual istream& read(istream& in) = 0;
		virtual ofstream& save(ofstream& out) const = 0;
		virtual ifstream& load(ifstream& in) = 0;

		virtual ~PosIO();

		ostream& operator<<(ostream& out) const;
		ofstream& operator<<(ofstream& out) const;

		istream& operator>>(istream& in);
		ifstream& operator>>(ifstream& in);
	};

	// PosIO Functions
	ostream& operator<<(ostream& out, const PosIO& posIO);
	ofstream& operator<<(ofstream& out, const PosIO& posIO);

	istream& operator>>(istream& in, PosIO& posIO);
	ifstream& operator>>(ifstream& in, PosIO& posIO);
}

#endif