/*Se puede añadir:
 	-lectura de longitud de cadena, para que se muestre error si el numero es superior al permitido.
 	-Preguntar si los datos son correctos; si no lo son, repetir el proceso para la misma persona.
 	
*/
#include<iostream>
#include<string.h>

using namespace std;

struct Direccion
{
	Direccion();
	char Calle[20];
	int Numero;
	char Dir[50];	//Colonia, municipio y estado.
	char CP[6];
};

struct Persona
{
	Persona();
	struct
	{
		char Nombres[32];
		char Apellidos[64];
	};
	//char Telefono[2][11];	//Teléfono fijo y celular
	double Telefono[2];
	Direccion Address;
};

int main()
{
	int i=0, n=0, s=0;
	cout<<"Cuantas personas se añadiran a la agenda? "<<endl;
	cin>>n;
	Persona Agenda[n];
	for(i=0;i<n;i++)
	{
	fflush(stdin);
	cout<<"Introduce tus datos"<<endl;
	cout<<"Introduce tu(s) nombre(s): ";
	cin.getline(Agenda[i].Nombres, 32, '\n');
	cout<<"Introduce tus apellidos: ";
	cin.getline(Agenda[i].Apellidos, 64, '\n');
	for(s=0;s<=1;s++)
	{
		cout<<"Introduce tu telefono "<<(s>0? "celular ":"de casa ");
		cout<<"(10 digitos): ";
		cin>>Agenda[i].Telefono[s];
		//cin.getline(Agenda[i].Telefono[s], 11, '\n');
	}
	fflush(stdin);
	cout<<"Calle: ";
	cin.getline(Agenda[i].Address.Calle, 20, '\n');
	cout<<"Numero: ";
	cin>>Agenda[i].Address.Numero;
	fflush(stdin);
	cout<<"Colonia, municipio y estado: ";
	cin.getline(Agenda[i].Address.Dir, 50, '\n');
	cout<<"C.P: ";
	cin.getline(Agenda[i].Address.CP, 6, '\n');
	
	cout<<endl<<Agenda[i].Nombres<<endl;
	cout<<Agenda[i].Apellidos<<endl;
	for(s=0;s<=1;s++) printf("%.0f\n", Agenda[i].Telefono[s]);
	cout<<Agenda[i].Address.Calle<<endl;
	cout<<Agenda[i].Address.Numero<<endl;
	cout<<Agenda[i].Address.Dir<<endl;
	cout<<Agenda[i].Address.CP<<endl;

	}
	return 0;
}

Direccion::Direccion()
{
	Calle[20]='0';
	Numero=0;
	Dir[50]='0';
	CP[6]='0';
}

Persona::Persona()
{
	Nombres[32]='0';
	Apellidos[64]='0';
	//Telefono[2][11]='0';
	Telefono[2]=0;
}

