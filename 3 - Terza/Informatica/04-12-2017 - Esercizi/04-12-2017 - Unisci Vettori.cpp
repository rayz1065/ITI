// Dato un vettore di 10 caratteri e uno di 15, inserirli in un terzo di 25.
#include <iostream>
#include <cstdlib>
using namespace std;

void unisci(char v1[],char v2[],char v3[],int n1,int n2){
	for(int i=0;i<n1;i++){
		v3[i]=v1[i];
	}
	for(int i=0;i<n2;i++){
		v3[i]=v3[i+n1];
	}
}

int main(){
	char v1[10], v2[15], v3[25];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<10;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero del primo vettore: ";
			cin>>v1[i];
		}
		for(int i=0;i<15;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero del secondo vettore: ";
			cin>>v1[i];
		}
	} else {
		for(int i=0;i<10;i++){
			v1[i]=rand()%256;
		}
		for(int i=0;i<15;i++){
			v2[i]=rand()%256;
		}
	}
	cout<<endl;
	unisci(v1,v2,v3,10,15);
	
	for(int i=0;i<25;i++){
		cout<<v3[i]<<"\t";
	}
	return 0;
}
