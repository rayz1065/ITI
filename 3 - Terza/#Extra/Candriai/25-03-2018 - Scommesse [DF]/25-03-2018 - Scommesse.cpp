#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<bool> V;
vector<int> P;

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
	}
    in.close();

    int p=0,d=0;
    for(int i=0;i<N;i++){

        if (V[i]%2=0&&)


	ofstream out;
    out.open("output.txt");
    assert(out);
	out << P.size()<<endl;
	for (int i=0;i<P.size();i++) out<<P[i]<<" ";
	out<<endl;
	out.close();
	return 0;
}
