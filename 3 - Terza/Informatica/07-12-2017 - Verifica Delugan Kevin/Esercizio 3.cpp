// Creare un programma che permetta di riempire un vettore di caratteri avente dimensione 45.
// Dopo aver riempito il vettore, il programma deve chiedere all'utente di inserire un carattere,
// controllare tramite un'opportuna funzione se quest'ultimo è presente nel vettore e contare il numero di occorrenze.

#include <iostream>
#include <cstdlib>
using namespace std;

void ContaSe(char v[], int n_elementi, char confronto, int &counter){ // Per ogni elemento di v uguale a confronto, incrementa counter
	for(int i=0;i<n_elementi;i++){
		if(v[i]==confronto){
			counter++;
		}
	}
}

int main(){
	int counter=0;
	char vettore[45], verifica;
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl; // Manuale o automatico?
	cin>>autom;
	
	if (autom==0){ // Manuale
		for(int i=0;i<45;i++){
			cout<<"Immetti il "<<i+1<<"° carattere: ";
			cin>>vettore[i];
			cout<<endl;
		}
	} else { // Automatico
		for(int i=0;i<45;i++){
			vettore[i]=rand()%128;
		}
	}
	
	cout<<"Immetti il carattere di cui vuoi verificare la presenza: "; // Immissione verifica
	cin>>verifica;
	
	ContaSe(vettore,45,verifica,counter);
	cout<<endl;
	
	if(counter==0){ // OutPut se non presenti
		cout<<"Non c'è il carattere \'"<<verifica<<"\' nel vettore immesso.";
	} else if(counter==1){ // OutPut se presente
		cout<<"Nel vettore immesso c'è "<<counter<<" carattere \'"<<verifica<<'\''<<endl;
	} else { // OutPut se presenti
		cout<<"Nel vettore immesso ci sono "<<counter<<" caratteri \'"<<verifica<<'\''<<endl;
	}

	return 0;
}
