/*Dopo aver caricato un array di numeri interi con 10 componenti, calcolare il prodotto delle componenti*/
#include <iostream>
using namespace std;

int main() {
	int prodotto=1;
	int numeri[10]; //dichiaro un vettore di tipo float di dimensione 10
	for(int i=0;i<10;i++){
		cout<<"Inserisci il "<<i+1<<"° numero"<<endl;
		cin>>numeri[i];
		prodotto*=numeri[i];
	}
	cout<<endl;
	cout<<"Il podotto vale "<<prodotto<<endl;
	return 0;
}
