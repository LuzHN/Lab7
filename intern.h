#ifndef intern_h
#define intern_h
#include "usuario.h"


class intern : public usuario{

	private:
		int dias;

	public:

		intern();
		intern(string, string, int, string);
		virtual ~intern();
		void setDias(int);
		int getDias();
};

#endif
