/*Dati gli incassi di ogni mese, si deve calcolare l'incasso annuale, il profitto medio, l'incasso minimo e l'incasso massimo*/
#include <iostream>
using namespace std;

float somma(float lista[], int n_elementi){ //funzione che dato un array e il numero dei suoi elementi, ne calcola la somma
	float addition=0;
	for (int i=0; i<n_elementi; i++){
		addition+=lista[i];
	}
	return addition;
}

float media(float lista[], int n_elementi){  //funzione che dato un array e il numero dei suoi elementi, ne calcola la media matematica
	float middle=somma(lista,n_elementi);
	middle/=n_elementi;
	return middle;
}

float min(float lista[], int n_elementi){ //funzione che dato un array e il numero dei suoi elementi, ne trova l'elemento minore
	float minimo=lista[0];
	for (int i=1; i<n_elementi; i++){
		if (minimo>lista[i]){
			minimo=lista[i];
		}
	}
	return minimo;
}

float max(float lista[], int n_elementi){ //funzione che dato un array e il numero dei suoi elementi, ne trova l'elemento maggiore
	float massimo=lista[0];
	for (int i=1; i<n_elementi; i++){
		if (massimo<lista[i]){
			massimo=lista[i];
		}
	}
	return massimo;
}

int main(){
	const int n_elementi=12;
	float M[12];
	string mese[12]={"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
	for (int i=0; i<n_elementi; i++){
		cout<<"Inserisci incasso del mese di "<<mese[i]<<':'<<endl;
		cin>>M[i];
	}
	cout<<"L'incasso annuale è stato di €"<<somma(M,n_elementi)<<endl;
	cout<<"Il profitto medio è stato di €"<<media(M,n_elementi)<<endl;
	cout<<"L'incasso minimo è stato di €"<<min(M,n_elementi)<<endl;
	cout<<"L'incasso massimo è stato di €"<<max(M,n_elementi)<<endl;
	return 0;
}
