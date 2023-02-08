/*
	- Buscar el m�nimo posible de monedas para obtener el cambio total N, tomando monedas del set coinSet[].
	- Necesitamos un auxiliar "res" stack recursivo.
	- Crear una funci�n recursiva para encontrar el valor.
	- Retornar "monedas necesarias para el cambio".
*/

#include <iostream>
#include<climits> 	// Dtecci�n de tama�os de variables.

using namespace std;

int greedyChange(int coinSet[], int n, int N) // n es la cantidad de monedas de distinta denominaci�n, en este caso, 5 (1, 5, 10, 15, 20).
{
	if(N==0) return 0; // Si el cambio es cero, entonces no hay nada.
	if(N<0) return INT_MAX; //Si el cambio es negativo, error de lectura o algo as�. Regresa el valor entero m�s grande posible.
	int coins = INT_MAX; // Inicializa la variable coins en el m�ximo.
	
	//Recorre todo el set de monedas.
	for(int i=0;i<n;i++)
	{
		int res = greedyChange(coinSet, n, N-coinSet[i]); // El mismo conjunto, la misma cantidad de monedas...
		if(res != INT_MAX) coins = min(coins, res+1);
		cout<<coins<<endl;
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
