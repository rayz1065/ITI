#include <iostream>
#include <fstream>
using namespace std;

#define START 1

int main (){
    int table[100][100],r,c;
    bool start=false;
    char temp;
    ifstream fin;
    fin.open("input.txt");
    fin>>r;
    fin>>c;

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            fin>>temp;
            if (i>0&&temp!='+') table[i][j]=table[i-1][j];
            else table[i][j]=0;
            if (j>0&&temp!='+') table[i][j]+=table[i][j-1];
            //cout<<table[i][j]<<" ";
            table[0][0]=START;
            //cout<<temp<<" ";
        }
        //cout<<endl;
    }
    fin.close();
    cout<<table[r-1][c-1]<<endl;
    return 0;
}
