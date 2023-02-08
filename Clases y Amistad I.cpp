#include <iostream>
using namespace std;
 
class A; // Declaración previa (forward [unto dawn])
 
class B {
   public:
    B(int i=0) : b(i) {} // Consstructor
    void Ver() { cout << b << endl; } //Función Ver
    bool EsMayor(A Xa);  // Compara b con a
   private:
    int b; // Variable privada que es única de las funciones de B o amigas de B.
};

class A {
   public:
    A(int i=0) : a(i) {} //Constructor
    void Ver() { cout << a << endl; } // Otra función Ver.
   private:
    // Función amiga tiene acceso 
    // a miembros privados de la clase A
    friend bool B::EsMayor(A Xa); // Si queremos acceder a los datos privados de una clase, en la misma clase se declaran las funciones amigas.
    int a;
};

bool B::EsMayor(A Xa) {
   return b > Xa.a;
}

int main() {
   A Na(10);
   B Nb(12);
   
   Na.Ver();
   Nb.Ver();
   if(Nb.EsMayor(Na)) cout << "Nb es mayor que Na" << endl;
   else cout << "Nb no es mayor que Na" << endl;
   
   return 0;
}
