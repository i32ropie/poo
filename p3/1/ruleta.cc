#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdlib>
#include <cstring>
#include "persona.h"
#include "ruleta.h"
#include "jugador.h"
#include "crupier.h"

using namespace std;
//FUNCION QUE TRANSFORMA UN STRING PASADO COMO PARÁMETRO EN UN CHAR*. SIRVE PARA ABRIR FICHEROS POR EJEMPLO.
char *stringToChar(string aux1){
	int len=aux1.length();
	char *aux2 = new char[len+1];
	strcpy(aux2,aux1.c_str());
	return aux2;
}
//CONSTRUCTOR DE LA CLASE RULETA
Ruleta::Ruleta(Crupier crupier1){
	setCrupier(crupier1);
	bola_=-1;
	banca_=1000000;
}
//FUNCION QUE ACTUALIZA EL VALOR DE banca_ PERO SOLO SI SE LE PASA UN ENTERO POSITIVO.
bool Ruleta::setBanca(int banca){
	if(banca<=0)
	{
		cout << "El valor de banca debe ser positivo. No se ha actualizado el valor de banca. Abortando programa." << endl;
		return false;
	}
	else
	{
		banca_=banca;
		cout << "El valor de banca se ha actualizado correctamente." << endl;
		return true;
	}
}
//FUNCION QUE ACTUALIZA EL VALOR DE bola_ PERO SOLO SI SE PASA UN ENTERO ENTRO 0 Y 36
bool Ruleta::setBola(int bola){
	if((bola<0) || (bola>36))
	{
		cout << "El valor de la bola debe estar entre 0 y 36. No se ha actualizado el valor de la bola." << endl;
		return false;
	}
	else
	{
		bola_=bola;
		cout << "El valor de la bola se ha actualizado correctamente." << endl;
		return true;
	}
}
//FUNCION QUE RECIBE UN JUGADOR COMO PARAMETRO Y AÑADE EL JUGADOR AL FINAL DE LA LISTA DE JUGADORES Y CREA UN FICHERO DE TIPO TEXTO DE APUESTAS VACIO. EL FICHERO DEBE LLAMARSE 'DNI.txt' SIENDO DNI EL DNI DEL JUGADOR. SI EL FICHERO EXISTE, LO DEJA COMO ESTABA SIN MODIFICARLO NI BORRARLO.
void Ruleta::addJugador(Jugador j){
	string aux1;
	aux1=j.getDNI()+".txt";
	ifstream fichero (stringToChar(aux1));
	if(fichero.is_open())
	{
		fichero.close();
		jugadores_.push_back(j);
		cout << "Jugador " << j.getNombre() << " añadido correctamente." << endl;
	}
	else
	{
		ofstream fichero (stringToChar(aux1));
		fichero.close();
		jugadores_.push_back(j);
		cout << "Jugador " << j.getNombre() << " añadido correctamente." << endl;
	}
}
//FUNCION QUE SE LE PASA UN JUGADOR Y LO BORRA DE LA LISTA. SI LA LISTA ESTÁ VACÍA DEVUELVE -2, SI EL JUGADOR NO ESTÁ EN LA LISTA -1, Y SI ESTÁ 1.
int Ruleta::deleteJugador(Jugador j){
	list<Jugador>::iterator i;
	string aux=j.getDNI();
	if(jugadores_.empty())
	{
		cout << "La lista está vacía." << endl;
		return -2;
	}
	for(i=jugadores_.begin() ; i!=jugadores_.end() ; ++i)
	{
		if(((*i).getDNI())==(aux))
		{
			jugadores_.erase(i);
			cout << "Jugador " << (*i).getNombre() << " con DNI " << (*i).getDNI() << " borrado correctamente." << endl;
			return 1;
		}
	}
	cout << "El jugador " << (*i).getNombre() << " con DNI " << (*i).getDNI() << " no se encuentra en la lista." << endl;
	return -1;
}
//FUNCION QUE SE LE PASA UN DNI Y BORRA EL JUGADOR DE LA LISTA. SI LA LISTA ESTÁ VACÍA DEVUELVE -2, SI EL JUGADOR NO ESTÁ EN LA LISTA -1, Y SI ESTÁ 1.
int Ruleta::deleteJugador(string DNI){
	list<Jugador>::iterator i;
	if(jugadores_.empty())
	{
		cout << "La lista está vacía." << endl;
		return -2;
	}
	for(i=jugadores_.begin() ; i!=jugadores_.end() ; ++i)
	{
		if(((*i).getDNI())==(DNI))
		{
			jugadores_.erase(i);
			cout << "Jugador " << (*i).getNombre() << " con DNI " << (*i).getDNI() << " borrado correctamente." << endl;
			return 1;
		}
	}
	cout << "El jugador " << (*i).getNombre() << " con DNI " << (*i).getDNI() << " no se encuentra en la lista." << endl;
	return -1;
}
//FUNCION QUE ABRE EL ARCHIVO jugadores.txt BORRA LO QUE TIENE DENTRO Y LO RELLENA CON LO QUE HAY EN LA LISTA DE JUGADORES.
void Ruleta::escribeJugadores(){
	ofstream fichero ("jugadores.txt");
	list<Jugador>::iterator i;
	for(i=jugadores_.begin() ; i!=jugadores_.end() ; i++)
	{
		fichero << (*i).getDNI();
		fichero << ',' ;
		fichero << (*i).getCodigo();
		fichero << ',' ;
		fichero << (*i).getNombre();
		fichero << ',' ;
		fichero << (*i).getApellidos();
		fichero << ',' ;
		fichero << (*i).getDireccion();
		fichero << ',' ;
		fichero << (*i).getLocalidad();
		fichero << ',' ;
		fichero << (*i).getProvincia();
		fichero << ',' ;
		fichero << (*i).getPais();
		fichero << ',' ;
		fichero << (*i).getDinero();
		fichero << endl;
	}
	fichero.close();
}
//FUNCION QUE BORRA LA LISTA DE JUGADORES ACTUAL Y LA ACTUALIZA CON LOS DATOS DEL FICHERO jugadores.txt
void Ruleta::leeJugadores(){
	char linea[256];
	Jugador aux("","");
	jugadores_.clear();
	cout << "Lista de jugadores borrada." << endl;
	ifstream fichero ("jugadores.txt");
	while(fichero.getline(linea,256,','))
	{
		aux.setDNI(linea);
		fichero.getline(linea,256,',');
		aux.setCodigo(linea);
		fichero.getline(linea,256,',');
		aux.setNombre(linea);
		fichero.getline(linea,256,',');
		aux.setApellidos(linea);
		fichero.getline(linea,256,',');
		aux.setDireccion(linea);
		fichero.getline(linea,256,',');
		aux.setLocalidad(linea);
		fichero.getline(linea,256,',');
		aux.setProvincia(linea);
		fichero.getline(linea,256,',');
		aux.setPais(linea);
		fichero.getline(linea,256);
		aux.setDinero(atoi(linea));
		jugadores_.push_back(aux);
	}
	fichero.close();
	cout << "Lista de jugadores actualizada con los valores guardados en el fichero." << endl;
}
//FUNCION QUE SEGUN LA OPCION DEL USUARIO DEVUELVE 1 O 2.
int Ruleta::getType(string opcion){
	if(opcion=="rojo")
		return 1;
	if(opcion=="negro")
		return 2;
	if(opcion=="par")
		return 1;
	if(opcion=="impar")
		return 2;
	if(opcion=="alto")
		return 1;
	if(opcion=="bajo")
		return 2;
	return -1;
}
//FUNCION QUE DEVUELVE TRUE SI LA BOLA ES ROJA Y FALSE SI LA BOLA ES NEGRA.
bool Ruleta::checkColour(){
	int aux=getBola();
	if(aux==1 || aux==3 || aux==5 || aux==7 || aux==9 || aux==10 || aux==14 || aux==16 || aux==18 || aux==19 || aux==21 || aux==23 || aux==25 || aux==27 || aux==30 || aux==32 || aux==34 || aux==36)
		return true;
	else
		return false;	
	cout << "Si lee este mensaje es que hubo un error comprobando el color de la bola." << endl;
}
//FUNCION QUE SIMULA EL GIRO DE LA RULETA Y LA OBTENCION DE UN NUMERO ALEATORIO ENTRE 0 Y 36.
void Ruleta::giraRuleta(){
	int aux;
	do
	{
		aux=rand()%37;
	}while(setBola(aux)); //En caso de que no se haya guardado un valor correcto, volvería a intentarlo.
}
//FUNCION QUE ASIGNA LOS PREMIOS, UN FOLLÓN TOTAL, MIRAR LA DOCUMENTACIÓN QUE HAY EN LA PROPIA FUNCIÓN.
void Ruleta::getPremios(){
	list<Jugador>::iterator i;
	char linea[256];
	for(i=jugadores_.begin() ; i!=jugadores_.end() ; ++i) //Recorro la lista.
	{
		string aux1;
		aux1=(*i).getDNI()+".txt";
		ifstream fichero (stringToChar(aux1)); //Abrimos el fichero usando la función super guay stringToChar.
		if(fichero.is_open()) //Abro cada documento del jugador.
		{
			while(fichero.getline(linea,256,',')) //Compruebo el primer campo de la linea, que corresponde al tipo de apuesta.
			{
				switch(atoi(linea))
				{
					case 1: //Si es 1, compruebo el valor que el jugador introdujo y lo comparo con el de la bola.
						fichero.getline(linea,256,',');
						if(atoi(linea)==bola_) //Si el jugador acertó...
						{
							fichero.getline(linea,256);
							if(setBanca(getBanca()-atoi(linea)*35)) //...se le retira el dinero a la banca (apuesta * 35)...
								(*i).setDinero((*i).getDinero()+atoi(linea)*34); //...y se le añade al jugador. (Multiplicamos por 34 porque no se le quitamos al hacer la apuesta dinero.)
							else
								exit(EXIT_FAILURE);
						}
						else //Si el jugador falló...
						{
							fichero.getline(linea,256);
							if(setBanca(getBanca()+atoi(linea))) //...la banca gana el dinero de la apuesta...
								(*i).setDinero((*i).getDinero()-atoi(linea)); //...y el jugador lo pierde.
							else
								exit(EXIT_FAILURE);
						}
						break;
					case 2: //Si es dos, compruebo si elijó Rojo o Negro con la función getType.
						fichero.getline(linea,256,',');
						switch(getType(linea))
						{
							case 1: //Si devuelve 1, es que el jugador escogió rojo.
								if(checkColour()) //Con checkColour comprobamos si la bola es roja, si lo es...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()-atoi(linea))) //...le quitamos el dinero a la banca...
										(*i).setDinero((*i).getDinero()+atoi(linea)); //...y se lo damos al jugador.
									else
										exit(EXIT_FAILURE);
								}
								else //Si devuelve false...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()+atoi(linea))) //...dinerito para la banca...
										(*i).setDinero((*i).getDinero()-atoi(linea)); //...y fuera del bolsillo del jugador.
									else
										exit(EXIT_FAILURE);
								}
								break;
							case 2: //Si devuelve 2, es que el jugador escogió negro.
								if(checkColour()) //Con checkColour(2) comprobamos si la bola es negra, en este caso, si devuelve true...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()+atoi(linea))) //...dinerito para la banca...
										(*i).setDinero((*i).getDinero()-atoi(linea)); //...y fuera del bolsillo del jugador.
									else
										exit(EXIT_FAILURE);
								}
								else //Si devuelve false...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()-atoi(linea))) //...es que ha ganado el jugador y quitamos dinero a la banca...
										(*i).setDinero((*i).getDinero()+atoi(linea)); //...y se lo damos al jugador.
									else
										exit(EXIT_FAILURE);
								}
								break;
							case -1:
								cout << "Hubo un fallo fatal, forzando evacuación del programa. " << endl; //Fallo con getType.
								fichero.close();
								exit(EXIT_FAILURE);
								break;
						}
						break;
					case 3: //Caso de par o impar
						fichero.getline(linea,256,',');
						switch(getType(linea)) //Si el jugador eligió par, getType devuelve 1, si fue impar, 2.
						{
							case 1: //Caso de que el jugador eligiera par.
								if(getBola()%2==0) //Si resulta que la bola era par...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()-atoi(linea))) //...le quitamos el dinero a la banca...
										(*i).setDinero((*i).getDinero()+atoi(linea)); //...y se lo damos al jugador.
									else
										exit(EXIT_FAILURE);
								}
								else //Si era impar la bola...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()+atoi(linea))) //...dinerito para la banca...
										(*i).setDinero((*i).getDinero()-atoi(linea)); //...y fuera del bolsillo del jugador.
									else
										exit(EXIT_FAILURE);
								}
								break;
							case 2: //Caso de que el jugador eligiera impar.
								if(getBola()%2!=0) //Si resulta que la bola era impar...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()-atoi(linea))) //...le quitamos el dinero a la banca...
										(*i).setDinero((*i).getDinero()+atoi(linea)); //...y se lo damos al jugador.
									else
										exit(EXIT_FAILURE);
								}
								else //Si era par la bola...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()+atoi(linea))) //...dinerito para la banca...
										(*i).setDinero((*i).getDinero()-atoi(linea)); //...y fuera del bolsillo del jugador.
									else
										exit(EXIT_FAILURE);
								}
								break;
							case -1:
								cout << "Hubo un fallo fatal, forzando evacuación del programa. " << endl; //Fallo con getType.
								fichero.close();
								exit(EXIT_FAILURE);
								break;
						}
						break;
					case 4: //Comprobamos si es alto o bajo con getType.
						fichero.getline(linea,256,',');
						switch(getType(linea))
						{
							case 1: //Caso que elija alto.
								if(getBola()>=19) //Si el jugador acertó porque la bola está entre 19 y 36...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()-atoi(linea))) //...le quitamos el dinero a la banca...
										(*i).setDinero((*i).getDinero()+atoi(linea)); //...y se lo damos al jugador.
									else
										exit(EXIT_FAILURE);
								}
								else //Si falló...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()+atoi(linea))) //...dinerito para la banca...
										(*i).setDinero((*i).getDinero()-atoi(linea)); //...y fuera del bolsillo del jugador.
									else
										exit(EXIT_FAILURE);
								}
								break;
							case 2: //Caso que elija bajo.
								if(getBola()<19) //Si el jugador acertó porque la bola está entre 19 y 36...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()-atoi(linea))) //...le quitamos el dinero a la banca...
										(*i).setDinero((*i).getDinero()+atoi(linea)); //...y se lo damos al jugador.
									else
										exit(EXIT_FAILURE);
								}
								else //Si falló...
								{
									fichero.getline(linea,256);
									if(setBanca(getBanca()+atoi(linea))) //...dinerito para la banca...
										(*i).setDinero((*i).getDinero()-atoi(linea)); //...y fuera del bolsillo del jugador.
									else
										exit(EXIT_FAILURE);
								}
								break;
							case -1:
								cout << "Hubo un fallo fatal, forzando evacuación del programa. " << endl; //Fallo con getType.
								fichero.close();
								exit(EXIT_FAILURE);
								break;
						}
						break;
					default:
						cout << "Error leyendo el tipo de apuesta." << endl;
				}
			}
		}
		else
		{
			cout << "El fichero correspondiente al jugador con DNI " << (*i).getDNI() << " no se abrió correctamente." << endl;
		}
	}
}

