#include<iostream>
#include<string.h>

using namespace std;

class Persona 			// Clase padre de todas las clases. De esta clase de derivan directamente Empleado y Estudiante; indirectamente, Becario.
{
	public:
		Persona();		// Constructor de la clase.
		void Edit();	// Función para editar los datos de una persona.
		void Display(); // Función para mostrar los datos de una persona.
	protected:
		char Name[50];
		char BD[11];
		char D1[40];
		char D2[40];
		char CP[6];
		double Phone[2];
};

void Persona::Edit()
{
	cout<<"Introduce el nombre: ";
	fflush(stdin);
	cin.getline(Name, 50, '\n');
	cout<<"Introduce tu fecha de nacimiento (formato dd/mm/aaaa): ";
	cin.getline(BD, 11, '\n');
	cout<<"Introduce tu calle y numero: ";
	cin.getline(D1, 40, '\n');
	cout<<"Introduce tu colonia, municipio y estado: ";
	cin.getline(D2, 40, '\n');
	cout<<"Introduce tu codigo postal: ";
	fflush(stdin);
	cin.getline(CP, 6, '\n');
	for(int i=0;i<2;i++)
	{
		cout<<"Introduce tu telefono "<<(i>0? "celular ": "de casa ");
		cout<<"(10 digitos): ";
		cin>>Phone[i];
	}   
}

void Persona::Display()
{
	cout<<Name<<endl;
	cout<<BD<<endl;
	cout<<D1<<endl;
	cout<<D2<<endl;
	cout<<CP<<endl;
	for(int i=0;i<2;i++) printf("Telefono %d: %.0f\n", i+1, Phone[i]);
}

class Empleado : virtual public Persona
{
	public:
		Empleado();
		void Edit();
		void Display();
	protected:
		char Empresa[40];
		char Puesto[30];
		double Salario;
};

void Empleado::Edit()
{
	cout<<"Introduce el nombre de la empresa: ";
	fflush(stdin);
	cin.getline(Empresa, 40, '\n');
	cout<<"Introduce tu puesto: ";
	cin.getline(Puesto, 60, '\n');
	fflush(stdin);
	cout<<"Introduce tu salario: ";
	cin>>Salario;
}

void Empleado::Display()
{
	cout<<Empresa<<endl;
	cout<<Puesto<<endl;
	cout<<Salario<<endl;
}

class Estudiante : virtual public Persona
{
	public:
		Estudiante();
		void Edit();
		void Display();
	protected:
		char Escuela[40];
		double Boleta;
		int Semestre;
		float Promedio;
};

void Estudiante::Edit()
{
	cout<<"Introduce tu escuela: ";
	fflush(stdin);
	cin.getline(Escuela, 40, '\n');
	cout<<"Introduce tu boleta: ";
	cin>>Boleta;
	cout<<"Introduce tu semestre: ";
	cin>>Semestre;
	cout<<"Introduce tu promedio: ";
	cin>>Promedio;
	
}

void Estudiante::Display()
{
	cout<<Escuela<<endl;
	printf("%.0f\n", Boleta);
	cout<<Semestre<<endl;
	cout<<Promedio<<endl;
}

class Becario : public Empleado, public Estudiante
{
	public:
		Becario();
		void Edit();
		void Display();
	protected:
		char SS1[11];
		char SS2[11];
};

void Becario::Edit()
{
	Persona::Edit();
	Empleado::Edit();
	Estudiante::Edit();
	fflush(stdin);
	cout<<"Introduce la fecha de inicio del SS: ";
	cin.getline(SS1, 11, '\n');
	cout<<"Introduce la fecha de termino del SS: ";
	cin.getline(SS2, 11, '\n');
	fflush(stdin);
}

void Becario::Display()
{
	Persona::Display();
	Empleado::Display();
	Estudiante::Display();
	cout<<SS1<<endl;
	cout<<SS2<<endl;
}

int main()
{
	Becario Tester;
	cout<<"Introduce los datos"<<endl;
	Tester.Edit();
	Tester.Display();
	system("pause");
	return 0;
}

Persona::Persona()
{
	int i=0;
	for(i=0;i<50;Name[i++]=0);
	for(i=0;i<11;BD[i++]=0);
	for(i=0;i<40;D1[i++]=0);
	for(i=0;i<40;D2[i++]=0);
	for(i=0;i<6;CP[i++]=0);
	for(i=0;i<2;Phone[i++]=0);
}

Empleado::Empleado()
{
	int i=0;
	for(i=0;i<40;Empresa[i++]=0);
	for(i=0;i<50;Puesto[i++]=0);
	Salario=0.0;
}

Estudiante::Estudiante()
{
	int i=0;
	for(i=0;i<40;Escuela[i++]=0);
	Boleta=0.0;
	Semestre=0;
	Promedio=0.0;
}

Becario::Becario()
{
	int i=0;
	for(i=0;i<11;SS1[i++]=0);
	for(i=0;i<11;SS2[i++]=0);	
	Persona(); // Cuando se utilizan clases virtuales, se necesita declarar aquí el constructor de la clase base.
}
