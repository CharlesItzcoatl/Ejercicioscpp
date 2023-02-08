/*Escribir un programa con una función que busque un caracter determinado en una cadena. El nombre de la función será BuscarCaracter. Debe devolver un int con la
  posición en que fue encontrado el caracter, si no se encontró volverá con -1. Los parámetros de entrada serán una cadena y un caracter.
*/
#include <iostream>
#include <string.h>
using namespace std;

struct Cadenas
{
	Cadenas();
	char Cadenita[100],caracter;
	int a;
	void Leer(Cadenas*);
	int BuscarCaracter(char*, char);
	void Display();
}Chain;

int BuscarCaracter(char *Entrada, char Caracter)
{
	int Entero=1;//Donde se guardará la posición en que se encuentra el caracter buscado.
		for(Entrada;*Entrada!=Caracter;Entrada++)
		{
			Entero++;
			if(*Entrada==0) 
			{
				Entero=-1;
				break;
			}
		}
	return Entero;
}

void Leer(Cadenas* VLocal)
{
	system("cls");
	cout<<"Introduce la cadenita:"<<endl;
	fflush(stdin);
	gets(VLocal->Cadenita);
	cout<<"Que caracter deseas buscar?"<<endl;
	cin>>VLocal->caracter;
	cout<<endl<<VLocal->Cadenita<<endl;
	return;
}

void Display(Cadenas* VLocal)
{
	if(VLocal->a>=1) cout<<"El caracter se encuentra en la posicion: "<<VLocal->a<<" de la cadena."<<endl;
	else cout<<"El caracter no se encuentra en la cadena."<<endl;
	return;
}

int main()
{
	Cadenas* p;
	p=&Chain;
	char Respuesta='N';
	do
	{
		Leer(p);
		Chain.a=BuscarCaracter(Chain.Cadenita,Chain.caracter);
		Display(p);
		cout<<"Repetir? Y/N"<<endl;
		cin>>Respuesta;
	}
	while(Respuesta=='Y'||Respuesta=='y');
  	return 0;	
}

Cadenas::Cadenas()
{
	for(int i=0;i<=99;i++) Cadenita[i]='0';
	caracter='0';
	a=0;
}
