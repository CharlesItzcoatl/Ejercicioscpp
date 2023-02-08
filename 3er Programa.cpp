/*Escribir un programa que lea 25 valores enteros en una tabla de 5x5 y que después muestre la tabla y las sumas de cada fila y de cada columna.
*/
#include <iostream>
using namespace std;
//Prototipos:
void Leer(void);
void Suma(void);
//Variables globales:
int Matriz[5][5];
int filas=0, columnas=0;
int SumaFilas[5]={0,0,0,0,0}, SumaColumnas[5]={0,0,0,0,0};

int main()
{
	Leer();
	Suma();
	return 0;	
}

void Leer(void)
{
	//Lee
	cout<<"Introduce los valores de la matriz 5x5\n";
	for(filas=0;filas<=4;filas++)//Cambiará la fila hasta que haya terminado de escribir las columnas
	{
		cout<<endl;
		for(columnas=0;columnas<=4;columnas++)
		{
			cout<<"Valor a("<<filas<<","<<columnas<<"): ";//a(0,0) -> a(0,1) -> a(0,2) -> a(0,3) -> a(0,4) -> a(1,0) -> a(1,1) -> a(1,2) -> ... -> a(4,4)
			cin>>Matriz[filas][columnas];//Se guardn en el orden anteriod
		}
	}
	//Muestra
	cout<<"La matriz generada es: "<<endl;
	for(filas=0;filas<=4;filas++)
	{
		cout<<endl;
		for(columnas=0;columnas<=4;columnas++)
		{
			cout<<Matriz[filas][columnas]<<" ";//Se genera la forma de matriz
		}
	}
}

void Suma(void)
{
	for(filas=0;filas<=4;filas++)
	{
		for(columnas=0;columnas<=4;columnas++)
		{
			SumaFilas[filas]+=Matriz[filas][columnas];//El vector SumaFilas guardará la suma total de elementos por fila
	//												  SumaFilas[0]=SumaFilas[0]+Matriz[0][0]+Matriz[0][1]+Matriz[0][2]+Matriz[0][3]+Matriz[0][4]
	//												  SumaFilas[1]=SumaFilas[1]+Matriz[1][0]+Matriz[1][1]+Matriz[1][2]+Matriz[1][3]+Matriz[1][4]
	//												  										.
	//												  										.
	//												  										.
	//												  SumaFilas[4]=SumaFilas[4]+Matriz[4][0]+Matriz[4][1]+Matriz[4][2]+Matriz[4][3]+Matriz[4][4]
			SumaColumnas[filas]+=Matriz[columnas][filas];//El vector SumaColumnas guardará la suma total de elementos de la columna
	//													 SumaColumnas[0]=SumaColumnas[0]+Matriz[0][0]+Matriz[1][0]+Matriz[2][0]+Matriz[3][0]+Matriz[4][0]
	//													 SumaColumnas[1]=SumaColumnas[1]+Matriz[0][1]+Matriz[1][1]+Matriz[2][1]+Matriz[3][1]+Matriz[4][1]
	//																						.
	//																						.
	//													 									.
	//													 SumaColumnas[4]=SumaColumnas[4]+Matriz[0][4]+Matriz[1][4]+Matriz[2][4]+Matriz[3][4]+Matriz[4][0]
		}
	}
	
	for(int i=0;i<=4;i++)//Iteración para mostrar cada uno de los elementos de los vectores Suma
	{
		cout<<"\nLa suma de la fila "<<i<<" es: "<<SumaFilas[i];//Se muestra el vector SumaFilas
		cout<<"\nLa suma de la columna "<<i<<" es : "<<SumaColumnas[i]<<endl;//Se muestra el vector SumaCOlumnas
	}
}
