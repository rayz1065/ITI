// Data una matrice di 3 righe e 3 colonne, calcolare la somma per riga
#include <iostream>
using namespace std;

void SommaMatrice_riga(int somma[], int matrice[][3], int n_righe){
	for(int i=0;i<n_righe;i++){
		for (int j=0;j<3;j++){
			somma[i]+=matrice[i][j];
		}
	}
}

int main(){
	int matrice[3][3], somma[3];
	for(int i=0;i<3;i++){
		somma[i]=0;
		for (int j=0;j<3;j++){
			cout<<"Immetti il "<<j+1<<"° numero della "<<i+1<<"^ riga: ";
			cin>>matrice[i][j];
			cout<<endl;
		}
	}
	SommaMatrice_riga(somma,matrice,3);
	cout<<"La somma di ogni riga è"<<endl;
	for (int i=0;i<3;i++){
		cout<<somma[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
