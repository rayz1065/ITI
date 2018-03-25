#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN=200;
int N;
vector<bool> V;

main(){
    ifstream in;
	in.open("input.txt");
	assert(in);
	in>>N;
	V=vector<bool>(N,0)
	for (int i=0;i<N;i++){
        char c ;
        if (c=='d') V[i]=1
	}
    in.close();



	ofstream out;
    out.open("output.txt");
    assert(out);
	out << n_queen;
	out.close();
	return 0;
}
