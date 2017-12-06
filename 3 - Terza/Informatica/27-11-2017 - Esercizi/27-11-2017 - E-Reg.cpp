/*
* Crea un progamma in C++ che abbia una struttura dati che permetta di memorizzare per ogni studente, le medie di ogni singola disciplina.
* Tale programma dovrà ritornare per ogni studente la media e il numero di insufficienze.
* Voti randomici tra 3-10
*/

#include <iostream>
#include <cstdlib>
// #include <ctime>
using namespace std;

int main(){
	string nomi[28], materie[11]={"informatica","inglese","italiano","matematica","scienze motorie e sportive","sistemi e reti","telecomunicazioni","storia","tecnolofie e progettazione di sistemi informatici e di telecomunicazioni","tedesco","religione"};
	int voti[11][28], insufficienze[28];
	float medie[28];
	int automatico=0;
	
	srand(time(NULL));
	
	for(int i=0;i<28;i++){
		if(i==0) cout<<"Insirisci il nome del 1° studente (immetti \"automatico\" per un auto-compilazione): ";
		else if(automatico==0) cout<<endl<<"Insirisci il nome del "<<i+1<<"° studente: ";
		if(automatico==0) cin>>nomi[i];
		if(nomi[0]=="automatico") automatico=1;
		if(automatico==1) nomi[i]="Automatico";
	}
	automatico=0;
	for(int i=0;i<28;i++){
		for(int j=0;j<11;j++){
			if(i==0&&j==0) cout<<"Inserisci il voto di "<<materie[j]<<" dello studente "<<nomi[i]<<" (immetti \"0\" per un auto-compilazione): ";
			else if(automatico==0) cout<<endl<<"Inserisci il voto di "<<materie[j]<<" dello studente "<<nomi[i]<<": ";
			if(automatico==0){
				do{
					cin>>voti[j][i];
					if((voti[j][i]<3&&(voti[j][i]!=0&&i!=0&&j!=0))||voti[j][i]>10) cout<<endl<<"Voto inserito non valido, riinserisci il voto di "<<materie[j]<<" dello studente "<<nomi[i]<<": ";
				} while((voti[j][i]<3&&(voti[j][i]!=0&&i!=0&&j!=0))||voti[j][i]>10);
			}
			if(voti[0][0]==0) automatico=1;
			if(automatico==1){
				voti[j][i]=rand()%8+3;
			}
		}
	}
	for(int i=0;i<28;i++){
		medie[i]=0;
		insufficienze[i]=0;
		for(int j=0;j<11;j++){
			medie[i]+=(float)voti[j][i];
			if(voti[j][i]<6) insufficienze[i]++;
		}
		medie[i]/=11;
		
		cout<<"Lo studente "<<nomi[i]<<" ha una media di "<<medie[i]<<" e "<<insufficienze[i]<<" insufficienze."<<endl;
	}
	return 0;
}
