/*
* Crea un progamma in C++ che abbia una struttura dati che permetta di memorizzare per ogni studente, le medie di ogni singola disciplina.
* Tale programma dovrà ritornare per ogni studente la media e il numero di insufficienze.
* Voti randomici tra 3-10
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
* int contaminori_matrice(float lista[][28], int n_elementi, float riferimento){
* 	int counter[28];
* 	for(int i=0;i<28;i++){
* 		couter[i]=0;
* 		for(int j=0;j<n_elementi;i++){
* 			if(lista[j][i]<riferimento) counter[i]++;
* 		}
* 	}
* 	return counter;
* }
* 
* float media_matrice(float lista[][28], int n_elementi){
* 	float media[28];
* 	for(int i=0;i<28;i++){
* 		media[i]=0;
* 		for(int j=0;j<n_elementi;i++){
* 			media[i]+=lista[j][i];
* 		}
* 		media[i]/=(float)n_elementi;
* 	}
* 	return media;
* }
*/
int main(){
	string nomi[28], materie[11]={"informatica","inglese","italiano","matematica","scienze motorie e sportive","sistemi e reti","telecomunicazioni","storia","tecnolofie e progettazione di sistemi informatici e di telecomunicazioni","tedesco","religione"};
	float voti[11][28], medie[28], insufficienze[28];
	int automatico=0;
	
	srand(time(NULL));
	
	for(int i=0;i<28;i++){
		if(i==0) cout<<"Insirisci il nome del 1° studente (immetti \"automatico\" per un auto-compilazione): ";
		else cout<<endl<<"Insirisci il nome del "<<i+1<<"° studente: ";
		if(automatico==0) cin>>nomi[i];
		if(nomi[0]=="automatico") automatico=1;
		if(automatico==1) nomi[i]=i+1;
	}
	automatico=0;
	for(int i=0;i<28;i++){
		for(int j=0;j<11;j++){
			if(i==0&&j==0) cout<<"Insirisci il voto di "<<materie[j]<<" dello studente "<<nomi[i]<<" (immetti \"-1\" per un auto-compilazione): ";
			else cout<<endl<<"Insirisci il voto di "<<materie[j]<<" dello studente "<<nomi[i]<<": ";
			if(automatico==0){
				do {
					cin>>voti[j][i];
					if(voti[j][i]<4&&voti[j][i]>10) cout<<endl<<"Voto inserito non valido, riinserisci il voto di "<<materie[j]<<" dello studente "<<nomi[i]<<": ";
				} while(voti[j][i]>=4&&voti[j][i]<=10);
			}
			if(voti[0][0]==-1) automatico=1;
			if(automatico==1){
				voti[j][i]=rand()%8+3;
			}
		}
	}
	
	// medie=media_matrice(voti,11);
	// insufficienze=contaminori_matrice(voti,11,6);
	
	for(int i=0;i<28;i++){
		medie[i]=0;
		insufficienze[i]=0;
		for(int j=0;j<11;i++){
			medie[i]+=voti[j][i];
			if(voti[j][i]<6) insufficienze[i]++;
		}
		medie[i]/=11;
		
		cout<<"Lo studente "<<nomi[i]<<" ha una media di "<<medie[i]<<" e "<<insufficienze[i]<<" insufficienze."<<endl;
	}
	return 0;
}
