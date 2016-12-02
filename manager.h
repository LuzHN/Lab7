#ifndef manager_h
#define manager_h

#include "usuario.h"


class manager : public usuario{
	private:
		int sueldo;
	public:
		manager();
		manager(string, string, int, string);
		virtual ~manager();
		void setSueldo(int);
		int getSueldo();
};

#endif