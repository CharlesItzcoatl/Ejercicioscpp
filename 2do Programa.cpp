/*Escribir un programa que lea 10 valores enteros en un array y los muestre en pantalla. Que los ordene de menor a mayor y viceversa. Usar una función
con el método de la burbuja con el tipo de ordenación como parámetro. Para el array usar una variable global.
*/
#include <iostream>
using namespace std;

void Orden(int); 
int Lista[10];

int main()
{
	int i=0,Opcion;
	cout<<"Ingrese una lista de 10 numeros: "<<endl;
	for(i=0;i<=9;i++) cin>>Lista[i];
	cout<<"Ordenacion?\n\tMenor a mayor = 0\n\tMayor a menor = 1\nOpcion: ";
	cin>>Opcion;
	Orden(Opcion);
	for(i=0;i<=9;i++)
	{
		cout<<endl<<Lista[i];
	}
	return 0;
	
}

void Orden (int Resultado)
{
	int a;
	switch(Resultado)
	{
		case 0://Menor a Mayor
			for(int j=1;j<=9;j++)
			{
				for(int i=1;i<=9;i++)
				{	
					if(Lista[i-1]>Lista[i])
					{
						a=Lista[i];
						Lista[i]=Lista[i-1];
						Lista[i-1]=a;
					}	
				}	
			}
			break;
		case 1://Mayor a menor
			for(int j=1;j<=9;j++)
			{
				for(int i=1;i<=9;i++)
				{	
					if(Lista[i-1]<Lista[i])
					{
						a=Lista[i];
						Lista[i]=Lista[i-1];
						Lista[i-1]=a;
					}	
				}	
			}
			break;
	}
	return;
}
