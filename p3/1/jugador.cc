#include <list>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "persona.h"
#include "jugador.h"

using namespace std;

Jugador::Jugador(string DNI, string codigo, int dinero, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais):Persona(DNI,nombre,apellidos,direccion,localidad,provincia,pais)
{
	setCodigo(codigo);
	setDinero(dinero);
}

void Jugador::setApuestas()
{
	char linea[256];
	struct Apuesta aux;
	apuestas_.clear();
	//Con lo siguiente, cojo el DNI del jugador, le añado ".txt", y luego transformo el string a char*.
	string nombre1;
	nombre1=getDNI()+".txt"; 
	int len=nombre1.length();
	char *nombre2 = new char[len+1];
	strcpy(nombre2,nombre1.c_str()); 
	ifstream fichero (nombre2);
	if(fichero.is_open())
	{
		while(fichero.getline(linea,256,','))
		{
			aux.tipo=atoi(linea);
			fichero.getline(linea,256,',');
			aux.valor=linea;
			fichero.getline(linea,256);
			aux.cantidad=atoi(linea);
			apuestas_.push_back(aux);
		}
		fichero.close();
	}
}

void mostrarLista(list <Apuesta> apuestas)
{
	list <Apuesta>::iterator i;
	Apuesta aux;

	for(i = apuestas.begin() ; i != apuestas.end() ; i++)
	{
		cout << "Tipo de apuesta: <" << (*i).tipo << "> Valor: <" << (*i).valor << "> Cantidad: <" << (*i).cantidad << ">.\n" ;
	}
}