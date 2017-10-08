/*
 * 02-10 - Introduzione.cxx
 * 
 * Copyright 2017 Kevin Delugan <delugank@L007-04FUSS>
 */


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i,NumeroIn,NumeroOut,BaseIn,BaseOut,Resto;
		
	cout<<"Inserisci la base di partenza (<=10)\n";
	cin>>BaseIn;
	cout<<"Inserisci la base di arrivo (<=10)\n";
	cin>>BaseOut;
	cout<<"Inserisci il numero da convertire\n";
	cin>>NumeroIn;
	
	for(i=0;NumeroIn>0;i++)
	{
		Resto=NumeroIn%BaseOut;
		NumeroIn/=BaseOut;
		Resto*=pow(BaseIn,i);
		NumeroOut+=Resto;
	}
	
	cout<<NumeroOut;
	
	return 0;
}

