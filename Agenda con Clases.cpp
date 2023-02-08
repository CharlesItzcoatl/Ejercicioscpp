#include <iostream>

using namespace std;

class Agenda
{
	public:
		Agenda();
		void Edit();
		void Display();
	private:
		char Nombre[50];
		char FechaDeNacimiento[11];
		char Direccion1[40];
		char Direccion2[40];
		char CP[6];
		double Telefono[2];
};

void Agenda::Edit()
{
	cout<<"Introduce tu(s) nombre(s): ";
	cin.getline(Nombre, 50, '\n');
	cout<<"Introduce tu fecha de nacimiento: ";
	cin.getline(FechaDeNacimiento, 11, '\n');
	cout<<"Introduce tu calle con numero: ";
	cin.getline(Direccion1, 40, '\n');
	cout<<"Introduce tu colonia, municipio y estado: ";
	cin.getline(Direccion2, 40, '\n');
	for(int i=0;i<2;i++)
	{
		cout<<"Introduce tu telefono "<<(i>0? "celular": "de casa")<<" (10 digitos): ";
		cin>>Telefono[i];
	} 
	fflush(stdin);
	cout<<"Introduce tu C.P: ";
	cin.getline(CP, 6, '\n');
}

void Agenda::Display()
{
	cout<<endl;
	cout<<Nombre<<endl;
	cout<<FechaDeNacimiento<<endl;
	cout<<Direccion1<<endl;
	cout<<Direccion2<<endl;
	for(int i=0;i<2;i++) printf("%.0f\n", Telefono[i]);
	cout<<CP<<endl;
}

int main()
{
	int i=0, n=0;
	cout<<"Cuantas personas habra en la agenda? ";
	cin>>n;
	fflush(stdin);
	Agenda Persona[n];
	for(i=0;i<n;i++) Persona[i].Edit();
	cout<<endl;
	for(i=0;i<n;i++) Persona[i].Display();
	return 0;
}

Agenda::Agenda()
{
	int i=0;
	for(i=0;i<50;Nombre[i++]='0'); 
	for(i=0;i<11;FechaDeNacimiento[i++]='0');
	for(i=0;i<40;Direccion1[i++]='0');
	for(i=0;i<40;Direccion2[i++]='0');
	for(i=0;i<6;CP[i++]='0');
	for(i=0;i<2;Telefono[i++]=0);
	
}
