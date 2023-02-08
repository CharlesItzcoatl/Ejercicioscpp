#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
	public:
		Complex(float x=0, float y=0): a(x), b(y) {};
		void Edit(float, float);
		void Display();
		Complex operator+(Complex);
		Complex operator-(Complex);
		Complex operator*(Complex);
		Complex operator/(Complex);
	private:
		float a, b;
		friend Complex Conjugado(Complex);
};

Complex Conjugado(Complex X)
{
	Complex C;
	C.a=X.a;
	C.b=-X.b;
	return C;
}

// Cuando se sobrecargan operadores en una clase, se asume que el primer operando es el propio objeto de la clase donde se define el operador, por lo cual
// sólo se necesita especificar un operando.
Complex Complex::operator+(Complex X)
{
	Complex C;
	C.a=a+X.a;
	C.b=b+X.b;
	return C;
}

Complex Complex::operator-(Complex X)
{
	Complex C;
	C.a=a-X.a;
	C.b=b-X.b;
	return C;
}

Complex Complex::operator*(Complex X)
{
	Complex C;
	C.a=(a*X.a)-(b*X.b);
	C.b=(a*X.b)+(b*X.a);
	return C;
}

Complex Complex::operator/(Complex X)
{
	Complex C;
	float D=0;
	C.a=(a*X.a)-(b*-X.b);
	C.b=(a*-X.b)+(b*X.a);
	D=pow(X.a,2)+pow(X.b,2);
	C.a/=D;
	C.b/=D;
	return C;
}

void Complex::Edit(float X, float Y)
{
	a=X;
	b=Y;
}

void Complex::Display()
{
	cout<<a<<(b>=0? "+":"")<<b<<"i"<<endl;
}

int main()
{
	Complex C;
	float a=0, b=0, c=0, d=0;
	cout<<"Introduce dos numeros complejos"<<endl;
	cout<<"Parte Real: ";
	cin>>a;
	cout<<"Parte Imaginaria: ";
	cin>>b;
	cout<<"Parte Real: ";
	cin>>c;
	cout<<"Parte Imaginaria: ";
	cin>>d;
	Complex A(a,b);
	Complex B(c,d);
	A.Display();
	B.Display();
	C=A+B;
	cout<<"Suma = ";
	C.Display();
	C=A-B;
	cout<<"Resta = ";
	C.Display();
	C=A*B;
	cout<<"Multiplicacion = ";
	C.Display();
	C=Conjugado(C);
	cout<<"Conjugado = ";
	C.Display();
	C=A/B;
	cout<<"Division = ";
	C.Display();
	system("pause");
	return 0;
}

