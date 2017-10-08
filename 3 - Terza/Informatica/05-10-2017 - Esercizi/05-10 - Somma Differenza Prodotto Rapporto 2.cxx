#include <iostream>
using namespace std;

int main()
{
	int a,b,c,S,P,D,R;
	cout<<"Inserisci il tuo primo numero: ";
	cin>>a;
	cout<<"Inserisci il tuo secondo numero: ";
	cin>>b;
	cout<<"Inserisci il tuo terzo numero: ";
	cin>>c;
	
	while (c==0)
	{
		cout<<"Il terzo numero non può essere 0, inserirne un'altro.";
		cin>>c;
	}
	
	S=a+b+c;
	P=a*b*c;
	D=P-S;
	R=S/c;
		
	cout<<"La somma dei tre numeri è "<<S<<", il prodotto dei tre numeri è "<<P<<",\nla differenza fra prodotto e somma è "<<D<<" e il rapporto somma-terzo numero è "<<R<<'.';
	
	return 0;
}
