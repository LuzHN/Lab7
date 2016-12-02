#ifndef intern_h
#define intern_h
#include "usuario.h"


class intern : public usuario{

	private:
		int dias;

	public:

		intern();
		virtual ~intern();
		void setDias(int);
		int getDias();
};

#endif
