// Dato un array di 30 elementi, contarne i pari, dispari, divisibili per 3 e per 5
#include <iostream>
#include <cstdlib>
using namespace std;

void divisibile (int array[], int &div, int &not_div, int n_elementi, int diviso){
	for(int i=0;i<n_elementi;i++){
		if (array[i]%diviso==0) div++; 
		else not_div++;
	}
}


int main(){
	int array[30], dispari=0, pari=0, cinque=0, tre=0, useless=0;
	srand(time(NULL));
	bool autom;
	
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<30;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero: ";
			cin>>array[i];
		}
	} else {
		for(int i=0;i<30;i++){
			array[i]=rand();
		}		
	}
	
	divisibile(array,pari,dispari,30,2);
	divisibile(array,tre,useless,30,3);
	divisibile(array,cinque,useless,30,5);
	
	cout<<pari<<" numeri sono pari, "<<dispari<<" numeri sono dispari, "<<tre<<" numeri sono divisibili per tre e "<<cinque<<" per cinque."<<endl;
	
	
	return 0;
}
