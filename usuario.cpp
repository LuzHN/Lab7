#include "usuario.h"

usuario :: usuario(){

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

