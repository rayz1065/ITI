// Chiedere all'utente di inserire 33 numeri, compresi tra 1 e 50, memorizzare tali valori nella
// struttura dati che si ritiene più adatta, verificare quanti tra essi sono numeri primi e
// calcolarne la somma. Mostrare i risultati.

#include <iostream>
#include <cstdlib>
using namespace std;

void SommaSeAppartiene_ContaSeAppartiene(int vettore[], int confronto[], int n_elementi_vettore, int n_elementi_confronto, int &somma, int &counter){ // Somma se appartiene + Conta se appartiene
	for(int i=0;i<n_elementi_vettore;i++){
		for(int j=0;j<n_elementi_confronto;j++){
			if(vettore[i]==confronto[j]){
				somma+=vettore[i];
				counter++;
			}
		}
	}
}

int main(){
	int v[33], primi[16]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}, somma=0, counter=0;
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl; // Manuale o automatico?
	cin>>autom;
	
	if (autom==0){ // Manuale
		cout<<endl<<"I";
		for(int i=0;i<33;i++){
			cout<<"mmetti il "<<i+1<<"° numero: ";
			cin>>v[i];
			if((v[i]<1)||(v[i]>50)){
				cout<<"Il numero inserito non è valido."<<endl<<"Rei";
				i--;
			} else if(i<32) {
				cout<<endl<<"I";
			}
		}
	} else { // Automatico
		for(int i=0;i<33;i++){
			v[i]=rand()%50+1;
		}
	}
	
	cout<<endl;
	
	SommaSeAppartiene_ContaSeAppartiene(v,primi,33,16,somma,counter);
	if(counter==0){ // OutPut se non presenti
		cout<<"Non si cono numeri primi nel vettore immesso.";
	} else { // OutPut se presenti
		cout<<"Ci sono "<<counter<<" numeri primi nel vettore immesso di cui la somma è "<<somma<<endl;
	}
	return 0;
}
