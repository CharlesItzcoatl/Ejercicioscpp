#include <iostream>
using namespace std;

#include <iostream>

using namespace std;

class fraccion {
    public:					// Los objetos p�blicos se pueden utilizar en cualquier parte del programa sin pedirri.
        fraccion(int n=0, int d=1) : numerador(n), denominador(d) { //Constructor inicializado en valores, n y d, que son 0 por defecto.
            Simplificar(); // �Qu� chingados hace esta funci�n aqu�?
        }
        void Simplificar(); // Funci�n que no retorna valores ni recibe.
        void Sumar(fraccion); // Funci�n que recibe un objeto de tipo fraccion y no retorna nada.
        void Mostrar();		// Funci�n que no retorna valores ni recibe.
    private:				// Los objetos privados s�lo pueden manipularse a trav�s de las funciones propias de la clase.
        int numerador;		// Variable entera para el numerador.
        int denominador;	// Variable entera para el denominador.
        int MCD(int, int);	// Funci�n que recibe como par�metros dos enteros y retorna otro entero.
};

void fraccion::Simplificar() { // Definici�n de la funci�n Simplificar.
    int mcd = MCD(numerador, denominador);
    numerador /= mcd; // numerador = numerador/mcd.
    denominador /= mcd; // denominador = denominador/mcd.
}

void fraccion::Sumar(fraccion f2) { // Variable local llamada f2.
    numerador = numerador*f2.denominador+denominador*f2.numerador;
    denominador = denominador*f2.denominador;
    Simplificar();
}

void fraccion::Mostrar() {
    cout << numerador << "/" << denominador << endl;
}

int fraccion::MCD(int a, int b) { // Definici�n de la funci�n MCD.
    if(a < b) return MCD(b,a);	// Si el numerador es menor que el denominador, vuelve la funci�n con los valores invertidos.
    if(b == 0) return a;
    return MCD(b, a % b);
}

int main() {
    fraccion f1(234, 2238);
    fraccion f2(64, 1024);
    
    f1.Mostrar();
    f2.Mostrar();
    
    f1.Sumar(f2);
    f1.Mostrar();
    return 0;
}

/*

64/1024
Se declara un nuevo objeto de tipo fracci�n, con valores numerador=64 y denominador=1024.
Al momento de inicializar, tambi�n se ejecuta, cada vez, la funci�n simplificar.
La funci�n simplificar tiene una variable entera que es el mcd y que se le asigna el valor de retorno de la funci�n MCD.
MCD recibe las variables y hace lo siguiente:

	int fraccion::MCD(int a, int b) 
	{
    	if(a < b) return MCD(b,a);	// Si el numerador es menor que el denominador, vuelve la funci�n con los valores invertidos.
    	if(b == 0) return a;
    	return MCD(b, a % b);
	}
	
	- ITERACI�N 1:
		si (64 < 1024) return MCD(1024,64); --> SE CUMPLE.
		si (1024 == 0) return 64; --> NO SE CUMPLE.
		return MCD(1024, 64%1024); --> return MCD(1024, 64); --> NO SE CUMPLE.
		
		Resultado: 64.
	- ITERACI�N 2:
		si (1024 < 64) return MCD(64,1024); --> NO SE CUMPLE.
		si (64 == 0) return 1024; --> NO SE CUMPLE.
		return MCD(64, 1024%64); --> return MCD(64, 0); --> SE CUMPLE.
		
		Resultado: 64.
	- ITERACI�N 3:
		si (64 < 0) return MCD(0,64); --> NO SE CUMPLE.
		si (0 == 0) return 64; --> SE CUMPLE.
		return MCD(0, 64%0); --> NO SE CUMPLE.
		
		Resultado: 64.
		
mcd equivale ahora a 64.
Entonces divide el numerador (64) entre 64 y el denominador (1024) entre 64. El resultado es 1/16.

*/

