#include "Edificio.h"
#include "Carro.h"
#include "Parqueo.h"

#include <iostream>
#include <string>

using namespace std;

int main();
//Menu
int menu();

//Metodos 
Edificio* crearEdificio(Edificio*);

void parquearCarro(Edificio*);

//void listarDisponibles();

//void sacarCarro();

int main(){
	
	bool salir = false;
	Edificio* edificio = NULL;
	while (!salir){
		switch(menu()){
			case 1:
				edificio = crearEdificio(edificio);
				break;
			case 2:
				parquearCarro(edificio);
				break;
			case 3:
				//listarDisponibles();
				break;
			case 4:
				//sacarCarro();
				break;
			case 5:
				salir = true;
				break;
		}
	}
	return 0;
}

void parquearCarro(Edificio* edificio){
	cout<<"Ingrese la altura del carro"<<endl;
	double altura;
	cin>>altura;
	cout<<"Ingrese el color del carro"<<endl;
	string color;
	cin>>color;
	cout<<"Ingrese la marca del carro"<<endl;
	string marca;
	cin>> marca;
	cout<<"Seleccione el piso del edificio"<<endl;
	int piso;
	cin>>piso;
	if (altura > (*edificio).getNo_pisos()){
		cout<<"La altura del carro excede la permitida"<<endl;
	}else{
		Carro* carro = new Carro(altura, color, marca);
		((*(*edificio).getParqueo()).agregarCarro(carro, piso));
	}

}

Edificio* crearEdificio(Edificio* edificio){
	cout<<"Ingrese la altura del edificio"<<endl;
	int altura;
	cin>>altura;
	bool seguir = false;
	int no_personas;
	while (!seguir){
		cout<<"Ingrese la capacidad maxima de personas"<<endl;
		cin>>no_personas;
		if (no_personas>=50 && no_personas <=200){
			seguir=true;
		}else{
			cout<<"Debe ser entre 50 y 200"<<endl;
		}
	}
	Edificio* temporal = new Edificio(altura, no_personas);
	cout<<"Ingrese la altura del parqueo"<<endl;
	double height;
	cin>>height;
	(*temporal).crearParqueo(height);
	return temporal;
	
}

int menu(){
	cout<<"Menu:"<<endl
	    <<"1) Crear Edificio"<<endl
	    <<"2) Parquear Carro"<<endl
	    <<"3) Sacar Carro"   <<endl
	    <<"4) Ver Libres"    <<endl
	    <<"5) Salir"<<endl
	;
	int opcion;
	cin>>opcion;
	return opcion;
}
