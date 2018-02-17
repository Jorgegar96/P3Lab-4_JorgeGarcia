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

void listarDisponibles(Edificio*);

//void sacarCarro();
//
void listar(Carro****, int, int, int);

int main(){
	
	bool salir = false;
	Edificio* edificio;
	while (!salir){
		switch(menu()){
			case 1:
				edificio = crearEdificio(edificio);
				break;
			case 2:
				parquearCarro(edificio);
				break;
			case 4:
				listarDisponibles(edificio);
				//listar(edificio->getParqueo()->getCarros(), edificio->getParqueo()->getCapacidad_n(), edificio->getParqueo()->getCapacidad_m(), 2);
				break;
			case 3:
				//sacarCarro();
				break;
			case 5:
				salir = true;
				break;
		}
	}
	return 0;
}

void listar(Carro**** casillas, int capacidad_n, int capacidad_m, int piso){
	int cont_disp = 0;
	int cont_ocup = 0;

	for (int i=0; i<capacidad_n;i++){
		for (int j=0; j< capacidad_m; j++){
			if (casillas[piso][capacidad_n][capacidad_m]==NULL){
				cont_ocup++;
			}else{
				cont_disp++;
			}
		}
	}
	cout<<"Hay "<<cont_ocup<< " opcupados y " << cont_disp << " disponibles en el piso"<<endl;
}

void listarDisponibles(Edificio* edificio){
	cout<<"Que piso desea ver?"<<endl;
	int piso;
	cin>>piso;
	edificio->getParqueo()->listarParqueo(piso);
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
	if (altura > ((edificio)->getParqueo())->getAltura()){
		cout<<"La altura del carro excede la permitida"<<endl;
	}else{
		cout<<"1234";
		Carro* carro = new Carro(altura, color, marca);
		cout<<" "<<altura<<""<<piso<<""<<"";
		(((edificio)->getParqueo())->agregarCarro(carro,piso));
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
	(temporal)->crearParqueo(height);
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
