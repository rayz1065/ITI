#include <iostream>
using namespace std;

int main()
{
	float p;
	const float leggero=3;
	const float pesante=10;
	const float prezzo_leggero=5;
	const float prezzo_medio=8;
	const float prezzo_pesante=10;
	
	cout<<"\033[92mInserisci il peso del tuo pacco\033[0m"<<endl;
	cin>>p;
	cout<<"\033[32mLa spedizione costerà €";
	if (p<=leggero){
		cout<<prezzo_leggero<<endl;
	} else if (p>pesante) {
		cout<<prezzo_pesante<<endl;
	} else {
		cout<<prezzo_medio<<endl;
	}
	return 0;
}
