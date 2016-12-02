#ifndef usuario_h
#define usuario_h

#include <iostream>

using std::string;

class usuario{


	protected:
		string nombre;
		string correo;
		string password;
	public:

		usuario();
		usuario(string , string, string);
		virtual ~usuario();

		void setNombre(string);
		string getNombre();

		void setCorreo(string);
		string getCorreo();

		void setPassword(string);
		string getPassword();




};

#endif