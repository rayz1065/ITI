#include <fstream>
using namespace std;

void cambiariga(bool table[][100],int n_riga, int c){
    for(int i=0;i<c;i++){
        !table[n_riga][i];
    }
}

void cambiacolonna(bool table[][100],int n_colonna, int r){
    for(int i=0;i<r;i++){
        !table[i][n_colonna];
    }
}

int main(){
    bool table[100][100];
    int r,c,temp;
    ifstream fin;
    fin.open("input.txt");
    fin>>r;
    fin>>c;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            fin>>table[i][j];
        }
    }
    fin.close();
    ofstream fout;
    fout.open("output.txt");
    for (int i=0;i<r;i++){
        if (table[i][0]){
            cambiariga(table,i,c);
            fout<<"1 ";
        } else {
            fout<<"0 ";
        }
    }
    fout<<endl;
    for (int i=0;i<c;i++){
        if (table[0][i]){
            cambiacolonna(table,i,r);
            fout<<"1 ";
        } else {
            fout<<"0 ";
        }
    }
    for (int i=1;i<r;i++){
        for (int j=1;j<c;j++){
            if (table[i][c]) {
                fout<<endl<<"IMPOSSIBILE";
                return 0;
            }
        }
    }
    return 0;
}
