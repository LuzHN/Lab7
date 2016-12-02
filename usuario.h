#ifndef usuario_h
#define usuario_h

#include <iostream>

using std::string;

class usuario{


	private:
		string nombre;
		string correo;
		string password;
	public:

		usuario();
		virtual ~usuario();

		void setNombre(string);
		string getNombre();

		void setCorreo(string);
		string getCorreo();

		void setPassword(string);
		string getPassword();




};

#endif