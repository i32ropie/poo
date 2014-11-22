//Autor: Eduardo Roldán Pijuán.
//Descripción: Main del ejercicio 3 de la práctica 1 de POO.
#include "dados.h"
#include <iostream>

using namespace std;

int main()
{
	Dados d; //Creamos variable tipo Dados.
	int n;
	cout << "Introduce el numero de lanzamientos a realizar: ";
	cin >> n;
	while(n<=0)
	{
		cout << "El numero de lanzamientos tiene que ser al menos 1, indique cuantos lanzamientos desea realizar: ";
		cin >>n;
	}
	for(int i=0 ; i<n ; i++)
	{
		cout << endl << "Lanzamiento numero " << i+1 << endl ;
		d.lanzamiento(); //Llamamos a la función lanzamiento desde la variable creada anteriormente.
		cout << "Valor del primer dado: " << d.getDado1() << endl ; //Obtenemos el valor del primer dado con getDado1
		cout << "Valor del segundo dado: " << d.getDado2() << endl ; 
		cout << "Valor de la suma de los dos dados: " << d.getSuma() << endl ;
		cout << "Valor de la diferencia entre el dado mayor y el dado menor: " << d.diferencia() << endl ;
	}
	if(n>1)
	{
		cout << endl << "El dado 1 se ha lanzado " << d.getLanzamiento1() << " veces." << endl;
		cout << "El dado 2 se ha lanzado " << d.getLanzamiento2() << " veces." << endl;
	}
	else
	{
		cout << endl << "El dado 1 se ha lanzado " << d.getLanzamiento1() << " vez." << endl;
		cout << "El dado 2 se ha lanzado " << d.getLanzamiento2() << " vez." << endl;
	}

	cout << "La suma de los dados 1 es <" << d.getSumaDado1() << ">, dividido entre el numero de lanzamientos da una media de: " << d.getMedia1() << endl;
	cout << "La suma de los dados 2 es <" << d.getSumaDado2() << ">, dividido entre el numero de lanzamientos da una media de: " << d.getMedia2() << endl;
	
	

	return 1;
}