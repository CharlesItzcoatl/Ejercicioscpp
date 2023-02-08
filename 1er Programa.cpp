/*Escribir un programa que lea 10 valores enteros en un array y calcule y muestre la suma, el valor promedio, el mayor y menor
*/
#include <iostream>

using namespace std;

int main()
{
	int Lista[10];
	int i,suma=0,MAYOR=0,menor=0;
	float promedio=0.0;
	cout<<"Introduce la lista de 10 numeros enteros: "<<endl;
	for(i=0;i<=9;i++) 
	{
		cin>>Lista[i];
	}
	//SUMA
	for(i=0;i<=9;i++) suma+=Lista[i];
	cout<<"La suma de los numeros es: "<<suma<<endl;
	//PROMEDIO
	promedio=(float)suma/10;
	cout<<"El promedio es: "<<promedio<<endl;
	//MAYOR
	/* 0 5 8 2 4 1 3 7 6 9 ... comparo el primero con el segundo, si el segundo es mayor, ahora debo usar ese para compararlo con el resto
	
	   0 1 2 3 4 5 6 7 8 9 
		En una variable almacenar el nuevo valor más grande*/
	for(i=0;i<=9;i++)
	{
		if(Lista[i]>Lista[i+1]&&Lista[i]>=MAYOR)
		MAYOR=Lista[i];
		continue;
		MAYOR=Lista[i+1];
	}
	if(Lista[8]<Lista[9]&&Lista[9]>MAYOR) MAYOR=Lista[9];
	cout<<MAYOR<<" es el numero mas alto"<<endl;
	//menor
	for(i=0;i<=9;i++)
	{
		if(Lista[i]<Lista[i+1]&&Lista[i]<=menor)
		menor=Lista[i];
		continue;
		menor=Lista[i+1];
	}
	if(Lista[8]>Lista[9]&&Lista[9]<menor) menor=Lista[9];
	cout<<menor<<" es el numero mas bajo"<<endl;
	return 0;
}
