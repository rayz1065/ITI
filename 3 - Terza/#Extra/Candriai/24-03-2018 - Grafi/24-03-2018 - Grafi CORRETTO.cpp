#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

const int MAXMN=100;
bool M[MAXMN][MAXMN];
bool visti[MAXMN];
int N,A,start,cnt;

void visita (int v){
    visti[v]=true;
    for (int i=0;i<N;i++) if (M[v][i]&&!visti[i]) visita(i);
}

int main(){
    ifstream in;
    in.open("input.txt");
    assert (in);
    in>>N>>A>>start;
    for (int i=0;i<A;i++) {
        int a,b;
        in>>a>>b;
        M[a][b]=true;
        M[b][a]=true;
    }
    in.close();
    visita(start);
    for (int i=0;i<N;i++) cnt+=visti[i];
    cout<<cnt<<endl;
    return 0;
}
