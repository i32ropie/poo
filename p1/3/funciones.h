//Autor: Eduardo Roldán Pijuán.
//Descripción: Cabeceras del ejercicio 3 de la práctica 1 de POO.

#ifndef FUNCIONES_H
#define FUNCIONES_H

	class Dados
	{
		private:
			int d1_;
			int d2_;
		public:
			Dados(); //Constructor.
			void lanzamiento();
			int getDado1();
			int getDado2();
			bool setDado1(int dado_);
			bool setDado2(int dado_);
			int getSuma();		
	};



#endif