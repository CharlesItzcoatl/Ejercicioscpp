#include <iostream>
#define SIZE 5

using namespace std;

int Lista[SIZE]={0,0,0,0,0};
int *Inicial, *Final;


void In(int);
void Out(void);

int main()
{
	Final=Lista;
	Inicial=Lista;
	int Valor=0;
	In(5);
	In(7);
	Out();
	In(9);
	In(8);
	In(3);
	In(1);
	Out();
	Out();
	for(int i=0;i<SIZE;i++) cout<<Lista[i]<<endl;
	return 0;
}

void In(int Value)
{
	for(int i=0;i<SIZE;i++)
	{
		if(Lista[i]==0)
		{
			Final=&Lista[i];
			*Final=Value; // El último valor que se agregó
			return;
		}
		
	}
	
	Inicial=Final;// Inicial ahora apunta al mismo.
	Final++; // Mueve el puntero a la siguiente celda.
	return;
}

void Out()
{
	*Inicial=0; // Elimina el último valor que se insertó.
	Inicial=Final;
	return;
}

