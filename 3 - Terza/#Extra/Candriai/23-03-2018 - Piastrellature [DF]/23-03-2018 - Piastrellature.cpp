#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#define VUOTO -1
#define MAXMN 100
int* memo;

int casi(int n){
    assert (n>=0);
    if (n<2) return 1;
    if (memo[n]==VUOTO) memo[n]=casi(n-1)+casi(n-2);
    return memo[n];
}

void calcola(int n){
    assert (n>=0);
    if (n==1){
        cout<<"[O]"<<endl;
    } else if (n!=0){
        cout<<"[O]";
        calcola(n-1);
        cout<<"[OOOO]";
        calcola(n-2);
    }

}

int main (){
    int n;
    cin>>n;
    memo=new int[n+1];
    for (int i=0;i<=n;i++) memo[i]=VUOTO;
    cout<<casi(n)<<endl;
    calcola(n);
    return 0;
}
