#include <string>
#include "Carro.h"

using namespace std;

#ifndef PARQUEO_H
#define PARQUEO_H

class Parqueo{
	
	private:
		int no_pisos;
		int capacidad_m;
		int capacidad_n;
		double altura;
		Carro**** casillas;

	public:
		Parqueo();
		Parqueo(int, int, int, double);
		int getNo_pisos();
		void setNo_pisos(int);
		int getCapacidad_m();
		void setCapacidad_m(int);
		int getCapacidad_n();
		void setCapacidad_n(int);
		double getAltura();
		void setAltura(double);
		Carro**** getCarros();
		void setCarros(Carro****);
		void crearCasillas();
		void agregarCarro(Carro*, int);
		~Parqueo();
};

#endif

