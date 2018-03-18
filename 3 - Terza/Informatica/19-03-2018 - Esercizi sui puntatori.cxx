#include <iostream>
using namespace std;

void esercizio60(float &prezzo){
	prezzo*=1.03;
}

struct esercizio62{
	int num_ordine;
	int cod_prodotto;
	int quantita;
	float prezzo_unitario;
}

int main(){
	int a=10,b=4;
	int* pa=&a,pb=&b;
	cout<<"Variabile A: Indirizzo="<<&a<<" Valore="<<a<<endl;
	cout<<"Variabile B: Indirizzo="<<&b<<" Valore="<<b<<endl;
	cout<<"Puntatore PA: Indirizzo="<<&pa<<" Valore="<<pa<<endl;
	cout<<"Puntatore PB: Indirizzo="<<&pb<<" Valore="<<pb<<endl;


	float prezzo=10;
	cout<<"Prezzo originale: "<<prezzo<<endl;
	esercizio60(prezzo);
	cout<<"Prezzo incrementato del 3%: "<<prezzo<<endl;


	int array[10];
	for(int i=0;i<10;i++){
		cout<<i+1<<": ";
		cin>>array[i];
	}
	cout<<endl;
	int* puntatore=array;
	for(int i=0;i<10;i++) cout<<i+1<<": "<<*puntatore+i<<endl;


	esercizio62 struttura;
	cout<<"Immetti il numero dell'ordine."<<endl;
	cin>>struttura.num_ordine;
	cout<<"Immetti il codice del prodotto."<<endl;
	cin>>struttura.cod_prodotto;
	cout<<"Immetti la quantità."<<endl;
	cin>>struttura.quantita;
	cout<<"Immetti il prezzo unitario."<<endl;
	cin>>struttura.prezzo_unitario;
	esercizio62* freccia=&struttura;
	cout<<freccia->cod_prodotto<<endl<<"€"<<(freccia->prezzo_unitario)*(freccia->quantita)<<endl;

	return 0;
}