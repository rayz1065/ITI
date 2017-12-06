/* Battaglia navale 6x6
* 2 navi da 1
* 2 navi da 2
* 1 navi da 3
* 1 nave da 4
* 
* █ colpito e affondato / nave
* ▓ colpito nave
* ▒ colpito nulla
* ░ non ancora colpito
* 
* righe|colonne|nave-colpito-affondato-occupata-completa
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int coord_convertion(char X){ // Converte X da char a int
	return (int)X-97;
}

int boat_lang(bool Tabella[6][10][5],char x,int Y){ // Calcola la lunghezza della nave dato un punto dove essa si trova
	int X,l=1;
	X=coord_convertion(x);
	
	if (X<6&&Tabella[Y][X+1][0]==1) {
		l++;
		if (X<5&&Tabella[Y][X+2][0]==1) {
			l++;
			if (X<4&&Tabella[Y][X+3][0]==1)	l++;
		}
	}
	if (X>0&&Tabella[Y][X-1][0]==1) {
		l++;
		if (X<1&&Tabella[Y][X-2][0]==1) {
			l++;
			if (X<2&&Tabella[Y][X-3][0]==1)	l++;
		}
	}
	if (Y<10&&Tabella[Y+1][X][0]==1) {
		l++;
		if (Y<9&&Tabella[Y+2][X][0]==1) {
			l++;
			if (Y<8&&Tabella[Y+3][X][0]==1)	l++;
		}
	}
	if (Y>0&&Tabella[Y-1][X][0]==1) {
		l++;
		if (Y>1&&Tabella[Y-2][X][0]==1) {
			l++;
			if (Y>2&&Tabella[Y-3][X][0]==1)	l++;
		}
	}
	return l;
}

void add_boat(bool Tabella[6][10][5],char x,int Y){ // Aggiunge una nave
	int X;
	X=coord_convertion(x);
	Y--;
	
	// Posizionamento nave
	Tabella[Y][X][0]=1;
	Tabella[Y][X][3]=1;
	
	// Diagonali occupate
	if (Y<10&&X<10) Tabella[Y+1][X+1][3]=1;
	if (Y<10&&X>0) Tabella[Y+1][X-1][3]=1;
	if (Y>0&&X>0) Tabella[Y-1][X-1][3]=1;
	if (Y>0&&X<10) Tabella[Y-1][X+1][3]=1;
	
	// Lang direzionale
	if (boat_lang(Tabella,x,Y)>=2){
		if ((X>0&&Tabella[Y][X-1][0]==1)||(X>0&&Tabella[Y][X+1][0]==1)) { // Orizzontale
			Tabella[Y+1][X][3]=1;
			Tabella[Y-1][X][3]=1;
		}
		if ((X>0&&Tabella[Y-1][X][0]==1)||(X>0&&Tabella[Y+1][X][0]==1)) { // Verticale
			Tabella[Y][X+1][3]=1;
			Tabella[Y][X-1][3]=1;
		}

		
	}
	
	// Lang maggiore o uguale di 4
	if (boat_lang(Tabella,x,Y)>=4){
		if (X>0&&Tabella[Y][X-1][0]==0) Tabella[Y][X-1][3]=1;
		if (Y>0&&Tabella[Y-1][X][0]==0) Tabella[Y-1][X][3]=1;
		if (X<6&&Tabella[Y][X+1][0]==0) Tabella[Y][X+1][3]=1;
		if (Y<10&&Tabella[Y+1][X][0]==0) Tabella[Y+1][X][3]=1;
	}
}

bool valid_pos(bool Tabella[6][10][5],char x,int Y){ // 1 se è inseribile
	bool valid=0;
	int X;
	X=coord_convertion(x);
	Y--;
	
	if (Tabella[X][Y][3]==0) valid=1;
	return valid;
}

bool valid_coord(char X,int Y){ // 1 se sono coordinate valide
	bool valid=0;
	if((X=='a'||X=='b'||X=='c'||X=='d'||X=='e'||X=='f'||X=='g'||X=='h'||X=='i'||X=='j')&&(Y<=6&&Y>=1)) valid=1;
	return valid;
}

void print_hit(bool Tabella[6][10][5]){ // Stampa la tabella dei colpi
	cout<<" abcdefghij"<<endl;
	for (int i=0;i<6;i++){
		cout<<i+1;
		for (int j=0;j<10;j++){
			if(Tabella[i][j][1]==0) cout<<"░"; // non ancora colpito
			else if(Tabella[i][j][1]==1&&Tabella[i][j][0]==0) cout<<"▒"; // colpito a vuoto
			else if(Tabella[i][j][1]==1&&Tabella[i][j][2]==0&&Tabella[i][j][0]==1) cout<<"▓"; // colpito nave
			else if(Tabella[i][j][1]==1&&Tabella[i][j][2]==1) cout<<"█"; // colpito e affondato nave
		}
		cout<<endl;
	}
}

void print_ins(bool Tabella[6][10][5]){ // Stampa Immissioni
	cout<<" abcdefghij"<<endl;
	for (int i=0;i<6;i++){
		cout<<i+1;
		for (int j=0;j<10;j++){
			if(Tabella[i][j][3]==0) cout<<"░"; // inseribile
			else if(Tabella[i][j][3]==1&&Tabella[i][j][0]==0) cout<<"▒"; // non inseribile
			else if(Tabella[i][j][0]==1&&Tabella[i][j][4]==0) cout<<"▓"; // nave incompleta
			else if(Tabella[i][j][0]==1&&Tabella[i][j][4]==1) cout<<"█"; // nave competa
		}
		cout<<endl;
	}
}

int main(){
	// DICHIARAZIONI VARIABILI
	bool Griglia[6][10][5];// righe|colonne|nave-colpito-affondato-occupata-completa
	for (int i=0;i<6;i++){
		for (int j=0;j<10;j++){
			for (int k=0;k<5;k++){
				Griglia[i][j][k]=0;
			}
		}
	}
	bool all_boat=0;
	int p=0;
	char X;
	int Y;
	
	// INPUT NAVI
	print_ins(Griglia);
	while (all_boat==0){
		cout<<"Immetti le coordinate della tua "<<p+1<<"^ nave: ";
		cin>>X>>Y;
		if ((valid_coord(X,Y)==1)&&(valid_pos(Griglia,X,Y)==1)){
			add_boat(Griglia,X,Y);
			system("clear");
			print_ins(Griglia);
			p++;
		} else {
			cout<<endl<<"Coordinate non valide"<<endl<<endl;
			system("clear");
		}
	}
	
	// SCELTA CASELLA
	
	// VINCITORE
	print_hit(Griglia);
	
	
	
	
	
	
	return 0;
}
