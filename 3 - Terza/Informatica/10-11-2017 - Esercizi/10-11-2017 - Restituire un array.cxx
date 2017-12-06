/*Dopo aver caricato un array di numeri interi con 10 componenti, raddoppiare il valore delle prime tre componenti*/
#include <iostream>
using namespace std;

int main() {
	int numeri[10]; //dichiaro un vettore di tipo float di dimensione 10
	for(int i=0;i<10;i++){
		cout<<"Inserisci il "<<i+1<<"° numero"<<endl;
		cin>>numeri[i];
		if(i<3) numeri[i]*=2;
	}
	cout<<endl<<"La sequenza aggiornata sarà:"<<endl;
	for(int i=0;i<10;i++){
		cout<<numeri[i];
		if(i<9) cout<<", ";
		else cout<<endl;
	}
	return 0;
}
