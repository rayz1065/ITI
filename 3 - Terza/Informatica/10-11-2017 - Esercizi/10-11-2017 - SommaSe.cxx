/*Dopo aver caricato un array di numeri interi con 10 componenti, contare le componenti che hanno valore superiore a 5*/
#include <iostream>
using namespace std;

int main() {
	int cont=0;
	int numeri[10]; //dichiaro un vettore di tipo float di dimensione 10
	for(int i=0;i<10;i++){
		cout<<"Inserisci il "<<i+1<<"° numero"<<endl;
		cin>>numeri[i];
		if(numeri[i]>5) cont++;
	}
	cout<<endl;
	cout<<cont<<" numeri sono maggiori di 5"<<endl;
	return 0;
}
