// Ordinare una lista

#include <iostream>
using namespace std;

void crescente(string principale[],string secondaria[],int n_elementi){ // Descending order
	string c;
	for(int i=0;i<n_elementi;i++) // For each element
		{
			for(int j=i;(j+1)<n_elementi;j++||(principale[i]==principale[j+1]&&secondaria[i]>secondaria[j+1])){ // For each next element
				if (principale[i]>principale[j+1]){ // Swap if array[element]>array[next element]
					c=principale[i];
					principale[i]=principale[j+1];
					principale[j+1]=c;
					c=secondaria[i];
					secondaria[i]=secondaria[j+1];
					secondaria[j+1]=c;
				}
			}
		}
}

void decrescente(string principale[],string secondaria[],int n_elementi){ // Increasing order
	string c;
	for(int i=0;i<n_elementi;i++) // For each element
		{
			for(int j=i;(j+1)<n_elementi;j++) // For each next element
				{
					if (principale[i]<principale[j+1]||(principale[i]==principale[j+1]&&secondaria[i]<secondaria[j+1])) // Swap if array[element]<array[next element]
						{
							c=principale[i];
							principale[i]=principale[j+1];
							principale[j+1]=c;
							c=secondaria[i];
							secondaria[i]=secondaria[j+1];
							secondaria[j+1]=c;
						}
				}
		}
}

int main(){
	string Nome[256],Cognome[256];
	int n_studenti;
	bool n_c,c_d;
	
	cout<<"     - ALFABETICAL SORT -"<<endl;
	cout<<"Inserisci  numero degli studenti: ";
	cin>>n_studenti;
	for(int i=0;i<n_studenti;i++)
		{
			cout<<endl<<"Inserisci  il nome \\n cognome del "<<i+1<<" studente:"<<endl; 
			cin>>Nome[i];
			cin>>Cognome[i];
		}
	cout<<"                                     nome | cognome"<<endl; // Nome o Cognome?
	cout<<"Vuoi ordinare per nome o per cognome? ( 0 | 1 )"<<endl; 
	cin>>n_c;	
	cout<<"                                           crescente | decrescente"<<endl; // Crescente o Decrescente?
	cout<<"Vuoi ordinare in ordine crescente o decrescente? ( 0 | 1 )"<<endl; 
	cin>>c_d;
	
	if(n_c==0){
		if(c_d==0){
			crescente(Nome,Cognome,n_studenti);
		} else {
			decrescente(Nome,Cognome,n_studenti);
		}
		for(int i=0;i<n_studenti;i++){
			cout<<Nome[i]<<" "<<Cognome[i]<<endl;
		}
	} else {
		if(c_d==0){
			crescente(Cognome,Nome,n_studenti);
		} else {
			decrescente(Cognome,Nome,n_studenti);
		}
		for(int i=0;i<n_studenti;i++){
			cout<<Cognome[i]<<" "<<Nome[i]<<endl;
		}
	}

	return 0;
}
