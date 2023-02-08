//Hacer un programa de cajero automático, que dé la menor cantidad de billetes según la cantidad de dinero que se solicite; genere un error cuando se excede esa cantidad.

#include<iostream>

using namespace std;

bool Respuesta=false;
//¿Cómo hacer para recortar el código, utilizando más funciones?
class ATM
{
	public:
		ATM(int A=0): Billete500(500), Billete200(500), Billete100(500), Retiro(A), switcher(false), Billetes(0) {};
		void Display();
		void WithDrawal();
		bool Check();
	private:
		int Billete500;
		int Billete200;
		int Billete100;
		int Retiro;
		int Billetes;
		int switcher;
};

void ATM::Display()
{
	system("pause");
	system("cls");
	cout<<"Dinero disponible en el cajero: "<<(Billete500*500)+(Billete200*200)+(Billete100*100)<<endl;
	cout<<"En este cajero hay: "<<endl;
	cout<<Billete500<<" billete"<<(Billete500==1? "":"s")<<" de 500"<<endl;
	cout<<Billete200<<" billete"<<(Billete200==1? "":"s")<<" de 200"<<endl;
	cout<<Billete100<<" billete"<<(Billete100==1? "":"s")<<" de 100"<<endl;
	cout<<"Retiro: ";
	cin>>Retiro;
}


void ATM::WithDrawal()
{
		if(Billete500==0) switcher=1;
		if(Billete200==0) switcher=2;
		if(Billete100==0) switcher=3;
		if(Billete200==0 && Billete100==0) switcher=4;
		switch(switcher)
		{
		case 0:
			Respuesta=true;
			if(((Billete500*500)+(Billete200*200)+(Billete100*100))<Retiro) {cout<<"Transaccion fallida, no hay suficientes billetes\n"; break;}
			Billetes=Retiro/500;
			if(Billetes>Billete500) Billetes=Billete500;
			Retiro-=Billetes*500;
			Billete500-=Billetes;
			cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 500"<<endl;
			Billetes=Retiro/200;
			if(Billetes>Billete200) Billetes=Billete200;
			Retiro-=Billetes*200;
			Billete200-=Billetes;
			cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 200"<<endl;
			Billetes=Retiro/100;
			Retiro-=Billetes*100;
			Billete100-=Billetes;
			cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 100"<<endl;
			break;
		case 1:
			Respuesta=true;
			if(((Billete200*200)+(Billete100*100))<Retiro) {cout<<"Transaccion fallida, no hay suficientes billetes\n"; break;}
			Billetes=Retiro/200;
			if(Billetes>Billete200) Billetes=Billete200;
			Retiro-=Billetes*200;
			Billete200-=Billetes;
			cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 200"<<endl;
			Billetes=Retiro/100;
			Retiro-=Billetes*100;
			Billete100-=Billetes;
			cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 100"<<endl;
			break;
		case 2:
			Respuesta=true;
			if(Billete500!=0)
			{
				if(((Billete500*500)+(Billete100*100))<Retiro) {cout<<"Transaccion fallida, no hay suficientes billetes\n"; break;}
				Billetes=Retiro/500;
				if(Billetes>Billete500) Billetes=Billete500;
				Retiro-=Billetes*500;
				Billete500-=Billetes;
				cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 500"<<endl;
			}
			if((Billete100*100)<Retiro) {cout<<"Transaccion fallida, no hay suficientes billetes\n"; break;}
			Billetes=Retiro/100;
			Retiro-=Billetes*100;
			Billete100-=Billetes;
			cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 100"<<endl;	
			break;
		case 3:
			Respuesta=true;
			if(Retiro%500==0 || Retiro%200==0 || Retiro>100)
			{
				if(((Billete500*500)+(Billete200*200))<Retiro) {cout<<"Transaccion fallida, no hay suficientes billetes\n"; break;}
				Billetes=Retiro/500;
				if(Billetes>Billete500) Billetes=Billete500;
				Retiro-=Billetes*500;
				Billete500-=Billetes;
				cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 500"<<endl;
				Billetes=Retiro/200;
				if(Billetes>Billete200) Billetes=Billete200;
				Retiro-=Billetes*200;
				Billete200-=Billetes;
				cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 200"<<endl;
			}
			else cout<<"Transaccion fallida, no hay suficientes billetes de 100\n";
			break;
		case 4:
			Respuesta=true;
			if(Retiro%500==0)
			{
				if(((Billete500*500)+(Billete200*200))<Retiro) {cout<<"Transaccion fallida, no hay suficientes billetes\n"; break;}
				Billetes=Retiro/500;
				if(Billetes>Billete500) Billetes=Billete500;
				Retiro-=Billetes*500;
				Billete500-=Billetes;
				cout<<Billetes<<" billete"<<(Billetes==1? "":"s")<<" de 500"<<endl;
			}
			else cout<<"Transaccion fallida, no hay suficientes billetes\n";
		default:
			break;
		}
}

bool ATM::Check()
{
	if(Retiro%100!=0) {cout<<"No hay billetes inferiores a 100$\n"; Respuesta=true; return true;}
}

int main()
{
	ATM Cliente0(0);
	do
	{	Cliente0.Display();
		if(Cliente0.Check()) continue;
		Cliente0.WithDrawal();
	}
	while(Respuesta);
	return 0;
}
