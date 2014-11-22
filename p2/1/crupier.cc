#include <string>
#include "crupier.h"
#include "persona.h"
using namespace std;

Crupier::Crupier(string DNI, string codigo, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais):Persona(DNI,nombre,apellidos,direccion,localidad,provincia,pais)
{
	//setDNI(DNI);
	setCodigo(codigo); //SOLO HACE FALTA ESTE OK? OK
	//setNombre(nombre);
	//setApellidos(apellidos);
	//setDireccion(direccion);
	//setLocalidad(localidad);
	//setProvincia(provincia);
	//setPais(pais);
}