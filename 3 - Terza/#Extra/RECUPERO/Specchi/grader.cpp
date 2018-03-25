#include <stdio.h>
#include <assert.h>

typedef enum {
	SOPRA = 0,
	DESTRA = 1,
	SOTTO = 2,
	SINISTRA = 3
} parete_t;

typedef struct {
	parete_t lato;
	int posizione;
} foro_t;

struct location{
	int riga;
	int colonna;
	parete_t direzione;
};

unsigned int Sr[250000], Sc[250000]; // Specchio riga, Specchio colonna
bool Sd[250000]; // Speccio diagonale
int R, C;

void inizia(int R, int C){
	for (int i=0;i<250000;i++){ // Inizializza gli specchi
		Sr[i]=0;
	}
}

void aggiungi(int r,int c,char diagonale){
	for (int i=0;i<250000;i++){ // Per ogni elemento della lista degli specchi
		if (Sr[i]==0){ // Se è vuoto aggiungilo
			Sr[i]=r+1; 
			Sc[i]=c+1;
			if (diagonale=='/') Sd[i]=0; // /=0
			if (diagonale=='\\') Sd[i]=1; // \=1
			break;
		}
	}
}

foro_t calcola(foro_t ingresso){
	location locazione; // locazione è la posizione attuale del laser
	
	locazione.direzione=ingresso.lato; // Inizializza la direzione e la posizione
	if (ingresso.lato==SOPRA) {
		locazione.riga=0;
		locazione.colonna=ingresso.posizione+1;
	} else if (ingresso.lato==DESTRA) {
		locazione.riga=ingresso.posizione+1;
		locazione.colonna=C+1;
	} else if (ingresso.lato==SOTTO) {
		locazione.riga=R+1;
		locazione.colonna=ingresso.posizione+1;	
	} else {
		locazione.riga=ingresso.posizione+1;
		locazione.colonna=0;
	}
	
	do { // Fino a quando il raggio non esce
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
	if (locazione.riga==0) {
		ingresso.lato=SOPRA;
		ingresso.posizione=locazione.colonna;
	} else if (locazione.riga>R) {
		ingresso.lato=SOTTO;
		ingresso.posizione=locazione.colonna;
	} else if (locazione.colonna==0) {
		ingresso.lato=SINISTRA;
		ingresso.posizione=locazione.riga;
	} else {
		ingresso.lato=DESTRA;
		ingresso.posizione=locazione.riga;
	}
	return ingresso;
	ingresso.posizione--;
}

int main() {
	int N, M, Q, riga, colonna, lato, posizione, i;
	char tipo;

	assert(3 == scanf("%d %d %d", &N, &M, &Q));
	inizia(N, M);

	for (i = 0; i < Q; i++) {
		assert(1 == scanf(" %c", &tipo));
		if (tipo == '?') {
			assert(2 == scanf("%d %d", &lato, &posizione));
			foro_t in = {(parete_t)lato, posizione};
			foro_t res = calcola(in);
			printf("%d %d\n", res.lato, res.posizione);
		} else if (tipo == '/' || tipo == '\\') {
			assert(2 == scanf("%d %d", &riga, &colonna));
			aggiungi(riga, colonna, tipo);
		} else {
			fprintf(stderr, "Tipo di comando errato (validi: / \\ ?): %c (ascii %d)\n", tipo, (int)tipo);
			assert(0);
		}
	}
}
