// Creare un vettore di 10 interi e trasmite una funzione calcolare la somma dei primi e ultimi 5 elementi e mostrarne il risultato
#include <iostream>
#include <cstdlib>
using namespace std;

int somma_par(int array[],int n_elementi,int n_start){
	int somma=0;
	for (int i=0;i<n_elementi;i++){
		somma+=array[i+n_start];
	}
	return somma;
}

int main(){
	int array[10];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<10;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero: ";
			cin>>array[i];
		}
	} else {
		for(int i=0;i<10;i++){
			array[i]=rand()%100;
		}		
	}
	cout<<"La somma dei primi 5 elementi è "<<somma_par(array,5,0)<<" e quella degli ultimi 5 è "<<somma_par(array,5,5)<<endl;
	return 0;
}
