#include <iostream>
using namespace std;

int main()
{
	int r,A,C;
	const float pi=3.14;
	cout<<"Inserisci la dimensione del tuo raggio: ";
	cin>>r;
	C=2*r*pi;
	A=r*r*pi;
	cout<<"La circonferenza misurera "<<C<<", mentre l'area misura "<<A<<".";
	return 0;
}
