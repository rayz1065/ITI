//Inserito il prezzo di vendita e lo sconto, si calcoli il prezzo scontato
#include <iostream>
using namespace std;
float prezzo_scontato(float prezzo,float sconto){
	float prezzoscontato; //Dichiarazione della variabile prezzoscontato
	prezzoscontato=prezzo*(1-sconto/100); //Prezzo scontato è eqivalente al prezzo moltiplicato per la centesima parte di uno meno lo sconto in %
	return prezzoscontato; //Restituisce il prezzo scontato
}
int main(){
	float prezzo,sconto; //Dichiarazioni delle variabili prezzo (di vendita) e sconto (da applicare al prezzo di vendita)
	cout<<"Inserisca il prezzo di vendita"<<endl; //Consegna per l'inserimento del prezzo di vendita
	cin>>prezzo; //Immissione del prezzo di vendita
	cout<<"Inserisca lo sconto in %"<<endl; //Consegna per l'inserimento del prezzo di vendita
	cin>>sconto; //Immissione dello sconto
	cout<<"Il prezzo scontato sarà di €"<<prezzo_scontato(prezzo,sconto)<<endl; //Calcolo con una funzione esterna del prezzo scontato e restituzione di esso
	return 0;
}
