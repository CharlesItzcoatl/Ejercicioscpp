/*
	- Buscar el mínimo posible de monedas para obtener el cambio total N, tomando monedas del set coinSet[].
	- Necesitamos un auxiliar "res" stack recursivo.
	- Crear una función recursiva para encontrar el valor.
	- Retornar "monedas necesarias para el cambio".
*/

#include <iostream>
#include<climits> 	// Dtección de tamaños de variables.

using namespace std;

int greedyChange(int coinSet[], int n, int N)
{
	if(N==0) return 0;
	if(N<0) return INT_MAX;
	int coins = INT_MAX;
	
	//Recorre todo el set de monedas.
	for(int i=0;i<n;i++)
	{
		int res = greedyChange(coinSet, n, N-coinSet[i]);
		if(res != INT_MAX) coins = min(coins, res+1);
	}
	return coins;
}

int main()
{
	int coinSet[]={1, 5, 10, 15, 20};
	int n = sizeof(coinSet)/sizeof(coinSet[0]);
	int N = 27;
	cout<<"El minimo de monedas para dar cambio es: "<< greedyChange(coinSet, n, N)<<endl;
	cout<<INT_MAX;
	return 0;
}
