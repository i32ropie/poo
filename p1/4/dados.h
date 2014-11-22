//Autor: Eduardo Roldán Pijuán.
//Descripción: Cabeceras del ejercicio 3 de la práctica 1 de POO.

#ifndef DADOS_H
#define DADOS_H

	class Dados
	{
		private:
			int d1_;
			int d2_;
		public:
			Dados(); //Constructor.
			void lanzamiento();
			int getDado1(){return d1_;}
			int getDado2(){return d2_;}
			bool setDado1(int dado_);
			bool setDado2(int dado_);
			int getSuma(){return getDado1()+getDado2();}
			int diferencia();
	};



#endif