// Funciones recursivas para números factoriales, serie de Fibonacci y palabras palíndromas.

#include<iostream>
#include<string.h>

using namespace std;

double Factorial (int);
long int Fibonacci(int);
int Palindromo(char*, char*);

int main()
{
	int n=0;
	char Cadena[20];
	for(n=0;n<=20;n++) cout<<Fibonacci(n)<<" ";
	cout<<"\nIntroduce el numero cuyo factorial quieres calcular: "<<endl;
	cin>>n;
	printf("%d! = %.0f\n",n, Factorial(n));
	//cout<<n<<"! = "<<Recursion(n)<<endl;
	cout<<"Introduce la palabra para saber si es palindroma: ";
	fflush(stdin);
	cin.getline(Cadena, 20, '\n');
	cout<<Cadena<<endl;
	
	if(Palindromo(Cadena, &Cadena[strlen(Cadena)-1])) cout<<"Es palindroma";
	else cout<<"No es palindroma";
	
	system("pause");
	return 0;
}

int Palindromo(char* Chain, char* Chain2)
{
	if((Chain-Chain2)>=0) return 1; // Si los punteros están en la misma posición o ya hicieron todo el recorrido, regresa 1.
	else if(*Chain==*Chain2) return Palindromo(++Chain, --Chain2);
	return 0;
}

long int Fibonacci(int x)
{
	int fn=0;
	if(x<0) return 0;
	else if(x>0)
	{
		fn=Fibonacci(x-1)+Fibonacci(x-2);
		return fn;
	}
	return 1;
}

double Factorial(int x)
{
	if(x<0) return 0; //No existe para números negativos, entonces se retorna 0.
	else if(x>0) return x*Factorial(x-1); //La premisa es ir hacia atrás, hasta que no se cumpla la condición.
	return 1;
}

/*
Palabras palíndromas:
rotor

ITERACIÓN 1:
	PALINDROMO(&CADENA[0], &CADENA[4])
	if((Chain-Chain2)>=0) return 1; --> NO SE CUMPLE.
	else if(*Chain==*Cadena2) return Palindromo(Chain++, Cadena2--); --> Aumenta la posición del puntero 1 y disminuye la del puntero 2.
	return 0; --> NO SE CUMPLE.
	
ITERACIÓN 2:
	PALINDROMO(&CADENA[1], &CADENA[3])
	if((Chain-Chain2)>=0) return 1; --> NO SE CUMPLE.
	else if(*Chain==*Cadena2) return Palindromo(Chain++, Cadena2--); --> Aumenta la posición del puntero 1 y disminuye la del puntero 2.
	return 0;
	
ITERACIÓN 3:
	PALINDROMO(&CADENA[2], &CADENA[2])
	if((Chain-Chain2)>=0) return 1; --> SE CUMPLE.
	else if(*Chain==*Cadena2) return Palindromo(Chain++, Cadena2--); --> NO SE CUMPLE.
	return 0; --> NO SE CUMPLE.
	
ORMLTRO

ITERACIÓN 1:
	PALINDROMO(&CADENA[0], &CADENA[6])
	if((Chain-Chain2)>=0) return 1; --> NO SE CUMPLE.
	else if(*Chain==*Chain2) return Palindromo(Chain++, Chain2--);
	return 0; --> NO SE CUMPLE.
	
	RESULTADO 0
	
ITERACIÓN 2:
	PALINDROMO(&CADENA[1], &CADENA[5])
	if((Chain-Chain2)>=0) return 1; --> NO SE CUMPLE.
	else if(*Chain==*Chain2) return Palindromo(Chain++, Chain2--);
	return 0; --> NO SE CUMPLE.
	
	RESULTADO: 0
	
ITERACIÓN 3:
	PALINDROMO(&CADENA[2], &CADENA[4])
	if((Chain-Chain2)>=0) return 1; --> NO SE CUMPLE.
	else if(*Chain==*Chain2) return Palindromo(Chain++, Chain2--); --> NO SE CUMPLE.
	return 0; --> SE CUMPLE.
	
	RESULTADO: 0
/*

ITERACIÓN 1:
	FIBONACCI(5)
	if(5<0) --> NO SE CUMPLE.
	else if(5>0) return 5*Factorial(5-1) --> 5*Factorial(4)
	
	if(5<0) --> NO SE CUMPLE.
	else if(5>0)
	{
		fn=Fibonacci(x-1)+Fibonacci(x-2); --> Fibonacci(4)+Fibonacci(3)
		return fn;
	}
	return 1; --> NO SE CUMPLE.
	RESULTADO: 8
	
ITERACIÓN 2:
	FIBONACCI(4)
	if(4<0) --> NO SE CUMPLE.
	else if(4>0) return 4*Factorial(4-1) --> 4*Factorial(3)

	if(4<0) --> NO SE CUMPLE.
	else if(4>0)
	{
		fn=Fibonacci(x-1)+Fibonacci(x-2); --> Fibonacci(3)+Fibonacci(2)
		return fn;
	}
	return 1; --> NO SE CUMPLE.
	RESULTADO: 5
	
ITERACIÓN 3:
	FIBONACCI(3)
	if(3<0) --> NO SE CUMPLE.
	else if(3>0) return 3*Factorial(3-1) --> 3*Factorial(2)

	if(3<0) --> NO SE CUMPLE.
	else if(3>0)
	{
		fn=Fibonacci(x-1)+Fibonacci(x-2); --> Fibonacci(2)+Fibonacci(1)
		return fn;
	}
	return 1; --> NO SE CUMPLE.
	RESULTADO: 3
	
ITERACIÓN 4:
	FIBONACCI(2)
	if(2<0) --> NO SE CUMPLE.
	else if(2>0)
	{
		fn=Fibonacci(x-1)+Fibonacci(x-2); --> Fibonacci(1)+Fibonacci(0)
		return fn;
	}
	return 1; --> NO SE CUMPLE.
	RESULTADO: 2
	
ITERACIÓN 5:
	FIBONACCI(1)
	if(1<0) --> NO SE CUMPLE.
	else if(1>0)
	{
		fn=Fibonacci(x-1)+Fibonacci(x-2); --> Fibonacci(0)+Fibonacci(-1)
		return fn;
	}
	return 1; --> NO SE CUMPLE.
	RESULTADO: 1
	
ITERACIÓN 6:	
	FIBONACCI(0)
	if(0<0) --> NO SE CUMPLE.
	else if(0>0) --> NO SE CUMPLE
	return 1;
	RESULTADO: 1
	
	FIBONACCI(-1)
	if(-1<0) return 0;
	else if(0>0) --> NO SE CUMPLE.
	return 1; --> NO SE CUMPLE.
	RESULTADO: 0
*/
