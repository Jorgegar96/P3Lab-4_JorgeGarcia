#include <string>
#include "Parqueo.h"

using namespace std;

#ifndef EDIFICIO_H
#define EDIFICIO_H

class Edificio{
	
	private:
		int no_pisos;
		int no_personas;
		Parqueo* parqueo;

	public: 
		Edificio();
		Edificio(int, int);
		void crearParqueo(double);
		int getNo_pisos();
		void setNo_pisos(int);
		int getNo_personas();
		void setNo_personas(int);
		Parqueo* getParqueo();
		void setParqueo(Parqueo*);
		~Edificio();
};

#endif
