/* Escribir un programa que almacene en un array los nombres y números de teléfono de 10 personas. El programa debe leer los datos introducidos por el usuario y guardarlos en memoria
   (en el array). Después debe ser capaz de buscar el nombre correspondiente a un número de teléfono y el teléfono correspondiente a una persona. Ambas opciones deben ser accesibles,
   a través de un menú, así como la opción de salir del programa. El menú debe tener esta forma:
   
   a) Buscar por nombre
   b) Buscar por teléfono
   c) Salir
   
   Pulsa una opción:
   
   
*/
#include<iostream>
#include <string.h>

using namespace std;

void Menu(int, int);
struct Agenda
{
	// Variables que pertenecen a la estructura.
	char Name[21];
	char Phone[11];					// La variable Phone consta de 11 elementos, 10 para el número y el último para el caracter nulo.
	Agenda();						// Declarar constructor.
	// Funciones que pertenecen a la estructura.
	void GetData(int);
	void ShowData(int);
} Persona[20];		// Objetos de tipo Agenda.

int main()
{
	bool cases;
	int n=0, i=0;
	char switcher=0;
	cout<<"Introduce el numero de personas en la agenda: "<<endl;
	cin>>n;
	// n objetos del tipo Agenda, en un vector llamado Persona.
	for(i=0;i<n;i++) Persona[i].GetData(i+1);
	do
	{
		system("cls");
		cout<<"Como deseas realizar la busqueda?"<<endl;
		cout<<"a) Por nombre"<<endl;
		cout<<"b) Por telefono"<<endl;
		cout<<"c) Salir"<<endl;
		cin>>switcher;
		Menu(switcher, n);
		cout<<"Repetir?\t1=SI\t0=NO"<<endl;
		cin>>cases;
	}
	while(cases);
	return 0;
}

void Agenda::GetData(int Numerito)
{
	cout<<"Escribe el nombre de la Persona "<<Numerito<<": "<<endl;
	if(Numerito==1)cin.ignore();
	cin.getline(Name,21);
	cout<<"Escribe el numero de la Persona: "<<Numerito<<": "<<endl;
	cin.getline(Phone,11);
	cout<<endl;
}

void Agenda::ShowData(int Numerito)
{
	cout<<"No. de Registro: "<<Numerito<<endl;
	cout<<"Nombre: "<<Name<<endl;
	cout<<"Telefono: "<<Phone<<endl;
}

Agenda::Agenda()
{
	for(int x=0;x<=10;x++) Phone[x]=0;
	for(int x=0;x<=20;x++) Name[x]=0;
}

void Menu(int op, int N)
{
	bool Flag=false;
	char Nombre[21], Telefono[11];
	switch(op)
	{
		case 'a':
			cout<<"Busqueda por nombre"<<endl;
			cout<<"Escribe el nombre de la persona que deseas encontrar: "<<endl;
			cin.ignore();
			cin.getline(Nombre,21);
			cout<<"El nombre ingresado es: "<<Nombre<<endl;
			for(int i=0;i<N;i++) 
			{
				if(!strcmp(Nombre, Persona[i].Name)) 
				{
					Persona[i].ShowData(i+1);
					Flag=true;
				}
				
			}
			if(!Flag) cout<<"Nombre no registrado!"<<endl;
			break;
		case 'b':
			cout<<"Busqueda por telefono"<<endl;
			cout<<"Escribe el telefono de la persona que deseas encontrar: "<<endl;
			cin.ignore();
			cin.getline(Telefono,11);
			cout<<"El numero ingresado es: "<<Telefono<<endl;
			for(int i=0;i<N;i++) 
			{
				if(!strcmp(Telefono, Persona[i].Phone)) 
				{
					Persona[i].ShowData(i+1);
					Flag=true;
				}
			}
			if(!Flag) cout<<"Telefono no registrado!"<<endl;
			break;
		case 'c':
			break;
		default:
			cout<<"Opcion no valida!";
			break;
				
	}
}
