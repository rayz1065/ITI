#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int MAXN=200;
const int MAXM=100;
int N;
bool matrice[MAXM][MAXN];
vector<bool> V;
vector<int> P;

bool uccidono(int inizio,int fine){
    for (int i=0;i<=fine-inizio;i++){
        //if (fine-inizio==5) cout<<inizio<<" "<<fine<<" "<<V[i+inizio]<<"d "<<i<<"\t",
        //    cout<<((inizio!=0&&V[i+inizio]&&(i%2==0)&&(i==0||matrice[i/2-1][inizio]))||(fine!=N-1&&!V[i+inizio]&&(i%2==1)&&(i==fine-inizio||matrice[(fine-inizio-i)/2-1][i+inizio+1])))<<endl;
        if (inizio!=0&&V[i+inizio]&&(i%2==0)&&(i==0||matrice[i/2-1][inizio])) return true;
        if (fine!=N-1&&!V[i+inizio]&&(i%2==1)&&(i==fine-inizio||matrice[(fine-inizio-i)/2-1][i+inizio+1])) return true;
    }
    return false;
}

main(){
    ifstream in;
	in.open("input.txt");
	assert(in);
	in>>N;
	V=vector<bool>(N,0);
	for (int i=0;i<N;i++){
        char c;
        in>>c;
        if (c=='d') V[i]=1;
        //cout<<V[i]<<" ";
	}
	//cout<<endl;
    in.close();

    for(int i=0;i<N;i+=2){
        for(int j=0;j<N-i-1;j++){
            matrice[i/2][j]=uccidono(j,j+i+1);
            //cout<<matrice[i/2][j]<<"\t";
        }
        //cout<<endl;
    }
    for (int i=0;i<N;i+=2){
        if ((i==0||uccidono(0,i-1))&&(i==N-1||uccidono(i+1,N-1))){
            cout<<i<<endl;
            P.push_back(i);
        }
    }

	ofstream out;
    out.open("output.txt");
    assert(out);
	out << P.size()<<endl;
	for (int i=0;i<P.size();i++) out<<P[i]<<" ";
	out<<endl;
	out.close();
	return 0;
}
