// Creare un vettore di 10 interi, creare un secondo vettore anch'esso di 10 elementi che contiene gli stessi elementi del primo, ma in ordine inverso
#include <iostream>
#include <cstdlib>
using namespace std;

void inverti (int v1[],int v2[],int n_elementi){
	for(int i=0;i<n_elementi;i++){
		v2[n_elementi-1-i]=v1[i];
	}
}

int main(){
	int array[10],yarra[10];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<10;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero: ";
			cin>>array[i];
		}
	} else {
		for(int i=0;i<10;i++){
			array[i]=rand()%100;
		}		
	}
	inverti(array,yarra,10);
	for(int i=0;i<10;i++){
		cout<<yarra[i]<<' ';
	}
	
	return 0;
}
