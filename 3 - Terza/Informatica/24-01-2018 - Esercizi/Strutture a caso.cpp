#include <iostream>
using namespace std;

struct rettangolo {
	float lunghezza;
	float larghezza;
	string nome;
};

void crescente_la (rettangolo array[],int n_elementi) {
	rettangolo swap;
	for (int i=0;i<n_elementi-1;i++){
		for (int j=i+1;j<n_elementi;j++){
			if (array.larghezza[i]<array.larghezza[j]) {
				swap=array[i];
				array[i]=array[j];
				array[j]=swap;
			}
		}	
	}
}
void crescente_lu (rettangolo array[],int n_elementi) {
	rettangolo swap;
	for (int i=0;i<n_elementi-1;i++){
		for (int j=i+1;j<n_elementi;j++){
			if (array.lunghezza[i]<array.lunghezza[j]) {
				swap=array[i];
				array[i]=array[j];
				array[j]=swap;
			}
		}	
	}
}
void decrescente_la (rettangolo array[],int n_elementi) {
	rettangolo swap;
	for (int i=0;i<n_elementi-1;i++){
		for (int j=i+1;j<n_elementi;j++){
			if (array.larghezza[i]>array.larghezza[j]) {
				swap=array[i];
				array[i]=array[j];
				array[j]=swap;
			}
		}	
	}
}
void decrescente_lu (rettangolo array[],int n_elementi) {
	rettangolo swap;
	for (int i=0;i<n_elementi-1;i++){
		for (int j=i+1;j<n_elementi;j++){
			if (array.lunghezza[i]>array.lunghezza[j]) {
				swap=array[i];
				array[i]=array[j];
				array[j]=swap;
			}
		}	
	}
}

int main() {
	rettangolo array[10];
	bool la_lu=0;
	
	cout<<"Immetti i 10 rettangoli: (nome lunghezza larghezza) ";
	for(int i=0;i<10;i++) {
		cin>>array[i].nome>>array[i].lunghezza>>array[i].larghezza;
	}
	cout<<"Vuoi ordinare per larghezza o lunghezza? (0|1) ";
	cin>>la_lu;
	if (la_lu) {
		cout<<"Vuoi ordinare in ordine crescente o decrescente? (0|1) ";
		cin>>la_lu;
		if (la_lu) decrescente_lu(array,10);
		else crescente_lu(array,10);
	} else {
		cout<<"Vuoi ordinare in ordine crescente o decrescente? (0|1) ";
		cin>>la_lu;
		if (la_lu) decrescente_la(array,10);
		else crescente_la(array,10);
	}	
	
	cout<<endl<<"Elenco rielaborato:"<<endl;
	for(int i=0;i<10;i++) {
		cout<<array[i].nome<<" "<<array[i].lunghezza<<" "<<array[i].larghezza<<endl;
	}
	return 0;
}
