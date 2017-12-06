#include <iostream>
using namespace std;

struct foro_t { //dichiarazione struttura dei fori
	 enum parete {SOPRA, SOTTO, DESTRA, SINISTRA};
	 int posizione;
} entrata; //foro di ingresso

void inizia();
void aggiungi();
foro_t calcola();

int main(){
	//DICHIARAZIONE VARIABILI PER PRIMA SERIE DI INSERIMENTI
	int r; //numero di righe
	int c; //numero di colonne
	int Q; //numero di operazioni da compiere
	
	//PRIMA SERIE DI INSERIMENTI
	cin>>r;
	cin>>c;
	cin>>Q;
	cout<<endl;
	
	//DICHIARAZIONE VARIABILI PER IL LOOP
	char operazione; //azione da compiere
	int a; //riga inserita dall'utente
	int b; //colonna inserita dall'utente
	
	//CREAZIONE TABELLA
	char *T;
	T=new char[r][c]; //tabella righe-colonne 
	
	function inizia();
	
	//LOOP INPUT
	for (int i=0; i<Q; i++){
		cin>>operazione;
		cin>>a;
		cin>>b;
		cout<<endl;
		if(operazione=='/'||operazione=='\\') aggiungi(a,b,operazione);
		if(operazione=='?') {
			ingresso.parete=a;
			ingresso.posizione=b;
		}
	}
		
	return 0;
}

void inizia(int R,int C){
	for (int ri=0; ri<R; ri++){
		for (int ci=0; ci<C;ci++){
			
			cout<<
		}
	}
	cout<<
}

void aggiungi(int r, int c, char diagonale){ //aggiunta specchio
	
}

foro_t calcola(foro_t ingresso){
	
}

