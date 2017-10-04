#include <iostream>
using namespace std;

int main()
{
	int r,A,C,pi;
	cout<<"Inserisci la dimensione del tuo raggio.";
	cin>>r;
	pi=3.14;
	C=2*r*pi;
	A=r*r*pi;
	cout<<"La circonferenza misurera "<<C<<", mentre l'area misura "<<A<<".";
	return 0;
}