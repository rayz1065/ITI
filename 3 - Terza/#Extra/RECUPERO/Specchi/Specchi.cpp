// Sala degli specchi - Delugan Kevin
#include <iostream>
#include <fstream>

using namespace std;

enum lato{SOPRA=0,DESTRA,SOTTO,SINISTRA};

struct foro_t{
	lato parete;
	int posizione;
};

struct location{
	int riga;
	int colonna;
	lato direzione;
};

unsigned int Sr[250000], Sc[250000]; // Specchio riga, Specchio colonna
bool Sd[250000]; // Speccio diagonale
int R, C; // Righe, Colonne,

void inizia(int R, int C);
void aggiungi(int r,int c,char diagonale);
foro_t calcola(foro_t ingresso);

int main(){
	int Q, b, c; // Numero Righe, Cordinate X, Cordinate Y
	char a; // Operazione
	foro_t ingresso;
	
	ifstream fin; // File input
	fin.open ("input.txt");
	ofstream fout; // File output
	fout.open ("output.txt");
			
	fin>>R>>C>>Q; // Preleva prima riga
	inizia(R,C);
	
	for (int i=0;i<Q;i++) { // Per ogni riga
		fin>>a>>b>>c; // leggi Operazione, Riga e Colonna
		if (a=='?'){ // Se operazione è calcola
			switch (b){ // La Riga rappresenta la parete
				case 0: ingresso.parete=SOPRA; break;
				case 1: ingresso.parete=DESTRA; break;
				case 2: ingresso.parete=SOTTO; break;
				case 3: ingresso.parete=SINISTRA; break;	
			}
			ingresso.posizione=c; // La Colonna rappresenta la posizione
			ingresso=calcola(ingresso); // Quindi esegui il calcolo
			fout<<ingresso.parete<<" "<<ingresso.posizione-1<<endl; // Stampa su file	
		} else if (a=='/'||a=='\\') { // Se l'operazione è aggiungi
			if ((b>=0&&b<R)&&(c>=0&&c<C)){ // Controlla se Riga e Colonna sono validi
				aggiungi(b,c,a); // Quindi esegui l'aggiunta
			} else {
				cout<<"Errore cordinate"<<endl; //E
			}
		} else {
			cout<<"Errore segno"<<endl; //E
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}

void inizia(int R, int C){
	for (int i=0;i<250000;i++){ // Inizializza gli specchi
		Sr[i]=0;
	}
	cout<<"Dimensione impostata a "<<R<<' '<<C<<endl; //D
}

void aggiungi(int r,int c,char diagonale){
	for (int i=0;i<250000;i++){ // Per ogni elemento della lista degli specchi
		if (Sr[i]==0){ // Se è vuoto aggiungilo
			Sr[i]=r+1; 
			Sc[i]=c+1;
			if (diagonale=='/') Sd[i]=0; // /=0
			if (diagonale=='\\') Sd[i]=1; // \=1
			cout<<"Aggiunto specchio "<<diagonale<<" a coordinate "<<r+1<<' '<<c+1<<endl; //D
			break;
		}
	}
}

foro_t calcola(foro_t ingresso){
	cout<<"INGRESSO: "<<ingresso.parete<<' '<<ingresso.posizione+1<<endl; //D
	location locazione; // locazione è la posizione attuale del laser
	
	locazione.direzione=ingresso.parete; // Inizializza la direzione e la posizione
	if (ingresso.parete==SOPRA) {
		locazione.riga=0;
		locazione.colonna=ingresso.posizione+1;
	} else if (ingresso.parete==DESTRA) {
		locazione.riga=ingresso.posizione+1;
		locazione.colonna=C+1;
	} else if (ingresso.parete==SOTTO) {
		locazione.riga=R+1;
		locazione.colonna=ingresso.posizione+1;	
	} else {
		locazione.riga=ingresso.posizione+1;
		locazione.colonna=0;
	}
	
	do { // Fino a quando il raggio non esce
		cout<<locazione.riga<<";"<<locazione.colonna<<endl; //D
		
		if (locazione.direzione==SOPRA) locazione.riga++;
		else if (locazione.direzione==DESTRA) locazione.colonna--;
		else if (locazione.direzione==SOTTO) locazione.riga--;
		else locazione.colonna++;
		if ((locazione.riga>0&&locazione.riga<=R)&&(locazione.colonna>0&&locazione.colonna<=C)) {
			for (int i=0;i<250000;i++){ // Per ogni specchio
				if ((int)Sr[i]==locazione.riga&&(int)Sc[i]==locazione.colonna) { // Cambia la direzione se il raggio si trova in quel punto
					if (locazione.direzione==SOPRA) {
						if (Sd[i]==1) locazione.direzione=SINISTRA;
						else locazione.direzione=DESTRA;
					} else if (locazione.direzione==DESTRA) {
						if (Sd[i]==0) locazione.direzione=SOPRA;
						else locazione.direzione=SOTTO;
					} else if (locazione.direzione==SOTTO) {
						if (Sd[i]==0) locazione.direzione=SINISTRA;
						else locazione.direzione=DESTRA;
					} else {
						if (Sd[i]==1) locazione.direzione=SOPRA;
						else locazione.direzione=SOTTO;
					}
				}
			}
		}
	} while ((locazione.riga>0&&locazione.riga<=R)&&(locazione.colonna>0&&locazione.colonna<=C));
	cout<<"USCITA: "<<locazione.riga<<";"<<locazione.colonna<<endl; //D
	
	if (locazione.riga==0) {
		ingresso.parete=SOPRA;
		ingresso.posizione=locazione.colonna;
	} else if (locazione.riga>R) {
		ingresso.parete=SOTTO;
		ingresso.posizione=locazione.colonna;
	} else if (locazione.colonna==0) {
		ingresso.parete=SINISTRA;
		ingresso.posizione=locazione.riga;
	} else {
		ingresso.parete=DESTRA;
		ingresso.posizione=locazione.riga;
	}
	
	cout<<"OUTPUT: "<<ingresso.parete<<" "<<ingresso.posizione-1<<endl; //D	
	return ingresso;
}
