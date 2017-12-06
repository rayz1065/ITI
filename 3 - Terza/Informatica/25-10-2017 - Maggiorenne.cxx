#include <iostream>
using namespace std;

int main()
{
	int anno;
	string nome;
	cout<<"Immetti il nome e l'età"<<endl;
	cin>>nome;
	cin>>anno;
	if (anno>=18) {
		cout<<nome<<" è maggiorenne"<<endl;
	}	
	else {
		cout<<nome<<" non è maggiorenne"<<endl;
	}
	return 0;
}
