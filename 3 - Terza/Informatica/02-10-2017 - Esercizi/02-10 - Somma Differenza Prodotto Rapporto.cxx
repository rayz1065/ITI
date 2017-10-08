/*
 * 02-10 - Somma Differenza Prodotto Rapporto.cxx
 * 
 * Copyright 2017 Kevin Delugan <delugank@L007-04FUSS>
 */


#include <iostream>
using namespace std;

int main()
{
	int a,b,s,d,p,r;
		
	cout<<"Inserisci il primo numero\n";
	cin>>a;
	cout<<"Inserisci il secondo numero\n";
	cin>>b;
	
	s=a+b;
	d=a-b;
	p=a*b;
	r=a/b;
	
	cout<<"Somma: "<<s<<"\nDifferenza: "<<d<<"\nProdotto: "<<p<<"\nRapporto: "<<r;

	return 0;
}

