// Creare un programma che dati 2 vettori v1 e v2 di dimensione 10, contenenti numeri compresi tra
// 3 e 107, ne costruisca un terzo v3 avente dimensioni 20 e contenente tutti gli elementi degli 
// altri vettori. In particolare da 1 a 10 devono esservi gli elementi di v2 in ordine inverso e nelle
// altre posizioni gli elementi di v1. Mostrare v3.

#include <iostream>
#include <cstdlib>
using namespace std;

void inverti(int vettore1[],int vettore2[],int n_elementi){ // Inverte vettore1 in vettore 2
	for(int i=0;i<n_elementi;i++){
		vettore2[n_elementi-1-i]=vettore1[i];
	}
}

void add_vector(int vettore1[],int vettore2[],int n_elementi,int n_start){ // Aggiunge n_elementi di vettore2 a vettore1 partendo da n_start
	for(int i=0;i<n_elementi;i++){
		vettore1[i+n_start]=vettore2[i];		
	}	
}

int main(){
	int v1[10], v2[10], v3[20], iv2[10];
	bool autom;
	srand(time(NULL));
		
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl; // Manuale o automatico?
	cin>>autom;
	
	if (autom==0){ 
		cout<<endl<<"I";
		for(int i=0;i<10;i++){ // Manuale v1
			cout<<"mmetti il "<<i+1<<"° numero del primo vettore: ";
			cin>>v1[i];
			if((v1[i]<3)||(v1[i]>107)){
				cout<<"Il numero inserito non è valido."<<endl<<"Rei";
				i--;
			} else if(i<9) {
				cout<<endl<<"I";
			}
		}
		cout<<endl<<endl<<"I";
		for(int i=0;i<10;i++){ // Manuale v2
			cout<<"mmetti il "<<i+1<<"° numero del secondo vettore: ";
			cin>>v2[i];
			if((v2[i]<3)||(v2[i]>107)){
				cout<<"Il numero inserito non è valido."<<endl<<"Rei";
				i--;
			} else if(i<9) {
				cout<<endl<<"I";
			}
		}
	} else { // Automatico
		for(int i=0;i<10;i++){
			v1[i]=rand()%105+3;
			v2[i]=rand()%105+3;
		}
	}
	
	inverti(v2,iv2,10);
	add_vector(v3,iv2,10,0);
	add_vector(v3,v1,10,10);
	
	for(int i=0;i<10;i++){
		cout<<v3[i]<<"\t";
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<v3[i+10]<<"\t";
	}

	return 0;
}
