#ifndef admin_h
#define admin_h
#include "usuario.h"

class administrador : public usuario{



	private:
		string fecha;

	public:

		administrador();
		virtual ~administrador();

		void setFecha(string);
		string getFecha();
};

#endif