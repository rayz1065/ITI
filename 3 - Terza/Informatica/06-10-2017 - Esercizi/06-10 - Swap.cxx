#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cout<<"Inserisci il tuo primo numero: ";
	cin>>a;
	cout<<"Inserisci il tuo secondo numero: ";
	cin>>b;
	
	c=a;
	a=b;
	b=c;
	cout<<a<<" e "<<b<<" sono stati invertiti grazie ad una funzione ausiliaria c.";
	return 0;
}
