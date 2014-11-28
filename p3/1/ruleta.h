#ifndef _RULETA_H
#define _RULETA_H

#include <string>
#include <list>
//#include <iostream>
#include "jugador.h"
#include "crupier.h"

//using namespace std;

class Ruleta
{
private:
	int banca_; //Representa el dinero de la banca.
	int bola_;//Representa el valor de la bola en cada tirada.
	list<Jugador> jugadores_;//Lista de jugadores de la ruleta.
	Crupier crupier_;//Crupier de la ruleta.
public:
	Ruleta(Crupier crupier1); //Constructor que recibe el crupier de la ruleta.
	int getBanca(void){return banca_;} //Funcion que devuelve el valor de banca_
	bool setBanca(int banca); //MIRAR ruleta.cc [line 30]
	int getBola(void){return bola_;} //Funcion que devuelve el valor de bola_
	bool setBola(int bola); //MIRAR ruleta.cc [line 44]
	Crupier getCrupier(void){return (crupier_);} //Funcion que devuelve el valor de crupier_
	void setCrupier(Crupier crupier1){crupier_=crupier1;} //Función que actualiza el valor de crupier_
	list<Jugador> getJugadores(void){return jugadores_;} //Funcion que devuelve la lista de jugadores.
	void addJugador(Jugador j); //MIRAR ruleta.cc [line 58]
	int deleteJugador(Jugador j); //MIRAR ruleta.cc [line 77]
	int deleteJugador(string DNI); //MIRAR ruleta.cc [line 98]
	void escribeJugadores(void); //MIRAR ruleta.cc [line 118]
	void leeJugadores(void); //MIRAR ruleta.cc [line 145]
	int getType(string opcion); //MIRAR ruleta.cc [line 176]
	bool checkColour(void); //MIRAR ruleta.cc [line 191]
	void giraRuleta(void); //MIRAR ruleta.cc [line 200]
	void getPremios(void); //MIRAR ruleta.cc [line 208]
};

char *stringToChar(string aux1);

#endif
