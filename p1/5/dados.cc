//Autor: Eduardo Roldán Pijuán.
//Descripción: Funciones del ejercicio 3 de la práctica 1 de POO.

#include "dados.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Dados::Dados()
{
	srand(time(NULL)); //Creación de semilla.
	d1_=1; //Incialización del dado 1 a 1.
	d2_=1; //Incialización del dado 2 a 1.
	contador1_=1;
	contador2_=1;
	sd1_=0;
	sd2_=0;
}

void Dados::lanzamiento()
{
	int a,b; //Variables auxiliares para la generación de los valores de los dados.
	a=rand(); //Guardo en 'a' un número aleatorio.
	a=a%6+1; //Le hago módulo 6 y queda entre 0 y 5, por lo que le sumo uno.
	b=rand(); //Igual que en a.
	b=b%6+1;
	if(!setDado1(a)) //Como setDado1 devuelve 'true' si el número está entre 1 y 6, si no lo está, devolverá false y acabará el programa lanzando el error sucedido.
	{
		cout << "Error asignando el valor a los dados" << endl;
		exit(-1);
	}
	if(!setDado2(b))
	{
		cout << "Error asignando el valor a los dados" << endl;
		exit(-1);
	}
}

bool Dados::setDado1(int dado_) //Tipo bool. Devuelve 'true' si d1_ está entre 1 y 6 y 'false' en caso contrario.
{
	if(dado_<1 || dado_>6)	
		return false;
	else
	{
		contador1_++; //Contamos cada lanzamiento nuevo.
		d1_=dado_; //Asignamos dado 1.
		sd1_+=getDado1(); //Va sumado el resultado de los dado 1.
		return true;
	}
}

bool Dados::setDado2(int dado_) //Tipo bool. Devuelve 'true' si d2_ está entre 1 y 6 y 'false' en caso contrario.
{
	if(dado_<1 || dado_>6)	
		return false;
	else
	{
		contador2_++;
		d2_=dado_;
		sd2_+=getDado2();
		return true;
	}
}

int Dados::diferencia()
{
	if(getDado1()>getDado2())
		return getDado1()-getDado2();
	else
		return getDado2()-getDado1();
}