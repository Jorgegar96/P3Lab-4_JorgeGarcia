#include "Carro.h"

#include <iostream>
#include <string>

using namespace std;

Carro::Carro(){
	altura = 0;
	color = "Azul";
	marca = "BMW";
}

Carro::Carro(double altura, string color, string marca){
	this->altura = altura;
	this->color = color;
	this->marca = marca;
}

double Carro::getAltura(){
	return altura;
}

void Carro::setAltura(double altura){
	this->altura = altura;
}

string Carro::getColor(){
	return color;
}

void Carro::setColor(string color){
	this->color = color;
}

string Carro::getMarca(){
	return marca;
}

void Carro::setMarca(string marca){
	this->marca = marca;
}

Carro::~Carro(){
	cout<<"El carro ha sido eliminado";
}
