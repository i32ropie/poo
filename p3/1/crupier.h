#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>
using namespace std;


class Crupier : public Persona
{
	private:
		string codigo_;
	public:
		Crupier(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		void setCodigo(string codigo){codigo_=codigo;}
		string getCodigo(){return codigo_;}
};


#endif