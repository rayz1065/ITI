// Funzioni ricorsive e puntatori
#include <iostream>
using namespace std;

int for_fattoriale(int n){
	int f=1;
	for(int i=0;i<n;i++){
		f*=(n-i);
	}
	return f;
}

int funzione_fattoriale(int n){
	int k=1;
	if (n==0){
		k=1;
	}
	else {
		k=n*funzione_fattoriale(n-1);
	}
	return k;
}
	
int main()
{
	int n;
	cin>>n;
	cout<<funzione_fattoriale(n)<<endl<<for_fattoriale(n);
	return 0;
}

