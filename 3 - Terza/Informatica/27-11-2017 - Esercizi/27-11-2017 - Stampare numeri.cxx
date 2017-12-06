/*
 * Numeri pseudocasuali, ovvero un algoritmo che partendo da un numero ne ritorna un altro.
 * Per fare ciò bisogna utilizzare la libreria cstdlib e la funzione rand()
 * Di default genera un numero casuale fra 0 e 32k.
 * Questo numero non è casuale, ma possiamo notare che si ripetono nel tempo,
 * Per cambiare utilizziamo un seme randomico srand() e come seme inseriamo la funzione
 * time(NULL), ovvero il tempo passato da 01.01.1970
 * Con l'operazione %6 possiamo ridurre il range da 0 a 5
*/

#include <iostream>
#include <cmath>
using namespace std;

void show(int n[],int n_elementi){ // Dato una lista e il numero degli elementi, li stampa in ordine
	for (int j=0;j<5;j++){
		cout<<endl;
		for (int i=0;i<n_elementi;i++){
			if (n[i]==0) {
				if (j==0) cout<<"░░▓▓▓░░";
				if (j==1) cout<<"░▓░░░▓░";
				if (j==2) cout<<"░▓░░░▓░";
				if (j==3) cout<<"░▓░░░▓░";
				if (j==4) cout<<"░░▓▓▓░░";
			}
			if (n[i]==1) {
				if (j==0) cout<<"░░░░▓░░";
				if (j==1) cout<<"░░░▓▓░░";
				if (j==2) cout<<"░░▓░▓░░";
				if (j==3) cout<<"░░░░▓░░";
				if (j==4) cout<<"░░░░▓░░";
			}
			if (n[i]==2) {
				if (j==0) cout<<"░░▓▓▓░░";
				if (j==1) cout<<"░▓░░░▓░";
				if (j==2) cout<<"░░░▓▓░░";
				if (j==3) cout<<"░░▓░░░░";
				if (j==4) cout<<"░▓▓▓▓▓░";
			}
			if (n[i]==3) {
				if (j==0) cout<<"░▓▓▓▓░░";
				if (j==1) cout<<"░░░░░▓░";
				if (j==2) cout<<"░░▓▓▓▓░";
				if (j==3) cout<<"░░░░░▓░";
				if (j==4) cout<<"░▓▓▓▓░░";
			}
			if (n[i]==4) {
				if (j==0) cout<<"░░░░▓░░";
				if (j==1) cout<<"░░░▓▓░░";
				if (j==2) cout<<"░░▓░▓░░";
				if (j==3) cout<<"░▓▓▓▓▓░";
				if (j==4) cout<<"░░░░▓░░";
			}
			if (n[i]==5) {
				if (j==0) cout<<"░▓▓▓▓▓░";
				if (j==1) cout<<"░▓░░░░░";
				if (j==2) cout<<"░▓▓▓▓░░";
				if (j==3) cout<<"░░░░░▓░";
				if (j==4) cout<<"░▓▓▓▓░░";
			}
			if (n[i]==6) {
				if (j==0) cout<<"░░▓▓▓░░";
				if (j==1) cout<<"░▓░░░░░";
				if (j==2) cout<<"░▓▓▓▓░░";
				if (j==3) cout<<"░▓░░░▓░";
				if (j==4) cout<<"░░▓▓▓░░";
			}
			if (n[i]==7) {
				if (j==0) cout<<"░▓▓▓▓▓░";
				if (j==1) cout<<"░░░░░▓░";
				if (j==2) cout<<"░░░░▓░░";
				if (j==3) cout<<"░░░▓░░░";
				if (j==4) cout<<"░░▓░░░░";
			}
			if (n[i]==8) {
				if (j==0) cout<<"░░▓▓▓░░";
				if (j==1) cout<<"░▓░░░▓░";
				if (j==2) cout<<"░░▓▓▓░░";
				if (j==3) cout<<"░▓░░░▓░";
				if (j==4) cout<<"░░▓▓▓░░";
			}
			if (n[i]==9) {
				if (j==0) cout<<"░░▓▓▓░░";
				if (j==1) cout<<"░▓░░░▓░";
				if (j==2) cout<<"░░▓▓▓▓░";
				if (j==3) cout<<"░░░░░▓░";
				if (j==4) cout<<"░░▓▓▓░░";
			}
			if (n[i]==10) {
				if (j==0) cout<<"░░░░░░░";
				if (j==1) cout<<"░░░░░░░";
				if (j==2) cout<<"░▓▓▓▓▓░";
				if (j==3) cout<<"░░░░░░░";
				if (j==4) cout<<"░░░░░░░";
			}
		}
	}
	cout<<endl;
}

void print(int NUMERO){ // Dato un numero lo divide in stringa
	int ARRAY[64],i=0;
	for(int j=0;j<64;j++){
		ARRAY[j]=-1;
	}
	if (NUMERO<0) {
		ARRAY[i]=10;
		NUMERO*=-1;
		i++;
	}
	while (NUMERO!=0) {
		ARRAY[63-i]=NUMERO%10;
		NUMERO/=10;	
		i++;
	}
	show(ARRAY,64);
}

int main(){
	int n;
	cout<<"Inserisci un numero intero: ";
	cin>>n;
	print(n);
	return 0;
}
