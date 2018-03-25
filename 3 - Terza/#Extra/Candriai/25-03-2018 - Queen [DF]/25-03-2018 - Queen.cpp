#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

const int MAXMN=100;
int sc[MAXMN][MAXMN],M,N,Q,best,n_best;

void print(){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++)
            cout<<sc[i][j];
        cout<<endl;
    }
}

void escludi(int x,int y,int inc){
    for (int i=0;i<M;i++) sc[i][y]+=inc;
    for (int i=0;i<N;i++) {
        sc[x][i]+=inc;
        if((x+i-y>=0)&&(x+i-y<M)) sc[x+i-y][i]+=inc;
        if((x+y-i>=0)&&(x+i-y<M)) sc[x+y-i][i]+=inc;
    }
}

void risolvi(int done, int collocate){
    int rig=done/N,col=done%N;
    if (done==M*N-1) {
        if (best==collocate) n_best++;
        if (best<collocate){
            n_best=1;
            best=collocate;
        }
        return;
    }
    if (sc[rig][done%M]) risolvi(done++,collocate);
    else {
        escludi(rig,col,1);
        risolvi(done+1,collocate+1);
        escludi(rig,col,-1);
        risolvi(done+1,collocate);
    }
}

int main(){
    ifstream in;
    in.open("input.txt");
	assert(in);
	in>>M>>N>>Q;
	for (int i=0;i<Q;i++){
        int x,y;
        in>>x>>y;
        escludi(x,y,1);
	}
    in.close();
    risolvi(0,0);
    cout<<best<<" "<<n_best<<endl;
    return 0;
}
