// Scrivere un programmache data una matrice quadrata di dimensione 6x6,
// permetta di calcolare la matrice trasposta. La trasposta di una matrice
// è una matrice in cui si scambiano le righe con le colonne.
#include <iostream>
#include <cstdlib>
using namespace std;

void trasposizione(int m1[6][6], int m2[6][6]){ // Funzione di trasposizione
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			m2[j][i]=m1[i][j];
		}
	}
}

int main(){
	int m1[6][6], m2[6][6];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl; // Manuale o automatico?
	cin>>autom;
	cout<<endl;
	
	if (autom==0){ // Manuale
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				cout<<"Immetti il "<<j+1<<"° numero della "<<i+1<<"^ colonna: ";
				cin>>m1[j][i];
				cout<<endl;
			}
			cout<<endl;
		}		
	} else { // Automatico
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				m1[j][i]=rand()%100;
			}
		}		
	}
	
	trasposizione(m1,m2);
	
	cout<<"La matrice immessa è:"<<endl;
	for(int i=0;i<6;i++){ // OutPut matrice
		for(int j=0;j<6;j++){
			cout<<m1[j][i]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<endl<<"La matrice trasposta sarà:"<<endl;
	for(int i=0;i<6;i++){ // OutPut metrice trasposta
		for(int j=0;j<6;j++){
			cout<<m2[j][i]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
