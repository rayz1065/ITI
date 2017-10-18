#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n,c;
	const string r="Milano";
	int i,o;
	i=1;
	o=0;
	do {
		cout<<"\033[92mInserisci il "<<i<<"° nome e la città di residenza\033[0m"<<endl;
	
		if (i>1){
			cout<<"\033[37mQuando hai terminato, immetti il nome ##\033[0m"<<endl;
		}
		cin>>n;	
		if (n=="##") {
			cout<<"\033[31mNel tuo elenco "<<o<<" persone sono di "<<r<<"\033[0m"<<endl;
			return 0;
		}
		cin>>c;
		if (c==r) {
			o++;
		}
		i++;
	 } while (n!="##");
	 return 0;
 }
