/*Escribir un programa que almacene en un array los nombres y números de teléfono de 10 personas. El programa debe leer los datos introducidos por el usuario
  y guardarlos en memoria (en el array). Después debe ser capaz de buscar el nombre correspondiente a un número de teléfono y el teléfono correspondiente a 
  una persona. Ambas opciones deben ser accesibles a través de un menú, así como la opción de salir del programa. 
*/
#include <iostream>
#include <string.h>
using namespace std;


int Opcion=0; //Opcion para el switch y Phone para el telefono a buscar 
char Respuesta; //Respuesta para el ciclo do while

struct Datos
{
	char Nombre[20];
	int Telefono;
	Datos() {Telefono=0;}
	void Leer();
	void Menu();
	void Operacion(int);
} Directorio[5];

void Leer()
{
	for(int i=0;i<=4;i++)
	{
		cout<<"Introduce el nombre de la persona "<<i+1<<" : "<<endl;
		gets(Directorio[i].Nombre);
		cout<<"Introduce el telefono "<<i+1<<" [8 digitos]: "<<endl;
		cin>>Directorio[i].Telefono;
		cin.ignore();
	}
}

void Menu()
{
	system("cls");
	cout<<"1) Buscar por nombre"<<endl;
	cout<<"2) Buscar por numero"<<endl;
	cout<<"3) Salir"<<endl;
	cout<<"Que opcion desea?"<<endl;
	cin>>Opcion;
}

void Operacion(int Op)
{
	int Phone=0,a=0;
	char Name[20];
	switch(Op)
		{	
			case 1:
				cout<<"Buscar por nombre\nIntroduce el nombre: "<<endl;
				cin.ignore();
				gets(Name);
				for(int i=0;i<=4;i++)
				{
					if(!strncmp(Name,Directorio[i].Nombre,20))
					{
						Phone=Directorio[i].Telefono;
					}
				}	
				if (Phone!=0) cout<<"El telefono es: "<<Phone;
				else cout<<"No existe en este directorio"<<endl;
				cout<<"\nRepetir? Y / N"<<endl;
				cin>>Respuesta;
				break;
			case 2:
				cout<<"Buscar por telefono\nIntroduce el telefono: "<<endl;
				cin>>Phone;
				for(int i=0;i<=4;i++)
				{
					if(Phone==Directorio[i].Telefono)
					{
						cout<<"El nombre es: "<<Directorio[i].Nombre;
						a++;
					}
				}
				if(a==0) cout<<"No existe en este directorio";
				cout<<"\nRepetir? Y / N"<<endl;
				cin>>Respuesta;
				break;
			case 3: 
				Respuesta=0;
				break;
			default:
				cout<<"Opcion no valida";
				cout<<"\nRepetir? Y / N"<<endl;
				cin>>Respuesta;
				break;
		}	
		
}

int main()
{
	Leer();
	do
	{
		Menu();
		Operacion(Opcion);
	}
	while(Respuesta=='Y'||Respuesta=='y');
	return 0;	
}
