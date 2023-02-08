/* 1) Para almacenar fechas podemos crear una estructura con tres campos: year, month y day. Los d�as pueden tomar valores entre 1 y 31. los meses entre 1 y 12 a�os y los a�os,
      dependiendo de la aplicaci�n, pueden requerir distintos rangos de valores. Para este ejemplo, consideraremos suficientes 128 a�os, entre 1960 y 2087. En este caso, el a�o se
   	  obtiene sumando 1960 al valor de year. El a�o 2003 se almacena como 43.
      Usando estructuras, y ajustando los tipos de los campos, necesitamos un char para day, un char para month y otro para year. 
      Dise�ar una estructura an�loga, llamada date, pero usando campos de bits. Usar s�lo un entero corto sin signo (unsigned short int), es decir, un entero de 16 bits. Los nombres de
      los campos ser�an: year, month y day. 
      
   2) Bas�ndose en la estructura de bits del ejercicio anterior, escribir una funci�n para mostrar fechas: void Mostrar(fecha);. El formato debe ser: "dd de mmmmmmmmmmm de aaaa", donde
   	  dd es el d�a, mmmmmmmmmm es el mes con letras, y aaaa, el a�o. Usar un array para almacenar los nombres de los meses.
   	  
   3) Bas�ndose en la estructura de bits del ejercicio anterior, escribir una funci�n bool ValidarFecha(fecha);, que verifique si la fecha entregada como par�metro es v�lida. El mes
      tiene que estar en el rango de 1 a 12, dependiendo del mes y del a�o, el d�a debe estar entre 1 y 28, 29, 30 � 31. El a�o siempre ser� v�lido, ya que debe estar en el rango de
      0 a 127. 
      Para validar los d�as usaremos un array int DiasMes[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};. Para el caso de que el mes sea febrero, crearemos otra funci�n para
      calcular si un a�o es bisiesto o no: bool Bisiesto(int);. Los a�os bisiestos son los divisibles entre 4, al menos en el rango de 1960 a 2087 se cumple. 
      
   4) Escribir dos funciones m�s. La primera debe responder a este prototipo: int Comparar(Date, Date);. Debe comparar las dos fechas suministradas y devolver '1' si la primera es
   	  mayor, '-1' si la segunda es mayor y '0' si son iguales.
*/
#include <iostream>
#include <string.h>

using namespace std;

// El n�mero de bytes en un unsigned short int es de dos, i. e., 16 bits. 
// Para day s�lo son necesarios 5 bits; para month, 4 bits; para year, 7. En total se requiere de todos los bits en un unsigned short int.

struct Date
{
	unsigned short int Day:5;		// Day ocupa 5 bits.
	unsigned short int Month:4;		// Month ocupa 4 bits.
	unsigned short int Year:7;		// Year ocupa 7 bits.
	Date();							// Constructor.
} ThisYear[2];		// ThisYear es una variable que contiene las caracter�sticas de d�a, mes y a�o.

void Mostrar(Date);
bool ValidarFecha(int[]);
bool Bisiesto(int);
int Comparar(Date, Date);	//Recibe dos par�metros de tipo Date.

int main()
{	
	int Vector[3]={0,0,0}; // Guarda d�a, mes y a�o.
	for(int i=0;i<=1;i++)
	{
		cout<<"Insert the day: "<<endl;
		cin>>Vector[0];
		cout<<"Insert the month: "<<endl;
		cin>>Vector[1];
		cout<<"Insert the year: "<<endl;
		cin>>Vector[2];
		if(ValidarFecha(Vector))
		{
			cout<<"Data has been saved"<<endl;
			ThisYear[i].Day=Vector[0];
			ThisYear[i].Month=Vector[1];
			ThisYear[i].Year=Vector[2];
		}
		else cout<<"Non valid date (parameter mistake)"<<endl;
		Mostrar(ThisYear[i]);
		cout<<endl;
	}
	switch(Comparar(ThisYear[0], ThisYear[1]))
	{
		case -1:
			cout<<Comparar(ThisYear[0], ThisYear[1])<<endl;
			cout<<ThisYear[1].Day<<"/"<<ThisYear[1].Month<<"/"<<ThisYear[1].Year+1960<<" es mayor que "<<ThisYear[0].Day<<"/"<<ThisYear[0].Month<<"/"<<ThisYear[0].Year+1960<<endl;
			break;
		case 0:
			cout<<Comparar(ThisYear[0], ThisYear[1])<<endl;
			cout<<ThisYear[1].Day<<"/"<<ThisYear[1].Month<<"/"<<ThisYear[1].Year+1960<<" es igual que "<<ThisYear[0].Day<<"/"<<ThisYear[0].Month<<"/"<<ThisYear[0].Year+1960<<endl;
			break;
		case 1:
			cout<<Comparar(ThisYear[0], ThisYear[1])<<endl;
			cout<<ThisYear[0].Day<<"/"<<ThisYear[0].Month<<"/"<<ThisYear[0].Year+1960<<" es mayor que "<<ThisYear[1].Day<<"/"<<ThisYear[1].Month<<"/"<<ThisYear[1].Year+1960<<endl;
	}
	return 0;
}

Date::Date()
{
	Day=0;
	Month=0;
	Year=0;
}

void Mostrar(Date Input)
{
	
	int i=0, j=0, aux=0;
	// Calendario es un vector que guarda 12 elementos tipo char, de tama�o 20 cada uno.
	char Calendario[12][20]={"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
	aux=Input.Month-1;
	switch(aux)
	{
		case 0:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[0][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 1:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i] != 0;i++) cout<<Calendario[1][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 2:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[2][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 3:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[3][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 4:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[4][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 5:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[5][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 6:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[6][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 7:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[7][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 8:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[8][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 9:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[9][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 10:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[10][i];
			cout<<" de "<<Input.Year+1960;
			break;
		case 11:
			cout<<Input.Day<<" de ";
			for(i=0;Calendario[aux][i]!=0;i++) cout<<Calendario[11][i];
			cout<<" de "<<Input.Year+1960;
			break;
				
	}
	return;
}

bool ValidarFecha(int Entrada[])
{
	bool Flag=false;
	int DiasMes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(Entrada[1]>=1 && Entrada[1]<=12) // Si el mes es 1 a 12...
	{
		if(Bisiesto(Entrada[2]+1960)) DiasMes[1]=29;			// Si el a�o es bisiesto...
		else DiasMes[1]=28;
		if(Entrada[0]<=DiasMes[Entrada[1]-1]) Flag=true;		// Si el n�mero de d�a ingresado es menor o igual que el elemento "Entrada[1]-1" de DiasMes...
	}
	return Flag;
}

bool Bisiesto (int Years)	// Regresa un '1' si el a�o es bisiesto (si el residuo de la divisi�n del a�o es igual a '0').
{
	bool Test=false;
	if(!(Years%4)) Test=true;
	return Test;
}

int Comparar(Date Uno, Date Dos)	// Devuelve 1 si la primera es mayor, -1 si la segunda es mayor y 0 si son iguales.
{
	int R=0;
	if(Uno.Year>Dos.Year) {R=1; return R;}
	if(Uno.Year<Dos.Year) {R=-1; return R;}
	if(Uno.Year==Dos.Year)
	{
		if(Uno.Month>Dos.Month) {R=1; return R;}
		if(Uno.Month<Dos.Month) {R=-1; return R;}
		if(Uno.Month==Dos.Month)
		{
			if(Uno.Day>Dos.Day) {R=1; return R;}
			if(Uno.Day<Dos.Day) { R=-1; return R;}
			if(Uno.Day==Dos.Day) { R=0; return R;}
		}
	}
	return R;
}
