/*Escribir un programa con una funci�n que calcule la longitud de una cadena de caracteres. El nombre de la funci�n ser� LongitudCadena, debe devolver un int,
  y como par�metro de entrada debe tener un puntero a char.
  En esta funci�n no se pueden usar enteros para recorrer el array, usar s�lo punteros y aplicar aritm�tica de punteros.
  En main probar con distintos tipos de cadenas: arrays y punteros.
*/
#include <iostream>

using namespace std;

//Prototipos:
int LongitudCadena(char*);

int main()
{
	char Cadenita[100];
	cout<<"Introduce la cadenita:"<<endl;
	gets(Cadenita);
	cout<<"La longitud de la cadenita es: "<<LongitudCadena(Cadenita);
  	return 0;	
}

int LongitudCadena(char *Entrada)//Al declarar esta entrada, se genera tanto un arreglo de entrada como el puntero correspondiente, que se inicializar�
{								 //apuntando al primer valor de la cadena
	int Entero=0;//Donde se guardar� la longitud de la cadena
	for(Entrada;*Entrada!=0;Entrada++) Entero ++;
	return Entero;
}
