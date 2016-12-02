#include "manager.h"

manager :: manager(){

}

manager :: ~manager(){

}

manager :: manager(string pnom, string pcorreo, int pSueldo, string pPass){
	nombre = pnom;
	correo = pcorreo;
	sueldo = pSueldo;
	password = pPass;
	tipo = "manager";
}

void manager :: setSueldo(int pSueldo){
	sueldo = pSueldo;
}

int manager :: getSueldo(){
	return sueldo;
}