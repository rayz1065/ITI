#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
using namespace std;

const int maxn=10000;
const int maxm=20000;

vector<bool> G[maxn];
bool visti[maxm];
int N,A,start,isole;

void visita (int v){
    visti[v]=true;
    for (int i=0;i<N;i++) if (G[v][i]&&!visti[i]) visita(i);
}

int main(){
    ifstream in;
    in.open("input.txt");
    assert (in);
    in>>N>>A;
    for (int i=0;i<N;i++) G[i]=vector<bool>(N,false);
    //G=<vector<vector<bool> >(N,vector<bool>(N,false));
    for (int i=0;i<A;i++) {
        int a,b;
        in>>a>>b;
        G[a][b]=true;
        G[b][a]=true;
    }
    in.close();
    for (int i=0;i<N;i++) {
        if (!visti[i]){
            isole++;
            visita(i);
        }
    }
    ofstream out;
    out.open("output.txt");
    assert (out);
    out<<isole-1<<endl;
    out.close();
    return 0;
}
