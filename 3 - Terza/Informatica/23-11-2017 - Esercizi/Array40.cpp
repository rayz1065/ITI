//Creare un vettore di 40 elementi e riempirlo dagli estremi
#include <iostream>
using namespace std;

int main(){
	int array[40];
	for (int i=0;i<20;i++){
		cout<<"Inserisci il "<<i+1<<"° numero:"<<endl;
		cin>>array[i];
		cout<<"Inserisci il "<<40-i<<"° numero:"<<endl;
		cin>>array[39-i];
	}
	cout<<endl<<endl;
	for(int i=0;i<40;i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
	return 0;
}
