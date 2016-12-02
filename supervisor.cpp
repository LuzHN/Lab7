#include "supervisor.h"

supervisor :: supervisor(){

}

supervisor :: ~supervisor(){

}

supervisor :: supervisor(string pnom, string pcorreo, int pveces, string pPass){
	nombre = pnom;
	correo = pcorreo;
	veces = pveces;
	password = pPass;
	tipo = "supervisor";
}

void supervisor :: setVeces(int vez){
	veces = vez;
}

int supervisor :: getVeces(){
	return veces;
}