#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

vector<vector<int> >mappa;
int N;
void attraversa(int i,int j) {
	for (int r=-1;r<2;r++)
		for (int s=-1;s<2;s++) {
			if (i+r<0 || i+r>N-1 || j+s<0 || j+s>N-1);
			else if (mappa[i+r][j+s]==0 || mappa[i+r][j+s]>mappa[i][j]+1) {
				mappa[i+r][j+s]=mappa[i][j]+1;
				attraversa(i+r,j+s);
			}
		}
}
int main() {
	ifstream in;
	in.open("input.txt");
	assert(in);
	in>>N;
	mappa=vector<vector<int> >(N,vector<int>(N,-1));
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++){
			char c;
			in>>c;
			if (c=='*') mappa[i][j]=0;
		}
    in.close();
	mappa[0][0]=1;
	attraversa(0,0);
	ofstream out;
    out.open("output.txt");
    assert(out);
	out << mappa[N-1][N-1];
	out.close();
	return 0;
}
