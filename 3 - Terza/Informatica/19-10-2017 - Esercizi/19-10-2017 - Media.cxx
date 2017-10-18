#include <iostream>
using namespace std;

float media(int n,float s)
{
	float m;
	m=s/(float)n;
	return m;
}

int main()
{
	int numero_elementi;
	float somma;
	cout<<"Immetti il numero di elementi"<<endl;
	cin>>numero_elementi;
	cout<<"Immetti la somma degli elementi"<<endl;
	cin>>somma;
	cout<<media(numero_elementi,somma)<<endl;
	
	return 0;
}
