//Autor: Eduardo Roldán Pijuán
//Descripción: Cabecera de la clase Persona

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
//#include <iostream>
using namespace std;

class Persona
{
	private:
		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;

	public:
		Persona(string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		void setDNI(string dni){DNI_=dni;}
		string getDNI(){return DNI_;}
		void setNombre(string nombre){nombre_=nombre;}
		string getNombre(){return nombre_;}
		void setApellidos(string apellidos){apellidos_=apellidos;}
		string getApellidos(){return apellidos_;}
		void setDireccion(string direccion){direccion_=direccion;}
		string getDireccion(){return direccion_;}
		void setLocalidad(string localidad){localidad_=localidad;}
		string getLocalidad(){return localidad_;}
		void setProvincia(string provincia){provincia_=provincia;}
		string getProvincia(){return provincia_;}
		void setPais(string pais){pais_=pais;}
		string getPais(){return pais_;}
		string getApellidosyNombre();

};



#endif