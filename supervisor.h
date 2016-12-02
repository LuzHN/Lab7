
#include "usuario.h"

#ifndef supervisor_h
#define supervisor_h




class supervisor : public usuario{
	private:
		int veces;

	public:
		supervisor();
		virtual ~supervisor();
		void setVeces(int);
		int getVeces();
};

#endif