#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a,b,c;
	cout<<"Inserisci il tuo primo cateto: ";
	cin>>a;
	cout<<"Inserisci il tuo secondo cateto: ";
	cin>>b;
	c=sqrt(pow(a,2)+pow(b,2));
	cout<<"L'ipotenusa vale "<<c<<'.';
	return 0;
}
