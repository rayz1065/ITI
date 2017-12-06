/*
* Dato un vettore di dimensione 30 di tipo double, creare 2 diminsioni 10 del tipo opportuno e inserire in essi.
* il contenuto seguendo la seguente regola:
* v2[0] = v1[0]+v1[10]+v1[20]
* v2[1] = v1[1]+v1[11]+v1[21]
* ...
*
* v3[]
*
*
*
*
* 0<=v1[n]<=100
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	double v1[30],v2[10],v3[10];
	bool autom=0;
	
	srand(time(NULL));
	cout<<"Vuoi una compilazione automatica? (0|1)"<<endl;
	cin>>autom;
	
	if (autom==0){
		for(int i=0;i<30;i++){
			cout<<endl<<"Immetti il "<<i+1<<"° numero: ";
			cin>>v1[i];
		}
	} else {
		for(int i=0;i<30;i++){
			v1[i]=rand()%101;
		}		
	}
	
	for (int i=0;i<10;i++){
		v2[i]=v1[i]+v1[i+10]+v1[i+20];
		v3[i]=v1[i]*v1[i+10]*v1[i+20];
	}
	
	for(int i=0;i<10;i++){
		cout<<v2[i]<<"\t";
	}
	
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<v3[i]<<"\t";
	}
	return 0;
}

