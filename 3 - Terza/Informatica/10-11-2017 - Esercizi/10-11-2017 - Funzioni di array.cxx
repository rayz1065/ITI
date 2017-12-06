/*Date le temperature del mese di dicembre, calcolare usando 2 funzioni i valore medio e massimo*/
#include <iostream>
using namespace std;



float Media(float numeri[], int d) {
	float media=0;
	for(int i=0;i<d;i++){
		media+=numeri[i];
	}	
	return media/d;
}

float Max(float numeri[],int d) {
	float max=numeri[0];
	for(int i=1;i<d;i++){
		if(numeri[i]>max) max=numeri[i];
	}
	return max;
}

int main() {
	float giorni[31]; //dichiaro un vettore di tipo float di dimensione 31
	for(int i=0;i<31;i++){
		cout<<"Inserisci le temperature del "<<i+1<<"° giorno"<<endl;
		cin>>giorni[i];
	}
	cout<<endl<<"La temperatura media del mese di dicembre è di "<<Media(giorni,31)<<"°C\ne con una temperatura massima di "<<Max(giorni,31)<<"°C"<<endl;
	return 0;
}

