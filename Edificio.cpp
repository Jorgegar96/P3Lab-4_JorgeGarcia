#include "Parqueo.h"
#include "Edificio.h"

#include <string>
#include <iostream>

using namespace std;

Edificio:: Edificio(){

}

Edificio:: Edificio(int no_pisos, int no_personas){
	this->no_pisos = no_pisos;
	this->no_personas = no_personas;
}

void Edificio:: crearParqueo(double altura){
	int capacidad_n = no_personas/10;
	int capacidad_m;
	if (capacidad_n < 12){
		capacidad_m = capacidad_n*0.7;
	}else{
		capacidad_m = capacidad_n*0.4;
	}
	parqueo = new Parqueo(no_pisos, capacidad_m, capacidad_n, altura);
}

int Edificio:: getNo_pisos(){
	return no_pisos;
}

void Edificio:: setNo_pisos(int no_pisos){
	this->no_pisos = no_pisos;
}

int Edificio:: getNo_personas(){
	return no_personas;
}

void Edificio:: setNo_personas(int no_personas){
	this->no_personas = no_personas;
}

Parqueo* Edificio:: getParqueo(){
	return parqueo;
}

void Edificio:: setParqueo(Parqueo* parqueo){
	this->parqueo = parqueo;
}


