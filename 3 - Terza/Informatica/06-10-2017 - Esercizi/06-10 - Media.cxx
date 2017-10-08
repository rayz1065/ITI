#include <iostream>
using namespace std;

int main()
{
	int e,s;
	const int n=3;
	float m;
	
	cout<<"Inserisci la prima età: ";
	cin>>e;
	s=e;
	
	cout<<"Inserisci la seconda età: ";
	cin>>e;
	s+=e;
	
	cout<<"Inserisci la terza età: ";
	cin>>e;
	s+=e;
	
	m=s/n;
	cout<<"\033[32mLa media dei numeri inseriti è "<<m<<".\033[0m"<<endl;
	return 0;
}
