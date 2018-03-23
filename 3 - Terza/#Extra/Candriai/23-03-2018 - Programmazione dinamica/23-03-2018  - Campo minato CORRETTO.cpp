#include <cassert>
#include <fstream>
using namespace std;

const int MAXMN=100;
int risp[2][MAXMN+1];

int main (){
    int r,c;
    ifstream fin;
    fin.open("input.txt");
    assert (fin);

    fin>>r>>c;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            char spoon;
            do {
                fin>>spoon;
            } while (!(spoon=='*'||spoon=='+'));
            if (spoon=='+') risp[i%2][j]=0;
            else {
                if (i==1&&j==1) risp[i%2][j]=1;
                else risp[i%2][j]=risp[(i-1)%2][j]+risp[i%2][j-1];
            }
        }
    }
    ofstream fout;
    fout.open("output.txt");
    assert (fout);

    fout<<risp[r%2][c]<<endl;

    fin.close();
    fout.close();
    return 0;
}
