// Creare un programma che, dato un vettore d'interi di dimensione 92,
// permetta di invertire gli elementi tramite un'opportuna funzione.

#include <iostream>
#include <cstdlib>
using namespace std;

void inverti(int v1[],int v2[],int n_elementi){ // Inverte v1 in v2
	for(int i=0;i<n_elementi;i++){
		v2[n_elementi-1-i]=v1[i];
	}
}

int main(){
	int vettore[92], erottev[92];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl; // Manuale o automatico?
	cin>>autom;
	
	if (autom==0){ // Manuale
		for(int i=0;i<92;i++){
			cout<<"Immetti il "<<i+1<<"° numero: ";
			cin>>vettore[i];
			cout<<endl;
		}	
	} else { // Automatico
		for(int i=0;i<92;i++){
			vettore[i]=rand()%100;
		}	
	}
	
	inverti(vettore,erottev,92);

	for(int i=0;i<92;i++){
		cout<<erottev[i]<<' ';
	}
	
	
	return 0;
}
