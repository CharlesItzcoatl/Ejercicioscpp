//Hacer un programa de cajero automático, que dé la menor cantidad de billetes según la cantidad de dinero que se solicite; genere un error cuando se excede esa cantidad.

#include<iostream>

using namespace std;

void DrawMap(char, unsigned int&, unsigned int&);
bool GameOver(void);

int main()
{
	// La función DrawMap dibuja el mapa
	// 
	char M='0';
	unsigned int X=0, Y=0;
	bool isGameOver=false;
	while(!isGameOver)
	{
		cin>>M;
		DrawMap(M, X, Y);
		isGameOver=GameOver();
	}
	
	return 0;
}

bool GameOver()
{
	bool R=false;
	cout<<endl<<"is Game Over? ";
	cin>>R;
	if(R!=0) return true;
	else return false;
}

void DrawMap(char P, unsigned int &X, unsigned int &Y)
{
	char MyHero='H';
	char Posicion[5][5]=
	{
		{'0','0','0','0','0'},
		{'0','0','0','0','0'},
		{'0','0','0','0','0'},
		{'0','0','0','0','0'},
		{'0','0','0','0','0'}
	};
	switch(P)
		{
			case 'a':
				X--;
				break;
			case 'd':
				X++;
				break;
			case 's':
				Y++;
				break;
			case 'w':
				Y--;
				break;
		}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j!=X)
			{
				cout<<Posicion[i][j];
			}
			else 
			{
				if(i!=Y)
				{
					cout<<Posicion[i][j];
				}
				else cout<<'H';
			}
		}
		cout<<endl;
	}
	return;
}
