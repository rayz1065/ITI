#include <iostream>
using namespace std;

int main()
{
	float km, lt, consumo, media;
	media=0;
	int i=1;
	while (km!=-1) {
		cout<<"\033[92mInserisci il valori dei chilometri percorsi e dei litri consumati del tuo "<<i<<"° veicolo\033[0m"<<endl;
		if (i>1){
			cout<<"\033[37mQuando hai terminato, immetti -1\033[0m"<<endl;
		}
		cin>>km;
		if (km==-1) {
			media/=(float)i;
			cout<<"La media dei consumi è di "<<media<<"km/l"<<endl;
			return 0;
		}
		cin>>lt;
		consumo=lt/km;
		media+=consumo;
		i++;
	}
}

