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
#include <ctime>
#include <cstdlib>

using namespace std;


void show(int n[],int n_elementi){
	for (int j=0;j<5;j++){
		cout<<endl;
		for (int i=0;i<n_elementi;i++){
			if (n[i]==1) {
				if (j==0) cout<<"░░░░▓░░    ";
				if (j==1) cout<<"░░░▓▓░░    ";
				if (j==2) cout<<"░░▓░▓░░    ";
				if (j==3) cout<<"░░░░▓░░    ";
				if (j==4) cout<<"░░░░▓░░    ";
			}
			if (n[i]==2) {
				if (j==0) cout<<"░░▓▓▓░░    ";
				if (j==1) cout<<"░▓░░░▓░    ";
				if (j==2) cout<<"░░░▓▓░░    ";
				if (j==3) cout<<"░░▓░░░░    ";
				if (j==4) cout<<"░▓▓▓▓▓░    ";
			}
			if (n[i]==3) {
				if (j==0) cout<<"░▓▓▓▓░░    ";
				if (j==1) cout<<"░░░░░▓░    ";
				if (j==2) cout<<"░░▓▓▓▓░    ";
				if (j==3) cout<<"░░░░░▓░    ";
				if (j==4) cout<<"░▓▓▓▓░░    ";
			}
			if (n[i]==4) {
				if (j==0) cout<<"░░░░▓░░    ";
				if (j==1) cout<<"░░░▓▓░░    ";
				if (j==2) cout<<"░░▓░▓░░    ";
				if (j==3) cout<<"░▓▓▓▓▓░    ";
				if (j==4) cout<<"░░░░▓░░    ";
			}
			if (n[i]==5) {
				if (j==0) cout<<"░▓▓▓▓▓░    ";
				if (j==1) cout<<"░▓░░░░░    ";
				if (j==2) cout<<"░▓▓▓▓░░    ";
				if (j==3) cout<<"░░░░░▓░    ";
				if (j==4) cout<<"░▓▓▓▓░░    ";
			}
			if (n[i]==6) {
				if (j==0) cout<<"░░▓▓▓░░    ";
				if (j==1) cout<<"░▓░░░░░    ";
				if (j==2) cout<<"░▓▓▓▓░░    ";
				if (j==3) cout<<"░▓░░░▓░    ";
				if (j==4) cout<<"░░▓▓▓░░    ";
			}
		}
	}
	cout<<endl;
}

float somma(int lista[], int n_elementi){ //funzione che dato un array e il numero dei suoi elementi, ne calcola la somma
	int addition=0;
	for (int i=0; i<n_elementi; i++){
		addition+=lista[i];
	}
	return addition;
}

int main(){
	string a,nome1,nome2;
	int num1[2],num2[2],somma1,somma2;
	srand(time(NULL));
	
	// Immissione nomi
	cout<<"Giocatore numero 1, inserisci il tuo nickname;  "<<endl;
	cin>>nome1;
	cout<<endl<<"Giocatore numero 2, inserisci il tuo nickname;  "<<endl;
	cin>>nome2;
	
	// Giocatore 1
	cout<<endl<<nome1<<", premi un tasto per tirare i dadi;  "<<endl;
	cin>>a;
	num1[0]=(rand()%6)+1;
	num1[1]=(((rand()%6)*rand())%6)+1;
	show(num1,2);
	
	// Giocatore 2
	cout<<endl<<nome2<<", premi un tasto per tirare i dadi;  "<<endl;
	cin>>a;
	num2[0]=(rand()%6)+1;
	num2[1]=((rand()/83)%6)+1;
	show(num2,2);
	
	// Vincitore
	somma1=somma(num1,2);
	somma2=somma(num2,2);
	
	if(somma1>somma2) cout<<endl<<nome1<<" ha vinto.  "<<endl;
	else if(somma1<somma2) cout<<endl<<nome2<<" ha vinto.  "<<endl;
	else cout<<endl<<nome1<<" e   "<<nome2<<" hanno pareggiato.  "<<endl;

	return 0;
}
