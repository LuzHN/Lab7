#include "usuario.h"

usuario :: usuario(){
	
}

usuario :: usuario(string pnombre, string pcorreo, string pPass, string ptipo){
	nombre = pnombre;
	correo = pcorreo;
	password = pPass;
	tipo = ptipo;
}


usuario :: ~usuario(){

}

void usuario :: setNombre(string nom){
	nombre = nom;
}

string usuario :: getNombre(){
	return nombre;
}

void usuario :: setCorreo(string corr){
	correo = corr;
}

string usuario :: getCorreo(){
	return correo;
}

void usuario :: setPassword(string pass){
	password = pass;
}

string usuario :: getPassword(){
	return password;
}

void usuario :: setTipo(string ptipo){
	tipo = ptipo;
}

string usuario :: getTipo(){
	return tipo;
}
