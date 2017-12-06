/*Vogliamo creare un programma per gestire l'incasso settimanale*/
#include <iostream>
using namespace std;

int main() {
	float sett=0;
	string nome[7]={"lunedì","martedì","mercoledì","giovedì","venerdì","sabato","domenica"};
	float giorni[7]; //dichiaro un vettore di tipo float di dimensione 7
	for(int i=0;i<7;i++){
		cout<<"Inserisci l'incasso del "<<nome[i]<<endl;
		cin>>giorni[i];
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		sett+=giorni[i];
	}
	cout<<"L'incasso settimanale è di €"<<sett<<endl;
	return 0;
}
