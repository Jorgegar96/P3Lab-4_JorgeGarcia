#include "Parqueo.h"
#include "Carro.h"

#include <string>
#include <iostream>

using namespace std;

Parqueo::Parqueo(){
	
}

Parqueo::Parqueo(int no_pisos, int capacidad_m, int capacidad_n, double altura){
	this->no_pisos = no_pisos;
	this->capacidad_m = capacidad_m;
	this->capacidad_n = capacidad_n;
	this->altura = altura;
	crearCasillas();
}

void Parqueo::crearCasillas(){
	casillas = new Carro***[no_pisos];
	for (int i=0; i < no_pisos; i++){
		casillas[i] = new Carro**[capacidad_n];
		for (int j=0; j < capacidad_n; j++){
			casillas[i][j] = new Carro*[capacidad_m];
			for(int k=0; k < capacidad_m; k++){
				casillas[i][j][k] = NULL;
			}
		}
	}
}

int Parqueo:: getNo_pisos(){
	return no_pisos;
}

void Parqueo:: setNo_pisos(int no_pisos){
	this->no_pisos = no_pisos;
}

int Parqueo:: getCapacidad_m(){
	return capacidad_m;
}

void Parqueo:: setCapacidad_m(int capacidad_m){
	this-> capacidad_m = capacidad_m;
}

int Parqueo:: getCapacidad_n(){
	return capacidad_n;
}

void Parqueo:: setCapacidad_n(int capacidad_n){
	this->capacidad_n = capacidad_n;
}

Carro**** Parqueo:: getCarros(){
	return casillas;
}

void Parqueo:: setCarros(Carro**** casillas){
	this->casillas = casillas;
}

void Parqueo:: agregarCarro(Carro* carro, int piso){
	bool agregado = false;
	for (int x=0; x < capacidad_n; x++){
		for (int y=0; y < capacidad_m; y++){
			if (!agregado && casillas[piso][capacidad_n][capacidad_m]==NULL){
				casillas[piso][capacidad_n][capacidad_m] = carro;
				cout<<"Parqueado"<<endl;
				agregado = true;
			}
		}
	}
}

Parqueo:: ~Parqueo(){
	for (int i=0; i < no_pisos; i++){
		for (int j=0; j < capacidad_n; j++){
			for(int k=0; k < capacidad_m; k++){
				casillas[i][j][k] = NULL;
				delete casillas[i][j][k];
			}
			delete[] casillas[j][j];
		}
		delete casillas[i];
	}	
}
