#include<iostream>
//#include<math.h>

using namespace std;
bool EsDivisible(int, const int);

int main()
{
	/*for(int i=1;i<=100;i++)
	{
		if(EsDivisible(i,3)) cout<<"Fizz";
		if(EsDivisible(i,5)) cout<<"Buzz";
		if(!EsDivisible(i,3) && !EsDivisible(i,5)) cout<<i;
		cout<<endl;
	}
	*/
	for(int i=1;i<=100;i++)
	{
		if(i%3==0)
		{
			cout<<"Fizz";
			if(i%5==0) cout<<"Buzz";
			cout<<endl;
			continue;
		}
		if(i%5==0)
		{
			cout<<"Buzz"<<endl;
			continue;
		}
		cout<<i<<endl;
	}
	return 0;
}

bool EsDivisible(int a, const int b)
{
	if(a%b==0) return true;
	else return false;
}
