//#include <stdlib.h>
//#include <stdio.h>
#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;

const int max_n = 100;
int righe, colonne;
int s[max_n][max_n];
int lower_b = 0;
int n_best = 0;

void input();
void mossa(int, int, int);
void risolvi(int, int);
void visualizza();

int main() {
	input();
	//visualizza();
	risolvi(0, 0);
	ofstream out;
    out.open("output.txt");
    assert(out);
	out << lower_b<<" "<<n_best;
	out.close();
	cout<<"Lower b: "<<lower_b<<endl;
	cout<<"N best: "<<n_best<<endl;
	return 0;
}

void risolvi(int done, int collocate) {
	int r = done/colonne;
	int c = done%colonne;
	//cout<<"Done: "<<done<<"\tRiga: "<<r<<"\tCol.: "<<c<<endl;
	//visualizza();
	if (done == righe * colonne) {
		if (collocate == lower_b) {
			n_best++;
		}
		if (collocate > lower_b) {
			lower_b = collocate;
			n_best = 1;
		}
		return;
	}
	assert(r>=0 && r<righe);
	assert(c>=0 && c<colonne);
	if (s[r][c] > 0) {
		risolvi(done+1, collocate);
	} else {
		mossa(r, c, +1);
		risolvi(done+1, collocate+1);
		mossa(r, c, -1);

		risolvi(done+1, collocate);
	}
}

/*void visualizza() {
	cout<<"Lower b: "<<lower_b<<endl;
	cout<<"N best: "<<n_best<<endl;
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			cout<<"\t"<<s[i][j];
		}
		cout<<endl<<endl;
	}
	system("PAUSE");
}*/

void mossa(int r, int c, int delta) {
	for (int i = 0; i < colonne; i++) { //riga
		s[r][i] += delta;
		if ((r+i-c >= 0) && (r+i-c < righe)) s[r+i-c][i] += delta;
		if ((r+c-i >= 0) && (r+c-i < colonne)) s[r+c-i][i] += delta;
	}
	for (int i = 0; i < righe; i++) { //colonna
		s[i][c] += delta;
	}
}

void input() {
	ifstream fin ("input.txt");
	assert(fin);
	int num;
	fin>>righe>>colonne>>num;
	for (int i = 0; i < num; i++) {
		int r, c;
		fin>>r>>c;
		mossa(r, c, +1);
	}
	fin.close();
}





