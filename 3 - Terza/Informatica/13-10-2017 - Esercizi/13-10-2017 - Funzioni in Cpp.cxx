#include <iostream>
using namespace std;

int somma(int x, int y){
	int z;
	z=x+y;
	return z;
}

int differenza(int x, int y){
	int z;
	z=x-y;
	return z;
}

int prodotto(int x, int y){
	int z;
	z=x*y;
	return z;
}

int main(){
	int a,b,s,d,p;
	cout<<"\033[32mInserisci il primo numero\033[0m"<<endl;
	cin>>a;
	cout<<"\033[32mInserisci il secondo numero\033[0m"<<endl;
	cin>>b;
	
	s=somma(a,b);
	d=differenza(a,b);
	p=prodotto(a,b);
	
	cout<<"\033[92La somma vale "<<s<<", la differenza "<<d<<" e il prodotto "<<p<<".\033[0m"<<endl;
	return 0;
}
