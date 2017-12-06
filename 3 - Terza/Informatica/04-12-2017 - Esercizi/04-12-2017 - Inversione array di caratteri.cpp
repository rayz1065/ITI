// Creare una funzione che dato un vettore mostri il suo inverso, usare tale funzione in un 
#include <iostream>
#include <cstdlib>
using namespace std;

void inverti (char v1[],char v2[],int n_elementi){
	for(int i=0;i<n_elementi;i++){
		v2[n_elementi-1-i]=v1[i];
	}
}

int main(){
	char array[40],yarra[40];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<40;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° carattere: ";
			cin>>array[i];
		}
	} else {
		for(int i=0;i<10;i++){
			array[i]=rand()%256;
		}		
	}
	inverti(array,yarra,40);
	for(int i=0;i<40;i++){
		cout<<yarra[i]<<" ";
	}
	
	return 0;
}
