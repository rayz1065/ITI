/*
* Si vuole creare una matrice quadrata di dimensione 5. Verificare se all'interno è presente il numero 5
*/

#include <iostream>
#include <cstdlib>
using namespace std;

void conta_se(int matrice[5][5],int n, int &c){
	for(int j=0;j<5;j++){
		for(int i=0;i<5;i++){
			if(matrice[j][i]==n) c++;
		}
	}
}


int main(){
	const int n=5;
	int c=0, matrice[5][5];
	for(int j=0;j<5;j++){
		for(int i=0;i<5;i++){
			array[i]=rand()%77+1;
			cout<<array[i]<<"\t";
		}
		cout<<endl;
	}
	conta_se(matrice,n,c);
	if(c>0) cout<<"Sì"; 
	else cout<<"No";
	return 0;
}
