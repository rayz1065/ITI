/*
* Dato un elenco di numeri, memorizzarli nella struttura dati più idonea.
* Calcolare il maggiore tra essi, la media e mostrare i risultati sapendo
* che i numeri sono 30 e devono essere compresi tra 1 e 77.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

float Media(int numeri[], int d) {
	float media=0;
	for(int i=0;i<d;i++){
		media+=(float)numeri[i];
	}	
	return media/d;
}

int Max(int numeri[],int d) {
	int max=numeri[0];
	for(int i=1;i<d;i++){
		if(numeri[i]>max) max=numeri[i];
	}
	return max;
}

int main(){
	int array[30];
	srand(time(NULL));
	for(int i=0;i<30;i++){
		array[i]=rand()%77+1;
		cout<<array[i]<<"\t";
	}
	cout<<"Il numero maggiore è "<<Max(array,30)<<" e la media è "<<Media(array,30)<<endl;
	return 0;
}
