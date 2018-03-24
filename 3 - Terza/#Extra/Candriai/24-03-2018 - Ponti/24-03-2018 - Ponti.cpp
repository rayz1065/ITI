#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
using namespace std;

vector<int> M;
vector<int> visti;
int N,A,start,isole;

void visita (int v){
    visti[v]=true;
    for (int i=0;i<N;i++) if (M[v][i]&&!visti[i]) visita(i);
}

int main(){
    ifstream in;
    in.open("input.txt");
    assert (in);
    in>>N>>A;
    for (int i=0;i<A;i++) {
        int a,b;
        in>>a>>b;
        M[a][b]=true;
        M[b][a]=true;
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
