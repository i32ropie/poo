#ifndef JUGADOR_H
#define JUGADOR_H


#include <string>
#include <list>
#include "persona.h"

using namespace std;

struct Apuesta
{
	int tipo;
	string valor;
	int cantidad;
};



class Jugador:public Persona
{
	private:
		int dinero_;
		string codigo_;
		list<Apuesta> apuestas_;

	public:
		Jugador(string DNI, string codigo, int dinero=1000, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		void setCodigo(string codigo){codigo_=codigo;}
		string getCodigo(){return codigo_;}
		void setDinero(int dinero){dinero_=dinero;}
		int getDinero(){return dinero_;}
		list<Apuesta> getApuestas(){return apuestas_;}
		void setApuestas();

};

void mostrarLista(list<Apuesta> apuestas);


#endif