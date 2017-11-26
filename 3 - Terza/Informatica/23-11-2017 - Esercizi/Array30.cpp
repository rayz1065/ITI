//Dato un array di 30 elementi inserire prima pari poi dispari
#include <iostream>
using namespace std;

int main(){
	int array[30];
	for(int i=0;i<15;i++){
		cout<<"Inserisci il "<<(i*2)+2<<"° numero:"<<endl;
		cin>>array[(i*2)+1];
	}
	for(int i=0;i<15;i++){
		cout<<"Inserisci il "<<(i*2)+1<<"° numero:"<<endl;
		cin>>array[(i*2)];
	}
	cout<<endl<<endl;
	for(int i=0;i<30;i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
	return 0;
}
