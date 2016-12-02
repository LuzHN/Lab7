main:	main.o administrador.o manager.o intern.o supervisor.o usuario.o
	g++ main.o administrador.o manager.o intern.o supervisor.o usuario.o -o main

main.o:	main.cpp administrador.h manager.h intern.h supervisor.h usuario.h
	g++ -c main.cpp

administrador.o:	usuario.h administrador.h administrador.cpp
	g++ -c administrador.cpp

manager.o:	usuario.h manager.h manager.cpp
	g++ -c manager.cpp

intern.o:	usuario.h intern.h intern.cpp
	g++ -c intern.cpp

supervisor.o:	usuario.h supervisor.h supervisor.cpp
	g++ -c supervisor.cpp

usuario.o:	usuario.h usuario.cpp
	g++ -c usuario.cpp

clean:
	rm -f *.o main
