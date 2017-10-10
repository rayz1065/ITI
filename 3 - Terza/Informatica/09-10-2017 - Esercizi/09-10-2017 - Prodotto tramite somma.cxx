#include <iostream>
using namespace std;

int main()
{
	int a,b,s;
	cout<<"\033[32;1mWHILE LOOP:\033[0m\nInserisci il moltiplicando "<<endl;
	cin>>a;
	cout<<"Inserisci il moltiplicatore "<<endl;
	cin>>b;
	s=0;
	while (b>0)
	{
		s+=a;
		b--;
	}
	cout<<"Il prodotto è "<<s<<endl<<endl<<"\033[32;1mFOR LOOP:\033[0m\nInserisci il moltiplicando "<<endl;
	cin>>a;
	cout<<"Inserisci il moltiplicatore "<<endl;
	cin>>b;
	s=0;
	for (int i=b;i>0;i--)
	{
		s+=a;
	}
	cout<<"Il prodotto è "<<s<<endl;
	return 0;
}

