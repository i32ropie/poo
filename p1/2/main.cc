#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int a,b,c;
	bool f;
	c=rand();
	a=c%10+1;
	do
	{
		cout << endl << "Introduce un numero entre 1 y 10, a ver si adivinas el que he pensado: ";
		cin >> b;
		if(a==b)
		{
			cout << "Enhorabuena, ha acertado el numero" << endl << endl;
		}
		else
		{
			if(a>b)
			{
				cout << "El numero que has introducido es menor que el que intentas adivinar." << endl;
			}
			else
			{
				cout << "El numero que has introducido es mayor que el que intentas adivinar." << endl;
			}
		}
	}while(a!=b);
	
	return 0;
}