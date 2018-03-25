// Tempo peggiore: 36 millisecondi
#include <bits/stdc++.h> //libreria per tutte le librerie
#define MAXN 16
using namespace std;

int N, M, Q;
int scacchiera[MAXN][MAXN];
int movr[] = {-1, -1, 0, 1, 1, 1, 0, -1}, movc[] = {0, 1, 1, 1, 0, -1, -1, -1}; // 2 array per gestire i movimenti

int am = 0; // ammonto della migliore soluzione
int bestS = 0; // soluzione migliore

bool inRange(int r, int c){ // controlla se la cella è dentro i limiti della scacchiera
    return (r>=0 && c>=0 && r < N && c < M);
}

void escludi(int r, int c, int a){ // posiziona o toglie la queen in posizione r c
    scacchiera[r][c]+= a;
    for(int m = 0; m < 8; m++){
        int newr = r, newc = c;
        while(inRange(newr + movr[m], newc + movc[m])){
            newr+= movr[m], newc+= movc[m];
            scacchiera[newr][newc]+=a;
        }
    }
}

void risolvi(int r, int c, int q){ // funzione risolutiva
    while(r >= N || c >= M || scacchiera[r][c] != 0){ // trova la prima casella libera
        c++;
        if(c >= M){
            c = 0;
            r++;
            if(r >= N){ // se supera la tabella vuol dire che ha trovato una possibile soluzione
                if(q >= bestS){
                    if(q > bestS){ // potrebbe essere una soluzione migliore, in caso la impostiamo
                        am = 0;
                        bestS = q;
                    }
                    am++;
                }
                return;
            }
        }
    }

    int rim = 0; // calcoliamo quante potenziali regine possiamo scegliere sommariamente
    for(int i = r; i < N; i++)
        for(int j = 0; j < M; j++)
            if(scacchiera[i][j] == 0 && (i > r || j > c)){
                j = M; // per evitare di arrivare in fondo alla riga
                rim++;
            }

    if(q + rim + 1 < bestS) return; // se le regine potenziali sono troppo poche torniamo indietro

    escludi(r, c, 1); // mettiamo la regina, computiamo la soluzione e poi la rimuoviamo
    risolvi(r + 1, 0, q + 1);
    escludi(r, c, -1);

    if(q + rim < bestS) return; // se le regine potenziali sono troppo poche togliendo quella presente nella casella torniamo indietro

    risolvi(r, c + 1, q); // computiamo la soluzione se non mettiamo la regina
}

int main(){
    fstream in, out;
    in.open("input.txt", ios::in); // input
    in>>N>>M>>Q; // non ha importanza in che ordine prendiamo righe e colonne finchè le usiamo con lo stesso significato
    for(int q = 0; q < Q; q++){
        int r, c;
        in>>r>>c;
        escludi(r - 1, c - 1, 1);
    }
    in.close();
    risolvi(0, 0, 0); // risolviamo a partire dalla prima casella con 0 regine
    out.open("output.txt", ios::out);
    out<<bestS<<" "<<am; // stampiamo la soluzione migliore e quante ne abbiamo trovate
    out.close();
}
