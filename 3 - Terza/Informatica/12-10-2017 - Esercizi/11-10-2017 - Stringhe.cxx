#include <iostream>
#include <string>
using namespace std;

int main()
{
	float prez;
	const float max=100;
	int i,c;
	string desc;
	i=1;
	do {
		cout<<"\033[92mInserisci la nome e il prezzo del tuo "<<i<<"° prodotto\033[0m"<<endl;
		if (i>1){
			cout<<"\033[37mQuando hai terminato, non immettere alcuna descrizione\033[0m"<<endl;
		}
		cin>>desc;	
		if (desc!="") {
			cout<<"\033[92mNel tuo elenco "<<c<<" prodotto/i supera/no i €100\033[0m"<<endl;
			return 0;
		}
		cin>>prez;
		if (prez>max) {
			c++;
		}
		i++;
	} while (desc!="");
}
