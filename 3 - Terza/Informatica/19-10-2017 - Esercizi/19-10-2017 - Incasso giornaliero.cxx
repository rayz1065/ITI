#include <iostream>
using namespace std;

float somma(float p,float c)
{
	p+=c;
	return p; 
}

void media(float p,int n)
{
	float m;
	m=p/(float)n--;
	return m;
}

int main()
{
	float incasso, parziale;
	i=1;
	parziale=0;
	do {
		cout<<"Immetti l'incasso del "<<i<<"° giorno."<<endl;
		if (i>1){
			cout<<"\033[37mQuando hai terminato e vuoi sapere la media, immetti -1\033[0m"<<endl;
		}
		cin>>incasso;
		parziale=somma(parziale,incasso);
		cout<<"Attualmente il totale degli incassi ammonta a €"<<parziale<<endl;
		i++;
	}
	cout<<"La media degli incassi è di €"<<media(parziale,i)<<endl;
	return 0;
}
