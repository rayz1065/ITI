#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

#define MAXMN 100
bool collegamenti[MAXMN][MAXMN];
bool visitato[MAXMN];

void visita (int v,int n){
    visitato[v]=true;
    for (int i=0;i<n;i++) if (collegamenti[v][i]&&!visitato[i]) visita(i,n);
}

int main(){
    int n,a,start,x,y,visitati=0;
    ifstream fin;
    fin.open("input.txt");
    fin>>n>>a>>start;
    assert (n<=MAXMN);
    for (int i=0;i<a;i++) {
        fin>>x>>y;
        collegamenti[x][y]=true;
        collegamenti[y][x]=true;
    }
    fin.close();
    visita(start,n);
    for (int i=0;i<n;i++) visitati+=visitato[i];
    cout<<visitati<<endl;
    return 0;
}
