#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream Archivo;
    Archivo.open("Prueba.txt");
    
    if(Archivo.fail())
    {
                      cout<<"Error de apertura";
                      system("Pause");
                      return 0;
    }
    
    Archivo<<"Esto es una prueba"<<endl;
    Archivo<<"Hola mundo"<<endl;
    Archivo<<"Adios Mundo cruel - dijo el topillo"<<endl;
    
    Archivo.close();
    
    cout<<"Prueba Terminada"<<endl;
    
    system("Pause");
    
    return 0;
}
