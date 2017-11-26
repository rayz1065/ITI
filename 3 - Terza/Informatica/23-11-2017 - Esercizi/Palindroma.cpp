//Creare un vettore di caratteri di 20 elementi, riempirlo e verificare se la parola inserita è palindroma

#include <iostream>
using namespace std;

int main(){
	char array[20];
	for (int i=0;i<20;i++){
		cout<<"Inserisci il "<<i+1<<"° carattere:"<<endl;
		cin>>array[i];
	}
	for (int i=0;i<10;i++){
		if(array[i]!=array[19-i]){
			cout<<"Non è palindroma."<<endl;
			return 0;
		}
	}
	cout<<"E' palindroma."<<endl;
	return 0;
}