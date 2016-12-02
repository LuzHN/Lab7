
#include "usuario.h"

#ifndef supervisor_h
#define supervisor_h




class supervisor : public usuario{
	private:
		int veces;

	public:
		supervisor();
		supervisor(string, string, int, string);
		virtual ~supervisor();
		void setVeces(int);
		int getVeces();
};

#endif