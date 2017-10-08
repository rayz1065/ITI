#include <iostream>
using namespace std;

int main()
{
	int s;
	float C;
	const float Inizio=0.10;
	const float PerSecondo=0.15;
	const float OltreLimite=0.09;
	const int Limite=80;
	cout<<"Inserire la durata della chiamata in secondi:"<<endl;
	cin>>s;
	
	if (s<=0)
	{
		cout<<"\033[31mNumero inserito non valido\033[0m"<<endl;
		return 0;
	}
	
	C=Inizio;
	
	if (s<=Limite)
	{
		C+=(float)s*PerSecondo;
	}
	else
	{
		C+=(float)Limite*PerSecondo;
		s-=(float)Limite;
		C+=(float)s*OltreLimite;
	}
	
	cout<<"Il costo della chiamata sarà di €"<<C<<endl;
}