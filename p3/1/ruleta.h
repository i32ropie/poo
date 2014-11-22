#ifndef _RULETA_H
#define _RULETA_H

#include "jugador.h"
#include "crupier.h"
#include <list>
#include <iostream>

using namespace std;

class Ruleta
{
private:
	int banca_; //Representa el dinero de la banca.
	int bola_;//Representa el valor de la bola en cada tirada.
	list<Jugador> jugadores_;//Lista de jugadores de la ruleta.
	Crupier crupier_(string DNI, string codigo);//Crupier de la ruleta.
public:
	Ruleta(Crupier crupier1); //Constructor que recibe el crupier de la ruleta.
	int getBanca(){return banca_;} //Funcion que devuelve el valor de banca_
	bool setBanca(int banca); //MIRAR ruleta.cc [line 30]
	int getBola(){return bola_;} //Funcion que devuelve el valor de bola_
	bool setBola(int bola); //MIRAR ruleta.cc [line 44]
	Crupier getCrupier(){return crupier_;} //Funcion que devuelve el valor de crupier_
	void setCrupier(Crupier crupier1); //Función que actualiza el valor de crupier_
	list<Jugador> getJugadores(){return jugadores_;} //Funcion que devuelve la lista de jugadores.
	void addJugador(Jugador j); //MIRAR ruleta.cc [line 58]
	int deleteJugador(Jugador j); //MIRAR ruleta.cc [line 77]
	int deleteJugador(string DNI); //MIRAR ruleta.cc [line 98]
	void escribeJugadores(); //MIRAR ruleta.cc [line 118]
	void leeJugadores(); //MIRAR ruleta.cc [line 145]
	int getType(string opcion); //MIRAR ruleta.cc [line 176]
	bool checkColour(); //MIRAR ruleta.cc [line 191]
	void giraRuleta(); //MIRAR ruleta.cc [line 200]
	void getPremios(); //MIRAR ruleta.cc [line 208]
};

char *stringToChar(string aux1);

#endif