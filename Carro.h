#include <string>

using namespace std;

#ifndef CARRO_H
#define CARRO_H

class Carro{
	
	private:
		int altura;
		string color;
		string marca;

	public:
		Carro();
		Carro(double, string, string);
		double getAltura();
		void setAltura(double);
		string getColor();
		void setColor(string);
		string getMarca();
		void setMarca(string);
		~Carro();
};

#endif
