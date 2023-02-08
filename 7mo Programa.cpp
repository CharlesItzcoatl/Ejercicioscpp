/*Escribir un programa con una funci�n que ordene un array de enteros. Debe recorrer el array simult�neamente desde el principio y el final, comparando los
  elementos. Cuando los punteros se crucen, indicar� que el orden es correcto. 
  Usar una funci�n con tres par�metros.
  --------------------->	void Ordenar(int* vector, int nElementos, bool ascendente);
  Usar s�lo aritm�tica de punteros.
*/
#include <iostream>
#include <string.h>
using namespace std;

//Prototipos:
void Ordenar(int*, int, bool);

int main()
{
	int n=0,Vector[20];
	bool Respuesta;
	cout<<"Cuantas componentes tendra el vector?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Componente "<<i+1<<": ";
		cin>>Vector[i];
	}
	cout<<"Ordenacion ascendente o descendente?\nAscendente = 0\nDescendente = 1\n"<<endl;
	cin>>Respuesta;
	Ordenar(Vector,n,Respuesta);
  	return 0;	
}

void Ordenar(int* Vector, int nElementos, bool Ascendente)
{
	int *Inicial, *Final, aux=0;
	Inicial=Vector;//Se inicializa en &Vector[0]
	Final=&Vector[nElementos-1];//Se inicializa en la direcci�n del �ltimo elemento de Vector
	switch(Ascendente)
	{
		case 0:
			while(Inicial!=Final)
			{
				if(*Inicial>*Final)
				{
					aux=*Inicial;
					*Inicial=*Final;
					*Final=aux;
				}
				Inicial++;
				Final--;
			}
	
			for(int i=0;i<nElementos;i++)
			{
				cout<<Vector[i]<<endl;
			}
			break;
		case 1:
			while(Inicial!=Final)
			{
				if(*Inicial<*Final)
				{
					aux=*Inicial;
					*Inicial=*Final;
					*Final=aux;
				}
				Inicial++;
				Final--;
			}
	
			for(int i=0;i<nElementos;i++)
			{
				cout<<Vector[i]<<endl;
			}
			break;
	}
	return;
}
