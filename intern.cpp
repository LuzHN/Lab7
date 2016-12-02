#include "intern.h"

intern :: intern(){

}

intern :: ~intern(){

}

intern :: intern(string pnom, string pcorreo, int pdias, string pPass){
	nombre = pnom;
	correo = pcorreo;
	dias = pdias;
	password = pPass;
	tipo = "intern";
}

void intern :: setDias(int pDias){
	dias = pDias;
}

int intern :: getDias(){
	return dias;
}