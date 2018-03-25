#include <fstream>
#include <vector>
using namespace std;

struct coord{
    int x;
    int y;
};

vector<vector<bool> >mappa;
vector<coord> possibili;
int M,N,Q,minore;



void filtra(int x,int y){
     mappa[x][y]=0;
     for (int i=0;i<M;i++) mappa[i][y]=0;
     for (int i=0;i<N;i++) mappa[x][i]=0;
     for (int i=0;i<min(M,N);i++) if (x-y>=0) mappa[x-y][i]=0;
     for (int i=x-y;i<min(M,N);i++) if (i>=0) mappa[i][i]=0;

}
/*void escludi(int x, int y) {
	for (int j = 0; j < n; j++) {
		mappa[x][j] = false;
	}
	for (int j = 0; j < m; j++) {
		mappa[j][y] = false;
	}
	for (int j = 0; j < n; j++) {
		int x2 = y-x+j;
		int y2 = x+y-j;
		if (x2 < n && x2 >= 0) {
			mappa[x2][j] = false;
		}
		if (y2 < n && y2 >= 0) {
			mappa[j][y2] = false;
		}
	}
}

void test(){
    do {
    if (m<=n){
        for (int i=m-1;i=0;i--) if (tenta(i)) possibili++;
    }else{
        for (int i=n-1;i>0;i--) if (tenta(i)) possibili++;
    }} while (!trovato);
}
*/
main(){
    /*ifstream in;
	in.open("input.txt");
	assert(in);
	in>>M>>N>>Q;
	mappa=vector<vector<bool> >(M,vector<bool>(N,1));
	if (M<N) minore=M;
	else minore=N;
	possibili=vector<coord>();
	for (int i=0;i<Q;i++){
        int x,y;
        in>>x>>y;
        escludi(x,y);
	}
    in.close();

    /////////////////////
    for(int i=0;i<M;i++)
        for (int j=0;j<N;j++)


	tenta(0);
	ofstream out;
    out.open("output.txt");
    assert(out);
	out << n_queen;
	out.close();*/
	return 0;
}
