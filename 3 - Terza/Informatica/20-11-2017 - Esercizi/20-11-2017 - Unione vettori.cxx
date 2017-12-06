/* Dati 3 vettori di interi, il primo avente dimensione 30, il secondo dimensione 20 e il terzo dimensione 10,
Creare un quarto vettore con dimensione 60; in nesso bisogna inserire nelle prime 30 posizioni gli elementi del primo
vettore*2, nella secodnaparte gli elementi del secodno vettore*3, nelle posizioni restanti inserire gli elementi del terzo vettore*4 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

void moltiplica(int vettore[], int per, int n_elementi){
	for(int i=0;i<n_elementi;i++){
		vettore[i]*=per;
	}
}

void add_vector(int vettore1[],int vettore2[],int n_elementi,int n_start){
	for(int i=0;i<n_elementi;i++){
		vettore1[i+n_start]=vettore2[i];		
	}	
}

int main(){
	int v1[30], v2[20], v3[10], v4[60];
	bool autom;
	
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<30;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero del primo vettore: ";
			cin>>v1[i];
		}
		for(int i=0;i<20;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero del secondo vettore: ";
			cin>>v1[i];
		}
		for(int i=0;i<10;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero del terzo vettore: ";
			cin>>v1[i];
		}
	} else {
		for(int i=0;i<30;i++){
			v1[i]=rand()%100;
		}
		for(int i=0;i<20;i++){
			v2[i]=rand()%100;
		}		
		for(int i=0;i<10;i++){
			v3[i]=rand()%100;
		}		
	}
	
	moltiplica(v1,2,30);
	moltiplica(v2,3,20);
	moltiplica(v3,4,10);
	
	add_vector(v4,v1,30,0);
	add_vector(v4,v2,20,30);
	add_vector(v4,v3,10,50);
	
	for(int i=0;i<6;i++){
		for(int j=0;j<10;j++){
			cout<<v4[(i*10)+j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
