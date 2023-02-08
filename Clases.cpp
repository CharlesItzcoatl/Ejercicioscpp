#include<iostream>

using namespace std;

class Complex
{
	public:
		Complex(float x=0, float y=0): a(x), b(y) {};
		void Lee();
		void Escribe(float, float);
		void Suma(Complex);
	private:
		float a, b;
		friend Complex Resta(Complex, Complex);
};

void Complex::Lee()
{
	cout<<a<<"+"<<b<<"i"<<endl;
}

void Complex::Escribe(float x, float y)
{
	a=x;
	b=y;
}

void Complex::Suma(Complex x)
{
	a+=x.a;
	b+=x.b;
}

Complex Resta(Complex x, Complex y)
{
	Complex C;
	C.a=x.a-y.a;
	C.b=x.b-y.b;
	return C;
}

int main()
{
	Complex X(15,20); //Nuevo objeto tipo Complex.
	Complex Y(10,12);
	Complex Z;
	X.Lee();
	Y.Lee();
	X.Escribe(5,10);
	X.Lee(); // Ahora X = 5+10i
	X.Suma(Y); // A 'X' se le suma 'Y'
	X.Lee(); // Ahora X = X+Y = 5+10i + 10+12i = 15+22i
	Z=Resta(X, Y); // Resta Y de X, Z= 15+22i - 10+12i = 5+10i
	X.Lee();
	Z.Lee();
	return 0;
}

