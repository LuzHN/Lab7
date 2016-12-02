#include "administrador.h"

administrador :: administrador(string pnom, string pcorreo, string pFecha, string pPass){
	nombre = pnom;
	correo = pcorreo;
	fecha = pFecha;
	password = pPass;
}

administrador :: ~administrador(){

}

administrador :: administrador(){
	
}

void administrador :: setFecha(string pFecha){
	fecha = pFecha;
}

string administrador :: getFecha(){
	return fecha;
}
