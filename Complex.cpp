#include <iostream>

using namespace std;

struct Complex
{
	Complex();
	//void Suma(Complex*,Complex*);
	//void Resta(Complex*,Complex*);
	int x, y;
}a, b, c, *pa, *pb, *pc; // variable tipo Complex, llamada 'a'.

Complex operator+(Complex a, Complex b)
{
	Complex C;
	C.x=a.x+b.x;
	C.y=a.y+b.y;
	return C;
}

Complex operator-(Complex a, Complex b)
{
	Complex C;
	C.x=a.x-b.x;
	C.y=a.y-b.y;
	return C;
}

void add(int&,int&);

int main()
{
	pa=&a;
	pb=&b;
	pc=&c;
	cout<<"Escribe un numero complejo:"<<endl<<"Real: ";
	cin>>a.x;
	cout<<"Imaginario: ";
	cin>>a.y;
	cout<<"Escribe un numero complejo:"<<endl<<"Real: ";
	cin>>b.x;
	cout<<"Imaginario: ";
	cin>>b.y;
	cout<<"El numero  a es: "<<a.x<<" + "<<a.y<<"i"<<endl;
	cout<<"El numero  b es: "<<b.x<<" + "<<b.y<<"i"<<endl;
	c=a+b;
	//c.Suma(pa,pb);
	cout<<"La suma de los numeros es: "<<c.x<<"+"<<c.y<<"i"<<endl;
	c=a-b;
	//c.Resta(pa,pb);
	cout<<"La resta de los numeros es: "<<c.x<<(c.y>0? "+":"")<<c.y<<"i";
	system("pause");
	int a1, b1;
	a1=10; b1=5;
	add(a1,b1);
	cout<<endl<<a1<<endl<<b1;
	return 0;
}

void add(int &x, int &y)
{
	x+=y;
	y-=3;
	return;
}
/*
void Complex::Suma(Complex* vx, Complex* vy)
{
	x=0, y=0;
	x+=(vx->x)+(vy->x);
	y+=(vx->y)+(vy->y);
	return;
}

void Complex::Resta(Complex* vx, Complex* vy)
{
	x=0, y=0;
	x+=(vx->x)-(vy->x);
	y+=(vx->y)-(vy->y);
	return;
}
*/
//Constructor. Se utiliza para inicializar las variables que pertenecen a la estructura.
Complex::Complex()
{
	x=0;
	y=0;
}
