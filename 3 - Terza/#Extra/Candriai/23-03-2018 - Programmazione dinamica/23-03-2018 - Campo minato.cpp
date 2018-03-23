#include <iostream>
#include <fstream>
using namespace std;

#define START 1
#define MINE -1

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
            switch (temp){
            case 'S':
                table[i][j]=START;
                start=true;
                break;
            case '.':
                if (start&&i>0) {
                     if (temp!='*') table[i][j]=table[i-1][j];
                } else table[i][j]=0;
                if (start&&j>0) {
                     if (temp!='*') table[i][j]+=table[i][j-1];
                }
                break;
            case 'H':
                if (start&&i>0) {
                    if (temp!='*') table[i][j]=table[i-1][j];
                } else table[i][j]=1;
                if (start&&j>0) {
                    if (temp!='*') table[i][j]+=table[i][j-1];
                }
                cout<<table[i][j]<<endl;
                fin.close();
                return 0;
            }
            //cout<<temp<<" ";
            //cout<<table[i][j]<<" ";
        }
        //cout<<endl;
    }
    fin.close();
    cout<<"IMPOSSIBILE"<<endl;
    return 0;
}
