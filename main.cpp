#include <iostream>
#include <vector>
#include <sstream>

#include "usuario.h"
#include "administrador.h"
#include "manager.h"
#include "intern.h"
#include "supervisor.h"

using namespace std;

int menuAdmin();
int menuSupervisor();
int menuManager();
int menuIntern();



int main(){

	vector <usuario*> users;


	string nom = "admin";
	string contraadmin = "master01";
	string fecha = "12/02/16";
	string correo = "420@hotmail.com";

	usuario* user = new administrador(nom, correo, fecha, contraadmin);

	users.push_back(user);

	int opcion = 0;

	int salir = 0;

	while(salir != 1){
		
		int opcion = 0;

		cout << endl << "Ingrese su contraseña: ";
		string pass  = "";

		cin >> pass;


		string tipo = "";
		int posicion = 0;

		for (int i = 0; i < users.size(); ++i)
		{
			if(contraadmin == pass){
				tipo = "admin";
			} else if( dynamic_cast<supervisor*> (users.at(i)) != NULL){
				if(pass == users.at(i) ->getPassword()){
					tipo = "supervisor";
					posicion = i;
				}
				tipo = "supervisor";
				posicion = i;
			} else if( dynamic_cast<intern*> (users.at(i)) != NULL){

				if(pass == users.at(i) ->getPassword()){
					tipo = "intern";
					posicion = i;
				}

			} else if( dynamic_cast<manager*> (users.at(i)) != NULL){
				if(pass == users.at(i) ->getPassword()){
					tipo = "manager";
					posicion = i;
				}
			}
	
		}

		cout << endl << "tipo: " << tipo;
		if(tipo == "admin"){ //administrador

			while(opcion != 3){
				opcion = menuAdmin();

				switch(opcion){
					case 1:{ //agregar usuario
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

							if(tipouser == 1){ //supervisor
								usuario* superviser = new supervisor(nombreusuario, correousuario, 0, passusuario);
								users.push_back(superviser);
								cout << endl << "El supervisor se ha agredado exitosamente.";
							} else if(tipouser == 2){ //intern
								cout << endl << "Ingrese los numeros de dia que ha trabajado esta persona: ";
								int dias = 0;
								cin >> dias;

								if(dias < 0){
									cout << endl << "... alguien no puede trabajar dias negativos...";
								} else{
									usuario* interno = new intern(nombreusuario, correousuario, dias, passusuario);
									users.push_back(interno);
									cout << endl << "El intern se ha agredado exitosamente.";
								} 

							} else if(tipouser == 3){
								cout << endl << "Ingrese el sueldo de este manager: ";
								int sueldo = 0;
								cin >> sueldo;

								if(sueldo < 0){
									cout << endl << "... alguien no puede tener sueldo negativo :c";
								} else{
									usuario* man = new manager(nombreusuario, correousuario, sueldo, passusuario);
									users.push_back(man);
									cout << endl << "El manager se ha agredado exitosamente.";
								}
							}
						}
						break;
					}
					case 2:{ //eliminar usuario

						cout << endl << endl << "Ingrese posicion del usuario que quiere eliminar: " << endl << endl;

						for (int i = 0; i < users.size(); ++i)
						{
							if(i == 0){

							} else{
								cout << i << ". " << users.at(i) -> getNombre() <<  " -> " << users.at(i) -> getTipo() << endl;
							}
						}

						int eliminar = 0;
						cin >> eliminar;

						if(eliminar <= 0){
							cout << endl << "No puede borrar esa posicion";
						} else{
							users.erase(users.begin() + eliminar);
							cout << endl << "El usuario ha sido borrado exitosamente.";
						}



						break;
					}
					case 3:{
						cout << endl << "Logging out..." << endl;
						break;
					}
					default:{
						cout << endl << "Valor ingresado incorrecto!" << endl;
					}
				}
			}

		} else if(tipo == "manager"){

			while(opcion != 3){
				opcion = menuManager();


				switch(opcion){
					case 1:{ //agregar usuario
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
									<< "2. Intern." << endl << endl;
						cin >> tipouser;

						if(tipouser > 2 || tipouser <= 0){
							cout << endl << "Valor ingresado es incorrecto :v" << endl;
						} else{

							if(tipouser == 1){ //supervisor
								usuario* superviser = new supervisor(nombreusuario, correousuario, 0, passusuario);
								users.push_back(superviser);
								cout << endl << "El supervisor se ha agredado exitosamente.";
							} else if(tipouser == 2){ //intern
								cout << endl << "Ingrese los numeros de dia que ha trabajado esta persona: ";
								int dias = 0;
								cin >> dias;

								if(dias < 0){
									cout << endl << "... alguien no puede trabajar dias negativos...";
								} else{
									usuario* interno = new intern(nombreusuario, correousuario, dias, passusuario);
									users.push_back(interno);
									cout << endl << "El intern se ha agredado exitosamente.";
								} 

							} 
						}
						break;
					}
					case 2:{ //eliminar usuario

						cout << endl << endl << "Ingrese posicion del usuario que quiere eliminar: " << endl << endl;

						
						
						for (int i = 0; i < users.size(); ++i)
						{
							if(i == 0){

							} else if(dynamic_cast<manager*> (users.at(i)) != NULL){
								cout << endl << "es manager";
							}else{
								cout << "Posicion para borrar: " << i << ". " << users.at(i) -> getNombre() <<  " -> " 
								<< users.at(i) -> getTipo() << endl;

							}
						}
						

						int eliminar = 0;
						cin >> eliminar;

						if(eliminar <= 0 || eliminar > users.size()){
							cout << endl << "No puede borrar esa posicion" << endl;
						} else if(posicion == eliminar){
							cout << endl << "No se puede borrar si mismo" << endl;
						}else{

							if(dynamic_cast<manager*> (users.at(eliminar)) != NULL){
								cout << endl << "No puede borrar otros managers";
							} else{
								users.erase(users.begin() + eliminar);
								cout << endl << "El usuario ha sido borrado exitosamente.";
							}
						}
						break;
					}
					case 3:{
						cout << endl << "Logging out..." << endl;
						break;
					}
					default:{
						cout << endl << "Valor ingresado incorrecto!" << endl;
					}
				}
			}

		} else if(tipo == "intern"){
			while(opcion != 3){
				opcion = menuManager();

				switch(opcion){
					case 1:{ //agregar usuario

						for (int i = 0; i < users.size(); ++i)
						{
							if(i == 0){

							} else if(dynamic_cast<manager*> (users.at(i)) != NULL){

							}else if(dynamic_cast<supervisor*> (users.at(i)) != NULL){

							} else{
								cout << "Posicion para borrar: " << i << ". " << users.at(i) -> getNombre() <<  " -> " 
								<< users.at(i) -> getTipo() << endl;

							}
						}
						
						break;
					}
					case 2:{ //eliminar usuario

						cout << endl << endl << "Ingrese posicion del usuario que quiere eliminar: " << endl << endl;

						
						
						for (int i = 0; i < users.size(); ++i)
						{
							if(i == 0){

							} else if(dynamic_cast<manager*> (users.at(i)) != NULL){

							}else if(dynamic_cast<supervisor*> (users.at(i)) != NULL){

							} else{
								cout << "Posicion para borrar: " << i << ". " << users.at(i) -> getNombre() <<  " -> " 
								<< users.at(i) -> getTipo() << endl;

							}
						}
						

						int eliminar = 0;
						cin >> eliminar;

						if(eliminar <= 0 || eliminar > users.size()){
							cout << endl << "No puede borrar esa posicion" << endl;
						} else if(posicion == eliminar){
							cout << endl << "No se puede borrar si mismo" << endl;
						}else{
							if( dynamic_cast<intern*> (users.at(eliminar)) != NULL){
								users.erase(users.begin() + eliminar);
								cout << endl << "El usuario ha sido borrado exitosamente.";
							} else{
								cout << endl << "Solo puede borrar interns";
							}
							
						}
						break;
					}
					case 3:{
						cout << endl << "Logging out..." << endl;
						break;
					}
					default:{
						cout << endl << "Valor ingresado incorrecto!" << endl;
					}
				}
			}

		} else if(tipo == "supervisor"){
			

			dynamic_cast<supervisor*> (users.at(posicion)) -> setVeces(dynamic_cast<supervisor*> (users.at(posicion)) -> getVeces() + 1);

			while(opcion != 2){

				opcion = menuSupervisor();

				switch(opcion){
					case 1:{
						for (int i = 0; i < users.size(); ++i)
						{
							cout << endl << i << ". " << "Nombre: " << users.at(i) -> getNombre() << " ; " << "Correo: " << 
							users.at(i) -> getCorreo() << " ; "  << "Pass: " << users.at(i) -> getPassword() << " ; ";

							if(dynamic_cast<manager*> (users.at(i)) != NULL){
								cout << "Sueldo: " << dynamic_cast<manager*> (users.at(i)) -> getSueldo() << endl;
							} else if(dynamic_cast<intern*> (users.at(i)) != NULL){
								cout << "Dias: " << dynamic_cast<intern*> (users.at(i)) -> getDias() << endl;
							}  else if(dynamic_cast<supervisor*> (users.at(i)) != NULL){
								cout << "Contador: " << dynamic_cast<supervisor*> (users.at(i)) -> getVeces() << endl;
							}  else if(dynamic_cast<administrador*> (users.at(i)) != NULL){
								cout << "Fecha: " << dynamic_cast<administrador*> (users.at(i)) -> getFecha() << endl;
							}
						}

						for (int i = 0; i < users.size(); ++i)
						{
							cout << endl << i << ". " << "Nombre: " << users.at(i) -> getNombre() << " ; " << "Correo: " << 
							users.at(i) -> getCorreo() << " ; "  << "Pass: " << users.at(i) -> getPassword() << " ; ";

							if(dynamic_cast<manager*> (users.at(i)) != NULL){
								cout << "Sueldo: " << dynamic_cast<manager*> (users.at(i)) -> getSueldo() << endl;
							} else if(dynamic_cast<intern*> (users.at(i)) != NULL){
								cout << "Dias: " << dynamic_cast<intern*> (users.at(i)) -> getDias() << endl;
							}  else if(dynamic_cast<supervisor*> (users.at(i)) != NULL){
								cout << "Contador: " << dynamic_cast<supervisor*> (users.at(i)) -> getVeces() << endl;
							}  else if(dynamic_cast<administrador*> (users.at(i)) != NULL){
								cout << "Fecha: " << dynamic_cast<administrador*> (users.at(i)) -> getFecha() << endl;
							}
						}

						break;
					}
					case 2:{
						cout << endl << "Saliendo..." << endl;
						break;
					}
					default:{
						cout << endl << "Ha ingresado un valor incorrecto" << endl;
						break;
					}
				}
			}
		}

		cout << endl << "Desea salir del programa?" << endl << "1. Si" << endl << "2. No" << endl << endl;
		cin >> salir;
	}



	return 0; //return del main
}

int menuAdmin(){
	int opcion = 0;
	cout << endl << " --------------------------------------- " << endl;
	cout << endl << endl << "================== Menu ================" << endl << "¡Bienvenido admin!" << endl << endl;
	cout << "= Ingrese su opcion = " << endl << "1. Crear usuario." << endl
											<< "2. Eliminar usuario." << endl
											<< "3. Logout." << endl << endl;
	cin >> opcion;

	return opcion;
}

int menuManager(){
	int opcion = 0;
	cout << endl << " --------------------------------------- " << endl;
	cout << endl << endl << "================== Menu ================" << endl << "¡Bienvenido Manager" 
	<<"!" << endl << endl;
	cout << "= Ingrese su opcion = " << endl << "1. Crear usuario." << endl
											<< "2. Eliminar usuario." << endl
											<< "3. Logout." << endl << endl;
	cin >> opcion;

	return opcion;
}

int menuIntern(){
	int opcion = 0;
	cout << endl << " --------------------------------------- " << endl;
	cout << endl << endl << "================== Menu ================" << endl << "¡Bienvenido intern!" << endl << endl;
	cout << "= Ingrese su opcion = " << endl << "1. Listar interns." << endl
											<< "2. Eliminar intern." << endl
											<< "3. Logout." << endl << endl;
	cin >> opcion;

	return opcion;
}

int menuSupervisor(){
	int opcion = 0;
	cout << endl << " --------------------------------------- " << endl;
	cout << endl << endl << "================== Menu ================" << endl << "¡Bienvenido supervisor!" << endl << endl;
	cout << "= Ingrese su opcion = " << endl << "1. Listar a todo mundo." << endl
											
											<< "2. Logout." << endl << endl;
	cin >> opcion;

	return opcion;
}