#include <iostream>
#include <vector>

#include "usuario.h"
#include "administrador.h"
#include "manager.h"
#include "intern.h"
#include "supervisor.h"

using namespace std;

int menuAdmin();
int menuSupervisor(int);
int menuManager(int);
int menuIntern(int);


int main(){


	vector <usuario*> users;

	string nom = "admin";
	string contraadmin = "master01";
	string fecha = "12/02/16";
	string correo = "420@hotmail.com";

	usuario* user = new administrador(nom, correo, fecha, contraadmin);

	users.push_back(user);

	cout << endl << "Ingrese su contraseña: ";
	string pass  = "";
	cin >> pass;

	string tipo = "";
	int posicion = 0;

	for (int i = 0; i < users.size(); ++i)
	{
		if(contraadmin == pass){
			tipo = "admin";
			break;
		} else if( dynamic_cast<supervisor*> (users.at(i)) != NULL){
			tipo = "supervisor";
			posicion = i;
		} else if( dynamic_cast<intern*> (users.at(i)) != NULL){
			tipo = "intern";
			posicion = i;
		} else if( dynamic_cast<manager*> (users.at(i)) != NULL){
			tipo = "manager";
			posicion = i;
		}
	
	}

	int opcion = 0;

	if(tipo == "admin"){

		while(opcion != 3){
			opcion = menuAdmin();

			switch(opcion){
				case 1:{
					cout << endl << "Ingrese el nombre del usuario que quiere agregar: ";
					string nombreusuario = "";
					cin >> nombreusuario;

					cout << endl << "Ingrese el correo del usuario que quiere agregar: ";
					string correousuario = "";
					cin >> correousuario;

					cout << endl << "Ingrese la contraseña de este usuario: ";
					string passusuario = "";
					cin >> passusuario;

					int tipouser = 0;

					cout << endl << "Ingrese el tipo de usuario que quiere agregar: " << endl 
								<< "1. Supervisor." << endl 
								<< "2. Intern." << endl 
								<< "3. Manager" << endl;
					cin >> tipouser;

					if(tipouser > 3 || tipouser <= 0){
						cout << endl << "Valor ingresado es incorrecto :v" << endl;
					} else{
						if(tipouser == 1){
							usuario* superviser = new supervisor(nombreusuario, correousuario, 0, passusuario);

						}
					}
					break;
				}
				case 2:{
					break;
				}
				case 3:{
					cout << endl << "Saliendo..." << endl;
					break;
				}
				default:{
					cout << endl << "Valor ingresado incorrecto!" << endl;
				}
			}
		}

	} else if(tipo == "manager"){

	} else if(tipo == "intern"){

	} else if(tipo == "supervisor"){

	}


	return 0; //return del main
}

int menuAdmin(){
	int opcion = 0;

	cout << endl << endl << "================== Menu ================" << endl << "¡Bienvenido admin!" << endl << endl;
	cout << "= Ingrese su opcion = " << endl << "1. Crear usuario." << endl
											<< "2. Eliminar usuario." << endl
											<< "3. Salir.";
	cin >> opcion;

	return opcion;
}