//Autor: Eduardo Roldán Pijuán.
//Descripción: Cabeceras del ejercicio 3 de la práctica 1 de POO.

#ifndef DADOS_H
#define DADOS_H

	class Dados
	{
		private:
			int d1_; //Valor dado 1
			int d2_; //Valor dado 2
			int sd1_; //Suma del total de los lanzamientos del dado 1
			int sd2_; //Suma del total de los lanzamientos del dado 2
			int contador1_; //Contador lanzamientos dado 1
			int contador2_; //Contador lanzamientos dado 2
		public:
			Dados(); //Constructor.
			void lanzamiento();
			int getDado1(){return d1_;} //Funciones inline
			int getDado2(){return d2_;}
			bool setDado1(int dado_);
			bool setDado2(int dado_);
			int getSuma(){return getDado1()+getDado2();}
			int diferencia();
			//Apartado a)
			int getLanzamiento1(){return contador1_-1;}
			int getLanzamiento2(){return contador2_-1;}
			//Apartado b) 
			float getMedia1(){return (float)getSumaDado1()/(float)contador1_;}
			float getMedia2(){return (float)getSumaDado2()/(float)contador2_;}
			int getSumaDado1(){return sd1_;}
			int getSumaDado2(){return sd2_;}
	};



#endif