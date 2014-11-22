//Autor: Eduardo Roldán Pijuán.
//Descripción: Main del ejercicio 3 de la práctica 1 de POO.
#include "dados.h"
#include <iostream>

using namespace std;

int main()
{
	Dados d; //Creamos variable tipo Dados.
	d.lanzamiento(); //Llamamos a la función lanzamiento desde la variable creada anteriormente.
	cout << "Valor del primer dado: " << d.getDado1() << endl ; //Obtenemos el valor del primer dado con getDado1
	cout << "Valor del segundo dado: " << d.getDado2() << endl ; 
	cout << "Valor de la suma de los dos dados: " << d.getSuma() << endl ;
	cout << "Valor de la diferencia entre el dado mayor y el dado menor: " << d.diferencia() << endl ;

	return 1;
}