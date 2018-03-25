// Delugan Kevin - Stanza degli Specchi
enum lato_t{SOPRA=0,DESTRA,SOTTO,SINISTRA};

struct foro_t{
	lato_t lato;
	int posizione;
};

struct location{
	int riga;
	int colonna;
	lato_t direzione;
};

struct specchio{
	int riga;
	int colonna;
	bool direzione;
};


specchio specchi[250000];
int R, C, pos=0, test=0, riga_usata[100000], colonna_usata[100000];

void inizia(int N,int M){
	for (int i=0;i<100000;i++){
		specchi[i].riga=0;
		riga_usata[i]=0;
		colonna_usata[i]=0;
	}
	for (int i=0;i<150000;i++){
		specchi[i+100000].riga=0;
	}
	
	R=N;
	C=M;
}

void aggiungi(int r,int c,char diagonale){
	specchi[pos].riga=r;
	specchi[pos].colonna=c;
	if (diagonale=='/') specchi[pos].direzione=0;
	if (diagonale=='\\') specchi[pos].direzione=1;
	riga_usata[r]++;
	colonna_usata[c]++;
	pos++;
}

foro_t calcola(foro_t ingresso){
	foro_t uscita;
	int vicino;
	bool diagonale;
	location locazione;
	locazione.direzione=ingresso.lato;
	
	switch (locazione.direzione){
	case SOPRA:
		locazione.riga=-1;
		locazione.colonna=ingresso.posizione;
		break;
	case DESTRA:
		locazione.riga=ingresso.posizione;
		locazione.colonna=C;
		break;
	case SOTTO:
		locazione.riga=R;
		locazione.colonna=ingresso.posizione;
	break;		
	case SINISTRA:
		locazione.riga=ingresso.posizione;
		locazione.colonna=-1;
	}
	
	do {
		switch (locazione.direzione){
		case SOPRA:
			vicino=R;
			test=0;
			for (int i=0;i<pos&&test<colonna_usata[locazione.colonna];i++){
				if (specchi[i].colonna==locazione.colonna&&specchi[i].riga<vicino&&specchi[i].riga>locazione.riga){
					vicino=specchi[i].riga;
					diagonale=specchi[i].direzione;
					test++;
				}
			}
			locazione.riga=vicino;
			if (diagonale) locazione.direzione=SINISTRA;
			else locazione.direzione=DESTRA;
		break;
		case DESTRA:
			vicino=-1;
			test=0;
			for (int i=0;i<pos&&test<riga_usata[locazione.riga];i++){
				if (specchi[i].riga==locazione.riga&&specchi[i].colonna>vicino&&specchi[i].colonna<locazione.colonna){
					vicino=specchi[i].colonna;
					diagonale=specchi[i].direzione;
					test++;
				}
			}
			locazione.colonna=vicino;
			if (diagonale) locazione.direzione=SOTTO;
			else locazione.direzione=SOPRA;
		break;
		case SOTTO:
			vicino=-1;
			test=0;
			for (int i=0;i<pos&&test<colonna_usata[locazione.colonna];i++){
				if (specchi[i].colonna==locazione.colonna&&specchi[i].riga>vicino&&specchi[i].riga<locazione.riga){
					vicino=specchi[i].riga;
					diagonale=specchi[i].direzione;
					test++;
				}
			}
			locazione.riga=vicino;
			if (diagonale) locazione.direzione=DESTRA;
			else locazione.direzione=SINISTRA;
		break;
			case SINISTRA:
			vicino=C;
			test=0;
			for (int i=0;i<pos&&test<riga_usata[locazione.riga];i++){
				if (specchi[i].riga==locazione.riga&&specchi[i].colonna<vicino&&specchi[i].colonna>locazione.colonna){
					vicino=specchi[i].colonna;
					diagonale=specchi[i].direzione;
					test++;
				}
			}
			locazione.colonna=vicino;
			if (diagonale) locazione.direzione=SOPRA;
			else locazione.direzione=SOTTO;
		break;
		}
		
	} while (!(locazione.riga==-1||locazione.riga==R||locazione.colonna==-1||locazione.colonna==C));
	
	if (locazione.riga==-1) {
		uscita.lato=SOPRA;
		uscita.posizione=locazione.colonna;
	} else if (locazione.riga==R) {
		uscita.lato=SOTTO;
		uscita.posizione=locazione.colonna;
	} else if (locazione.colonna==-1) {
		uscita.lato=SINISTRA;
		uscita.posizione=locazione.riga;
	} else {
		uscita.lato=DESTRA;
		uscita.posizione=locazione.riga;
	}
	
	return uscita;
}
