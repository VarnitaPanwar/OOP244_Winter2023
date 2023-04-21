#ifndef ERROR_H
#define ERROR_H

using namespace std;

namespace sdds {
	class Error {
		private:
			char* errorMessage;
		public:
			Error();
			Error(const char errorMessage[]);
			
			Error(const Error& error);
			Error& operator=(const Error& error);
			~Error();

			void operator=(const char errorMessage[]);
			operator bool() const;
			Error& clear();

			ostream& operator<<(ostream& out) const;
	};

	ostream& operator<<(ostream& out, const Error& error);
}

#endif
