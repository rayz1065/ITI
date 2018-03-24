#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int> > G;
bool visti[20000];
int N,A,start,isole;

void visita (int v){
    visti[v]=true;
    for (int i=0;i<G[v].size();i++) {
        int vic=G[v][i];
        if (!visti[vic]) visita(vic);
    }
}

int main(){
    ifstream in;
    in.open("input.txt");
    assert (in);
    in>>N>>A;
    G.resize(N);
    for (int i=0;i<A;i++) {
        int a,b;
        in>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
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
